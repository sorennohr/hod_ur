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
  clockArmMotor.move(REVERSE_DIRECTION * ONE_FULL_ROUND);
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

/*void doStartSequence() {
  Serial.println(F("Sequence starting"));
  digitalWrite(RESET_AND_START_BUTTON_LED_PIN, LOW);
  controllerState = CONTROLLER_PROGRAM_STATE_RUNNING;
  currentSequenceTaskIdx = 0;
  startNextTask();
}*/

/*void doEndSequence() {
  Serial.println(F("Sequence completed"));
  controllerState = CONTROLLER_PROGRAM_STATE_DONE;
}*/

/*bool isCurrentlyRunningTaskDone() {
  struct task currentlyRunningTask = sequence[currentSequenceTaskIdx];

  bool currentStepInTaskDone = false;

  if (currentlyRunningTask.state == TASK_STATE_RUNNING_MOTOR) {
    if (clockArmMotor.distanceToGo() == 0) {
      delayTime.setdelay(currentlyRunningTask.postDelayMillis);
      delayTime.start();
      currentlyRunningTask.state = TASK_STATE_POST_WAIT;
    }
  } else if (currentlyRunningTask.state == TASK_STATE_POST_WAIT) {
    currentStepInTaskDone = delayTime.update();
  } else {
    Serial.println(F("Error in task state!!!"));
  }

  if (currentStepInTaskDone) {
    if (currentlyRunningTask.repeat > 0) {
      --currentlyRunningTask.repeat;
      startNextTask();
    } else {
      return true;
    }
  }

  return false;
}*/

/*void startNextTask() {
  if (currentSequenceTaskIdx < sequenceLength) {
    struct task nextTask = sequence[currentSequenceTaskIdx];
    struct taskStep nextTaskStep = nextTask.taskSteps[nextTask.currentStep];

    if (nextTaskStep.destination != 0) {
      clockArmMotor.stop();
      clockArmMotor.setMaxSpeed(nextTask.speed);
      clockArmMotor.setAcceleration(nextTask.acceleration);
      clockArmMotor.move(REVERSE_DIRECTION * nextTask.destination);
      nextTask.state = TASK_STATE_RUNNING_MOTOR;
    } else if (nextTaskStep.postDelayMillis > 0) {
      delayTime.setdelay(nextTask.postDelayMillis);
      delayTime.start();
      nextTask.state = TASK_STATE_POST_WAIT;
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
*/

void loop() {

  resetAndStartButton.loop();
  startPositionIndicator.loop();

  bool resetAndStartButtonActivated = resetAndStartButton.isPressed();
  bool onStartPosition = startPositionIndicator.isPressed();

  //log_printf("state: %i, reset: %i, startPos: %i\n", controllerState, resetAndStartButtonActivated, startPositionIndicatorActivated);

  switch (controllerState) {
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
          // TODO!! doStartSequence();
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
          // TODO!! doEndSequence();
        } else {
          advanceTasks();
        }

        if (isSequenceDone()) {
          controllerState = CONTROLLER_PROGRAM_STATE_DONE;
        }

        break;
      }
  }
}
