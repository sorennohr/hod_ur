
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
  { .speed = 0, .acceleration = 0, .destination1 = 0, .destination2 = 0, .postDelayMillis = 2000, repeat = 1 },

  /* first single step */
  { .speed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination1 = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .destination2 = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .postDelayMillis = 3600, repeat = 1 },


};

/*struct task sequence[] = {
  
  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 2000 },

  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY,  .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 3600 },

 
 
 
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 }, 

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY,  .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
 


  { .type = TASK_TYPE_DELAY,  .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 2300 },




  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY,  .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },



  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 1500 },



  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY,  .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY,  .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },


  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 1600 },


  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY,  .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },


  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 2600 },


 { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_HALF_SECOND_TICK, .delayMillis = 0 },
  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 360 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_HALF_SECOND_TICK, .delayMillis = 0 },
  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 360 },

    { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_HALF_SECOND_TICK, .delayMillis = 0 },
  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 360 },

    { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_HALF_SECOND_TICK, .delayMillis = 0 },
  
  
  { .type = TASK_TYPE_DELAY,  .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 200 },



  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY,  .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 620 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY,  .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 620 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 620 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 620 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 620 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 620 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 620 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 620 },

  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 620 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY,  .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 620 },

  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 620 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 620 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

{ .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 620 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 620 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

   { .type = TASK_TYPE_DELAY, .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 620 },

  { .type = TASK_TYPE_ACCELERATION, .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .type = TASK_TYPE_ACCELERATION,  .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 }




};*/



int sequenceLength = sizeof(sequence) / sizeof(sequence[0]);

#endif