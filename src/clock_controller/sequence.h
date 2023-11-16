
#ifndef SEQUENCE_H
#define SEQUENCE_H
#include "definitions.h"

struct task 
{
    short speed;
    short acceleration;
    short destination1;
    short destination2;
    short postDelayMillis;
    short repeat;
};

struct task sequence[] = {

  /* initial sync. wait */
  { .speed = 0, .acceleration = 0, .destination1 = 0, .destination2 = 0, .postDelayMillis = 2000, .repeat = 1 },

  /* first single step */
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 3600, .repeat = 1 },

  /* seven one-second ticks followed by 2,3 second wait */
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 630, .repeat = 6 },
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 2300, .repeat = 1 },

  /* seven one-second ticks followed by 1,5 second wait */
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 630, .repeat = 6 },
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 1500, .repeat = 1 },

  /* seven one-second ticks followed by 1,6 second wait */
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 630, .repeat = 6 },
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 1600, .repeat = 1 },

  /* six one-second ticks followed by 2,6 second wait */
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 630, .repeat = 5 },
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 1600, .repeat = 1 },

  /* four half-second ticks followed by 0,2 second wait */
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_HALF_SECOND_TICK, .destination2 = 0, .postDelayMillis = 360, .repeat = 3 },
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_HALF_SECOND_TICK, .destination2 = 0, .postDelayMillis = 200, .repeat = 1 },

  /* seventeen one-second ticks */
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 620, .repeat = 17 },
};

int sequenceLength = sizeof(sequence) / sizeof(sequence[0]);

#endif