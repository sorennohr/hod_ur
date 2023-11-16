#include <AccelStepper.h>
#include <ezButton.h>
#include <NoDelay.h>

#include "definitions.h"
#include "sequence.h"

AccelStepper clockArmMotor(AccelStepper::DRIVER, MOTOR_PIN_1, MOTOR_PIN_2);
ezButton resetAndStartButton(RESET_AND_START_BUTTON_PIN);
ezButton startPositionIndicator(START_POS_INDICATOR_PIN);
noDelay delayTime(0);

int controllerState = CONTROLLER_PROGRAM_STATE_DONE;
int currentSequenceTaskIdx = 0;
int currentTaskStep = TASK_STATE_INIT;


void setup() {

  // setup start/reset button 
  resetAndStartButton.setDebounceTime(50);

  // setup start position indicator
  startPositionIndicator.setDebounceTime(50);

  // setup start/reset button LED pin
  pinMode(RESET_AND_START_BUTTON_LED_PIN, OUTPUT);

  // setup serial output  
  Serial.begin(9600);

  Serial.println(F("Setup complete"));
}

void setupNewMotorTask(short speed, short acceleration, short destination) {
  clockArmMotor.stop();
  clockArmMotor.setMaxSpeed(speed);
  clockArmMotor.setAcceleration(acceleration);
  clockArmMotor.move(REVERSE_DIRECTION*destination);
}

void setupNewDelayTask(short delayMillis) {
  delayTime.setdelay(delayMillis);
  delayTime.start();
}

void doReset() {
  Serial.println(F("Starting reset to start position"));
  controllerState = CONTROLLER_PROGRAM_STATE_RESETTING;

  setupNewMotorTask(200, 400, ONE_FULL_ROUND*2);
}

void doReady() {
  Serial.println(F("Ready to start sequence"));
  digitalWrite(RESET_AND_START_BUTTON_LED_PIN, HIGH);
  controllerState = CONTROLLER_PROGRAM_STATE_READY;

  setupNewMotorTask(0, 0, 0);
}

void doStartSequence() {
  Serial.println(F("Sequence starting"));
  digitalWrite(RESET_AND_START_BUTTON_LED_PIN, LOW);
  controllerState = CONTROLLER_PROGRAM_STATE_RUNNING;
  currentSequenceTaskIdx = 0;
  currentTaskStep = TASK_STATE_INIT;

  startTaskOrRepetitionOfTask();
}

void doEndSequence() {
  Serial.println(F("Sequence completed"));
  controllerState = CONTROLLER_PROGRAM_STATE_DONE;
}

bool isCurrentlyRunningTaskDone() {
    struct task *currentlyRunningTask = &sequence[currentSequenceTaskIdx];

    /*Serial.print("Is done,  task: ");
    Serial.print(currentSequenceTaskIdx);
    Serial.print(", repeat: ");
    Serial.print(currentlyRunningTask->repeat);
    Serial.print(", step: ");
    Serial.println(currentTaskStep);*/

    boolean stepDone = false;
    boolean repetitionDone = false;
    switch (currentTaskStep) {
      case TASK_STATE_POST_WAIT:
      {
        stepDone = delayTime.update();
        break;
      }

      case TASK_STATE_DEST1:
      case TASK_STATE_DEST2:
      {
        stepDone = clockArmMotor.distanceToGo() == 0;
        break;
      }
    }

    if (!stepDone) {
      return false;
    }

    if (currentTaskStep == TASK_STATE_DEST1) {
      if (currentlyRunningTask->destination2 != 0) {
        currentTaskStep = TASK_STATE_DEST2;
      } else if (currentlyRunningTask->postDelayMillis > 0) {
        currentTaskStep = TASK_STATE_POST_WAIT;
      } else {
        repetitionDone = true;
      }
    } else if (currentTaskStep == TASK_STATE_DEST2) {
      if (currentlyRunningTask->postDelayMillis > 0) {
        currentTaskStep = TASK_STATE_POST_WAIT;
      } else {
        repetitionDone = true;
      }
    } else if (currentTaskStep == TASK_STATE_POST_WAIT) {
      repetitionDone = true;
    }

    if (repetitionDone) {
        if (--currentlyRunningTask->repeat > 0) {
          startTaskOrRepetitionOfTask();
          return false;
        } else {
          return true;
        }
    }

    return false;
}

void startTaskOrRepetitionOfTask() {
  if (currentSequenceTaskIdx < sequenceLength) {
    struct task taskToStartOrRepeat = sequence[currentSequenceTaskIdx];

    Serial.print(F("Starting task/repetition: "));
    Serial.print(currentSequenceTaskIdx);
    Serial.print(F(" / "));
    Serial.println(taskToStartOrRepeat.repeat);

    if (taskToStartOrRepeat.destination1 != 0) {
      setupNewMotorTask(taskToStartOrRepeat.speed, taskToStartOrRepeat.acceleration, taskToStartOrRepeat.destination1);
      currentTaskStep = TASK_STATE_DEST1;
    } else if (taskToStartOrRepeat.destination2 != 0) {
      setupNewMotorTask(taskToStartOrRepeat.speed, taskToStartOrRepeat.acceleration, taskToStartOrRepeat.destination2);
      currentTaskStep = TASK_STATE_DEST2;
    } else if (taskToStartOrRepeat.postDelayMillis > 0) {
      setupNewDelayTask(taskToStartOrRepeat.postDelayMillis);
      currentTaskStep = TASK_STATE_POST_WAIT;
    } else {
      Serial.println(F("Error - got empty task, "));
    }
  }
}

void doRunSequence() {
  bool currentlyRunningTaskIsComplete = isCurrentlyRunningTaskDone();

  if (currentSequenceTaskIdx >= sequenceLength && currentlyRunningTaskIsComplete) {
    doEndSequence();
  } else {
    if (currentlyRunningTaskIsComplete) { 
      /*Serial.print(F("Task completed: "));
      Serial.println(currentSequenceTaskIdx++);*/
      startTaskOrRepetitionOfTask();
    }
  }
}

void loop() {
  
  resetAndStartButton.loop();
  startPositionIndicator.loop();

  bool resetAndStartButtonActivated = resetAndStartButton.isPressed();
  bool onStartPosition = startPositionIndicator.isPressed();

  switch(controllerState)
  {
    case CONTROLLER_PROGRAM_STATE_DONE:
    {
      if (resetAndStartButtonActivated) {
        doReset();
      }

      break;
    }

    case CONTROLLER_PROGRAM_STATE_READY:
    {
      if (resetAndStartButtonActivated) {
        doStartSequence();
      }

      break;
    }

    case CONTROLLER_PROGRAM_STATE_RESETTING:
    {
      clockArmMotor.run();

      if (onStartPosition) {
        doReady();
      }

      break;
    }

    case CONTROLLER_PROGRAM_STATE_RUNNING:
    {
      clockArmMotor.run();

      if (resetAndStartButtonActivated) {
        doEndSequence();
      } else {
        doRunSequence();
      }

      break;
    }
  }
}
