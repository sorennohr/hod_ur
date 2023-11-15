
#ifndef TASK_H
#define TASK_H

#include "step.h"

class Task {
  public:
    unsigned char repeat;
    unsigned char currentStep;
    unsigned char stepCount;
    Step steps[];

    Task(unsigned char repeat, unsigned char stepCount/*, Step steps[]*/) {
      repeat = repeat;
      currentStep = 0;
      stepCount = stepCount;
      //steps = steps;
    }
};

#endif