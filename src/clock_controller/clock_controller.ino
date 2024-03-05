#include <AccelStepper.h>
#include <ezButton.h>
#include <NoDelay.h>

#include "definitions.h"
#include "sequence.h"

//#define LOG
//#define VERBOSE_LOG

AccelStepper clockArmMotor(AccelStepper::DRIVER, MOTOR_PIN_1, MOTOR_PIN_2);
ezButton resetAndStartButton(RESET_AND_START_BUTTON_PIN);
noDelay delayTime(0);

int controllerState = CONTROLLER_PROGRAM_STATE_INIT;
int currentSequenceTaskIdx = 0;
int currentTaskStep = TASK_STATE_INIT;

void setup() {

  controllerState = CONTROLLER_PROGRAM_STATE_INIT;
  currentSequenceTaskIdx = 0;
  currentTaskStep = TASK_STATE_INIT;

  // setup start/reset button 
  resetAndStartButton.setDebounceTime(25);

  // setup start/reset button LED pin
  pinMode(RESET_AND_START_BUTTON_LED_PIN, OUTPUT);

  // setup system reset pin
  digitalWrite(SYSTEM_RESET_PIN, HIGH);
  pinMode(SYSTEM_RESET_PIN, OUTPUT);

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

void doGoToStartPosition() {
#ifdef LOG
  Serial.println(F("Running to start position"));
#endif

  controllerState = CONTROLLER_PROGRAM_STATE_RESETTING;
  setupNewMotorTask(140, 200, ONE_HALF_ROUND);
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
  Serial.print(F("Sequence starting, steps in sequence: "));
  Serial.println(sequenceLength);
#endif

  digitalWrite(RESET_AND_START_BUTTON_LED_PIN, LOW);
  controllerState = CONTROLLER_PROGRAM_STATE_RUNNING;
  currentSequenceTaskIdx = 0;
  currentTaskStep = TASK_STATE_INIT;

  startTaskOrRepetitionOfTask();
}

void doSystemReset() {
#ifdef LOG
  Serial.println(F("Resetting...."));
#endif

  digitalWrite(SYSTEM_RESET_PIN, LOW);
}

bool isCurrentlyRunningTaskDone() {
  if (currentSequenceTaskIdx >= sequenceLength) {
    doSystemReset();
    return false;
  }

  struct task *currentlyRunningTask = &sequence[currentSequenceTaskIdx];

#ifdef VERBOSE_LOG
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
  if (currentSequenceTaskIdx >= sequenceLength) {
    doSystemReset();
    return;
  }

  struct task *taskToStartOrRepeat = &sequence[currentSequenceTaskIdx];

#ifdef VERBOSE_LOG
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

  if (currentlyRunningTaskIsComplete) { 
#ifdef LOG
    Serial.print(F("Task completed: "));
    Serial.println(currentSequenceTaskIdx);
#endif
    currentSequenceTaskIdx++;
    startTaskOrRepetitionOfTask();
  }
}

void loop() {
  
  resetAndStartButton.loop();

  bool resetAndStartButtonActivated = resetAndStartButton.isPressed();

  switch(controllerState)
  {
    case CONTROLLER_PROGRAM_STATE_INIT:
    {
      if (resetAndStartButtonActivated) {
        doGoToStartPosition();
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
      if (!clockArmMotor.run()) {
        // we never got to start-pos, but better to be able to start from where we ended....
        doReady();
        break;
      }

      if (resetAndStartButtonActivated) {
        doSystemReset();
        break;
      }

      break;
    }

    case CONTROLLER_PROGRAM_STATE_RUNNING:
    {
      if (resetAndStartButtonActivated) {  
        doSystemReset();
      } else {
        clockArmMotor.run();
        doRunSequence();
      }

      break;
    }
  }
}