
#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "definitions.h"

struct task 
{
    int taskType;
    const char* id;
    int maxSpeed;
    int acceleration;
    int destination;
    int delayMillis;
};

struct task sequence[] = {

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 10, .acceleration = 10, .destination = 5, .delayMillis = 10000 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1", .maxSpeed = 10, .acceleration = 10, .destination = 5, .delayMillis = 1000 },
  { .taskType = TASK_TYPE_DELAY, .id = "wait2", .maxSpeed = 10, .acceleration = 10, .destination = 5, .delayMillis = 10000 }
};

int sequenceLength = sizeof(sequence) / sizeof(sequence[0]);

#endif