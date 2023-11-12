
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

//struct task sequence_music_demo1[] = {
struct task sequence[] = {
  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 7200 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 3700 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 }, 

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 2300 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = 630 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 }

};


struct task sequence_clockwise_slowly[] = {
//struct task sequence[] = {
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1", .maxSpeed = 50, .acceleration = 50, .destination = 999999999, .delayMillis = 0 }
};


struct task sequence_12_ticks_clockwise[] = {
//struct task sequence[] = {
  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = STEPS_PR_TICK+TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = -TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick2", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = STEPS_PR_TICK+TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = -TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick3", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = STEPS_PR_TICK+TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = -TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick3", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = STEPS_PR_TICK+TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = -TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick3", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = STEPS_PR_TICK+TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = -TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick3", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = STEPS_PR_TICK+TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = -TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick3", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = STEPS_PR_TICK+TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = -TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick3", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = STEPS_PR_TICK+TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = -TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick3", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = STEPS_PR_TICK+TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = -TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick3", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = STEPS_PR_TICK+TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = -TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick3", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = STEPS_PR_TICK+TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = -TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick3", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = STEPS_PR_TICK+TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = TICK_MAX_SPEED, .acceleration = TICK_ACCELERATION, .destination = -TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 }
};

struct task sequence_single_tick_clockwise[] = {
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1", .maxSpeed = 200, .acceleration = 150, .destination = (STEPS_PR_ROUND/12)+TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = 100, .acceleration = 100, .destination = -TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
};

//struct task sequence[] = {
struct task sequence_10_second_ticks_clockwise[] = {
  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = SECOND_TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = SECOND_TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = SECOND_TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = SECOND_TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = SECOND_TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = SECOND_TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = SECOND_TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = SECOND_TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = SECOND_TICK_AFTER_TICK_WAIT },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "tick1", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = STEPS_PR_SECOND_TICK+SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = SECOND_TICK_MAX_SPEED, .acceleration = SECOND_TICK_ACCELERATION, .destination = -SECOND_TICK_OVERSHOOT_STEP_COUNT, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 0, .acceleration = 0, .destination = 0, .delayMillis = SECOND_TICK_AFTER_TICK_WAIT }  
};

struct task sequence_test1[] = {

  { .taskType = TASK_TYPE_DELAY, .id = "wait1", .maxSpeed = 10, .acceleration = 10, .destination = 5, .delayMillis = 1000 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1", .maxSpeed = 100, .acceleration = 100, .destination = (800/12)+20, .delayMillis = 0 },


  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1", .maxSpeed = 100, .acceleration = 100, .destination = (800/12)+20, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run1r", .maxSpeed = 100, .acceleration = 100, .destination = -20, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait2", .maxSpeed = 10, .acceleration = 10, .destination = 5, .delayMillis = 500 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "run2", .maxSpeed = 100, .acceleration = 100, .destination = (800/12)+20, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run3r", .maxSpeed = 100, .acceleration = 100, .destination = -20, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait3", .maxSpeed = 10, .acceleration = 10, .destination = 5, .delayMillis = 500 },
/*
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run3", .maxSpeed = 1000, .acceleration = 800, .destination = (800/12)+20, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run3r", .maxSpeed = 1000, .acceleration = 800, .destination = -20, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait3", .maxSpeed = 10, .acceleration = 10, .destination = 5, .delayMillis = 500 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "run3", .maxSpeed = 1000, .acceleration = 800, .destination = (800/12)+20, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run3r", .maxSpeed = 1000, .acceleration = 800, .destination = -20, .delayMillis = 0 },

  { .taskType = TASK_TYPE_DELAY, .id = "wait3", .maxSpeed = 10, .acceleration = 10, .destination = 5, .delayMillis = 500 },

  { .taskType = TASK_TYPE_ACCELERATION, .id = "run3", .maxSpeed = 1000, .acceleration = 800, .destination = (800/12)+20, .delayMillis = 0 },
  { .taskType = TASK_TYPE_ACCELERATION, .id = "run3r", .maxSpeed = 1000, .acceleration = 800, .destination = -20, .delayMillis = 0 }
*/

};

int sequenceLength = sizeof(sequence) / sizeof(sequence[0]);

#endif