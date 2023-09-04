#include <AccelStepper.h>
#include <ezButton.h>
#include <NoDelay.h>

#include "definitions.h"
#include "sequence.h"

// Log all to Serial, comment this line to disable logging
#define LOG Serial

// Include must be placed after LOG definition to work
#include "log.h"

AccelStepper clockArmMotor(AccelStepper::DRIVER, MOTOR_PIN_1, MOTOR_PIN_2);
ezButton resetAndStartButton(RESET_AND_START_BUTTON_PIN);
ezButton startPositionIndicator(START_POS_INDICATOR_PIN);
noDelay delayTime(0);

int controllerState = CONTROLLER_PROGRAM_STATE_DONE;
int currentSequenceTaskIdx = 0;


void setup() {

  // setup start/reset button 
  resetAndStartButton.setDebounceTime(50);
  
  // setup start indicator
  startPositionIndicator.setDebounceTime(50);

  // setup serial output  
  Serial.begin(9600);

  log_printf("Setup complete\n");

}

void doReset() {
  log_printf("Starting reset to start position\n");
  controllerState = CONTROLLER_PROGRAM_STATE_RESETTING;

  clockArmMotor.setMaxSpeed(100);
  clockArmMotor.setAcceleration(100);
  clockArmMotor.move(ONE_FULL_ROUND);
}

void doReady() {
  log_printf("Ready to start sequence\n");
  controllerState = CONTROLLER_PROGRAM_STATE_READY;
  clockArmMotor.stop();
}

void doStartSequence() {
  log_printf("Sequence starting\n");
  controllerState = CONTROLLER_PROGRAM_STATE_RUNNING;
  currentSequenceTaskIdx = 0;
  startNextTask();
}

void doEndSequence() {
  log_printf("Sequence completed\n");
  controllerState = CONTROLLER_PROGRAM_STATE_DONE;
}

bool isCurrentlyRunningTaskDone() {
    struct task currentlyRunningTask = sequence[currentSequenceTaskIdx];

    switch (currentlyRunningTask.taskType) {
      case TASK_TYPE_DELAY:
      {
        return delayTime.update();
        break;
      }

      case TASK_TYPE_ACCELERATION:
      case TASK_TYPE_CONSTANT_SPEED:
      {
        return clockArmMotor.distanceToGo() == 0;
        break;
      }
    }
}

void startNextTask() {
  if (currentSequenceTaskIdx < sequenceLength) {
    struct task nextTask = sequence[currentSequenceTaskIdx];

    log_printf("Task [%s] starting\n", nextTask.id);

    switch (nextTask.taskType) {
      case TASK_TYPE_DELAY:
      {
        delayTime.setdelay(nextTask.delayMillis);
        delayTime.start();
        break;
      }

      case TASK_TYPE_ACCELERATION:
      case TASK_TYPE_CONSTANT_SPEED:
      {
        clockArmMotor.setMaxSpeed(nextTask.maxSpeed);
        clockArmMotor.setAcceleration(nextTask.acceleration);
        clockArmMotor.move(nextTask.destination);
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
      log_printf("Task [%s] completed\n", completedTask.id);
      startNextTask();
    }
  }
}

void loop() {
  
  resetAndStartButton.loop();
  startPositionIndicator.loop();

  bool startPositionIndicatorActivated = startPositionIndicator.isPressed();
  bool resetAndStartButtonActivated = resetAndStartButton.isPressed();

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

      if (startPositionIndicatorActivated) {
        doReady();
      }

      break;
    }

    case CONTROLLER_PROGRAM_STATE_RUNNING:
    {
      clockArmMotor.run();

      if (resetAndStartButtonActivated) {
        doReset();
      } else {
        doRunSequence();
      }

      break;
    }
  }
}
