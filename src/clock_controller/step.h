
#ifndef STEP_H
#define STEP_H
#include "definitions.h"

class Step {
  public:
    short speed;
    short acceleration;
    short destination;
    short delayMillis;

    Step(short speed, short acceleration, short destination, short delayMillis) {
      speed = speed;
      acceleration = acceleration;
      destination = destination;
      delayMillis = delayMillis;
    }
};

#endif