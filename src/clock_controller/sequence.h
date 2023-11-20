
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

  // initial sync. wait 
  { .speed = 0, .acceleration = 0, .destination1 = 0, .destination2 = 0, .postDelayMillis = 1900, .repeat = 1 },

  // first single step
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 3600, .repeat = 1 },

  // seven one-second ticks followed by 2,3 second wait
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 630, .repeat = 6 },
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 2300, .repeat = 1 },

  // seven one-second ticks followed by 1,5 second wait
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 630, .repeat = 6 },
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 1500, .repeat = 1 },

  // seven one-second ticks followed by 1,6 second wait
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 630, .repeat = 6 },
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 1600, .repeat = 1 },

  // six one-second ticks followed by 2,6 second wait
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 630, .repeat = 5 },
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 2600, .repeat = 1 },

  // four half-second ticks followed by 0,2 second wait
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_HALF_SECOND_TICK, .destination2 = 0, .postDelayMillis = 360, .repeat = 3 },
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_HALF_SECOND_TICK, .destination2 = 0, .postDelayMillis = 200, .repeat = 1 },

  // sixteen one-second ticks
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 620, .repeat = 16 },

  // wait one second
  { .speed = 0, .acceleration = 0, .destination1 = 0, .destination2 = 0, .postDelayMillis = 1000, .repeat = 1 },

  // rotate backwards - slowly
  { .speed = 200, .acceleration = 200, .destination1 = REVERSE_DIRECTION*ONE_FULL_ROUND*1.8, .destination2 = 0, .postDelayMillis = 0, .repeat = 1 },

  // 4 half-second ticks
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_HALF_SECOND_TICK, .destination2 = 0, .postDelayMillis = 360, .repeat = 3 },
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_HALF_SECOND_TICK, .destination2 = 0, .postDelayMillis = 360, .repeat = 1 },

  // rotate backwards - fast
  { .speed = 800, .acceleration = 600, .destination1 = REVERSE_DIRECTION*ONE_FULL_ROUND*8.2, .destination2 = 0, .postDelayMillis = 0, .repeat = 1 },

  // four one-second ticks - slowing down
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 630, .repeat = 1 },
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 665, .repeat = 1 },
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 700, .repeat = 1 },
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 1010, .repeat = 1 },
 
  // rotate forwards
  { .speed = 530, .acceleration = 600, .destination1 = ONE_FULL_ROUND*13.96, .destination2 = 0, .postDelayMillis = 4650, .repeat = 1 },

  // seven one-second ticks followed by 2.3 second wait
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 620, .repeat = 6 },
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 2200, .repeat = 1 },

  // five one-second ticks - slowing down
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 825, .repeat = 1 },
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 975, .repeat = 1 },
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 1175, .repeat = 1 },
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 1350, .repeat = 1 },
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 0, .repeat = 1 },

  // wait 15 seconds
  { .speed = 0, .acceleration = 0, .destination1 = 0, .destination2 = 0, .postDelayMillis = 15000, .repeat = 1 },

  // rotate forwards - half a round
  { .speed = 200, .acceleration = 200, .destination1 = ONE_FULL_ROUND*0.5, .destination2 = 0, .postDelayMillis = 0, .repeat = 1 },
};

int sequenceLength = sizeof(sequence) / sizeof(sequence[0]);

#endif