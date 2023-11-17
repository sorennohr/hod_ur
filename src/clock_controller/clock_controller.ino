#include <AccelStepper.h>
#include <ezButton.h>
#include <NoDelay.h>

#include "definitions.h"
#include "sequence.h"

// #define LOG

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

#ifdef LOG
  // setup serial output  
  Serial.begin(9600);
  Serial.println(F("Setup complete"));
#endif
}

void inline setupNewMotorTask(short speed, short acceleration, short destination) {
  clockArmMotor.stop();
  clockArmMotor.setMaxSpeed(speed);
  clockArmMotor.setAcceleration(acceleration);
  clockArmMotor.move(REVERSE_DIRECTION*destination);
}

void inline setupNewDelayTask(short delayMillis) {
  delayTime.setdelay(delayMillis);
  delayTime.start();
}

void doReset() {
#ifdef LOG
  Serial.println(F("Starting reset to start position"));
#endif

  controllerState = CONTROLLER_PROGRAM_STATE_RESETTING;
  setupNewMotorTask(200, 400, ONE_FULL_ROUND*2);
}

void doReady() {
#ifdef LOG
  Serial.println(F("Ready to start sequence"));
#endif
  
  digitalWrite(RESET_AND_START_BUTTON_LED_PIN, HIGH);
  controllerState = CONTROLLER_PROGRAM_STATE_READY;
  setupNewMotorTask(0, 0, 0);
}

void doStartSequence() {
#ifdef LOG
  Serial.println(F("Sequence starting"));
#endif

  digitalWrite(RESET_AND_START_BUTTON_LED_PIN, LOW);
  controllerState = CONTROLLER_PROGRAM_STATE_RUNNING;
  currentSequenceTaskIdx = 0;
  currentTaskStep = TASK_STATE_INIT;

  startTaskOrRepetitionOfTask();
}

void doEndSequence() {
#ifdef LOG
  Serial.println(F("Sequence completed"));
#endif

  controllerState = CONTROLLER_PROGRAM_STATE_DONE;
}

bool isCurrentlyRunningTaskDone() {
    struct task *currentlyRunningTask = &sequence[currentSequenceTaskIdx];

#ifdef LOG
    Serial.print("Is done,  task: ");
    Serial.print(currentSequenceTaskIdx);
    Serial.print(", repeat: ");
    Serial.print(currentlyRunningTask->repeat);
    Serial.print(", step: ");
    Serial.println(currentTaskStep);
#endif

    boolean repetitionDone = false;
    switch (currentTaskStep) {
      case TASK_STATE_POST_WAIT:
      {
        if (!delayTime.update()) {
          return false;
        }

        repetitionDone = true;
        break;
      }

      case TASK_STATE_DEST1:
      case TASK_STATE_DEST2:
      {
        if (!clockArmMotor.distanceToGo() == 0) {
          return false;
        }

        if (currentTaskStep == TASK_STATE_DEST1) {
          if (currentlyRunningTask->destination2 != 0) {
            currentTaskStep = TASK_STATE_DEST2;
            setupNewMotorTask(currentlyRunningTask->speed, currentlyRunningTask->acceleration, currentlyRunningTask->destination2);
          } else if (currentlyRunningTask->postDelayMillis > 0) {
            currentTaskStep = TASK_STATE_POST_WAIT;
            setupNewDelayTask(currentlyRunningTask->postDelayMillis);
          } else {
            repetitionDone = true;
          }
        } else if (currentTaskStep == TASK_STATE_DEST2) {
          if (currentlyRunningTask->postDelayMillis > 0) {
            currentTaskStep = TASK_STATE_POST_WAIT;
            setupNewDelayTask(currentlyRunningTask->postDelayMillis);
          } else {
            repetitionDone = true;
          }
        }
        break;
      }
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
  struct task *taskToStartOrRepeat = &sequence[currentSequenceTaskIdx];

#ifdef LOG
  Serial.print(F("Starting task/repetition: "));
  Serial.print(currentSequenceTaskIdx);
  Serial.print(F(" / "));
  Serial.println(taskToStartOrRepeat->repeat);
#endif

  if (taskToStartOrRepeat->destination1 != 0) {
    setupNewMotorTask(taskToStartOrRepeat->speed, taskToStartOrRepeat->acceleration, taskToStartOrRepeat->destination1);
    currentTaskStep = TASK_STATE_DEST1;
  } else if (taskToStartOrRepeat->destination2 != 0) {
    setupNewMotorTask(taskToStartOrRepeat->speed, taskToStartOrRepeat->acceleration, taskToStartOrRepeat->destination2);
    currentTaskStep = TASK_STATE_DEST2;
  } else if (taskToStartOrRepeat->postDelayMillis > 0) {
    setupNewDelayTask(taskToStartOrRepeat->postDelayMillis);
    currentTaskStep = TASK_STATE_POST_WAIT;
  } else {
#ifdef LOG
    Serial.println(F("Error - got empty task"));
#endif
  }
}

void doRunSequence() {
  bool currentlyRunningTaskIsComplete = isCurrentlyRunningTaskDone();

  if (currentSequenceTaskIdx >= sequenceLength && currentlyRunningTaskIsComplete) {
    doEndSequence();
  } else {
    if (currentlyRunningTaskIsComplete) { 
      /*Serial.print(F("Task completed: "));
      Serial.println(currentSequenceTaskIdx);*/
      currentSequenceTaskIdx++;
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