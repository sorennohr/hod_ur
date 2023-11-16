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

  pinMode(RESET_AND_START_BUTTON_LED_PIN, OUTPUT);

  // setup serial output  
  Serial.begin(9600);

  Serial.println(F("Setup complete"));

}

void doReset() {
  Serial.println(F("Starting reset to start position"));
  controllerState = CONTROLLER_PROGRAM_STATE_RESETTING;

  clockArmMotor.setMaxSpeed(200);
  clockArmMotor.setAcceleration(200);
  clockArmMotor.move(REVERSE_DIRECTION*ONE_FULL_ROUND);
}

void doReady() {
  Serial.println(F("Ready to start sequence"));
  digitalWrite(RESET_AND_START_BUTTON_LED_PIN, HIGH);
  controllerState = CONTROLLER_PROGRAM_STATE_READY;
  clockArmMotor.stop();
  clockArmMotor.setMaxSpeed(0);
  clockArmMotor.setAcceleration(0);
  clockArmMotor.move(0);
}

void doStartSequence() {
  Serial.println(F("Sequence starting"));
  digitalWrite(RESET_AND_START_BUTTON_LED_PIN, LOW);
  controllerState = CONTROLLER_PROGRAM_STATE_RUNNING;
  currentSequenceTaskIdx = 0;
  currentTaskStep = TASK_STATE_INIT;
  startNextTask();
}

void doEndSequence() {
  Serial.println(F("Sequence completed"));
  controllerState = CONTROLLER_PROGRAM_STATE_DONE;
}

bool isCurrentlyRunningTaskDone() {
    struct task currentlyRunningTask = sequence[currentSequenceTaskIdx];

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
      if (currentlyRunningTask.destination2 != 0) {
        currentTaskStep = TASK_STATE_DEST2;
      } else if (currentlyRunningTask.postDelayMillis > 0) {
        currentTaskStep = TASK_STATE_POST_WAIT;
      } else {
        repetitionDone = true;
      }
    }

    if (currentTaskStep == TASK_STATE_DEST2) {
      if (currentlyRunningTask.postDelayMillis > 0) {
        currentTaskStep = TASK_STATE_POST_WAIT;
      } else {
        repetitionDone = true;
      }
    }

    if (repetitionDone) {
        if (--currentlyRunningTask.repeat > 0) {
          // TODO start igen1

          return false;
        }
    }

    return true;
}

void startTaskOrRepetitionOfTask() {
  if (currentSequenceTaskIdx < sequenceLength) {
    struct task nextTask = sequence[currentSequenceTaskIdx];

    //log_printf("Task [%i] starting\n", nextTask.type);

    switch (nextTask.type) {
      case TASK_TYPE_DELAY:
      {
        delayTime.setdelay(nextTask.delayMillis);
        delayTime.start();
        break;
      }

      case TASK_TYPE_ACCELERATION:
      case TASK_TYPE_CONSTANT_SPEED:
      {
        clockArmMotor.stop();
        clockArmMotor.setMaxSpeed(nextTask.maxSpeed);
        clockArmMotor.setAcceleration(nextTask.acceleration);
        clockArmMotor.move(REVERSE_DIRECTION*nextTask.destination);
        break;
      }
    }
  }
}

void doRunSequence() {
  bool currentlyRunningTaskIsComplete = isCurrentlyRunningTaskDone();

  if (currentSequenceTaskIdx >= sequenceLength && currentlyRunningTaskIsComplete) {
    doEndSequence();
  } else {
    if (currentlyRunningTaskIsComplete) { 
      struct task completedTask = sequence[currentSequenceTaskIdx++];
      //log_printf("Task [%i] completed\n", completedTask.type);
      startNextTask();
    }
  }
}

void loop() {
  
  resetAndStartButton.loop();
  startPositionIndicator.loop();

  bool resetAndStartButtonActivated = resetAndStartButton.isPressed();
  bool onStartPosition = startPositionIndicator.isPressed();

  //log_printf("state: %i, reset: %i, startPos: %i\n", controllerState, resetAndStartButtonActivated, startPositionIndicatorActivated);

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
