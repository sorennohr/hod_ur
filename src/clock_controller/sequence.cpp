#include "sequence.h"
#include <Arduino.h>

#define LOG
#include <log.h>

int currentSequenceTaskIdx = 0;
struct task currentlyRunningTask;
int sequenceLength = sizeof(sequence) / sizeof(sequence[0]);
bool sequenceComplete = false;


void setupSequence() {
  //Serial.println("Setting up task sequence with %i tasks", sequenceLength);
  currentlyRunningTask = sequence[currentSequenceTaskIdx];
}

bool isSequenceDone() {
  return sequenceComplete;  
}

void advanceTasks() {
  if (isCurrentlyRunningTaskDone()) {
      if (currentSequenceTaskIdx < sequenceLength) {
        //Serial.println(F("Sequence completed"));
        sequenceComplete = true;
      } else {
          currentlyRunningTask = sequence[++currentSequenceTaskIdx];
      }
  }
}

bool isCurrentlyRunningTaskDone() {
  return true;
}

