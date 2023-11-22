
#define MOTOR_PIN_1 7
#define MOTOR_PIN_2 6

#define START_POS_INDICATOR_PIN               5
#define SYSTEM_RESET_PIN                      10
#define RESET_AND_START_BUTTON_PIN            12
#define RESET_AND_START_BUTTON_LED_PIN        13

#define CONTROLLER_PROGRAM_STATE_READY        1
#define CONTROLLER_PROGRAM_STATE_RESETTING    2
#define CONTROLLER_PROGRAM_STATE_RUNNING      3
#define CONTROLLER_PROGRAM_STATE_INIT         4

#define TASK_STATE_INIT                       0
#define TASK_STATE_DEST1                      1
#define TASK_STATE_DEST2                      2
#define TASK_STATE_POST_WAIT                  3

#define TICKS_PR_ROUND                        12
#define SECOND_TICKS_PR_ROUND                 60
#define STEPS_PR_ROUND                        1600
#define STEPS_PR_TICK                         STEPS_PR_ROUND/TICKS_PR_ROUND
#define STEPS_PR_SECOND_TICK                  STEPS_PR_ROUND/SECOND_TICKS_PR_ROUND
#define STEPS_PR_HALF_SECOND_TICK             STEPS_PR_SECOND_TICK/2

#define ONE_FULL_ROUND                        STEPS_PR_ROUND
#define TICK_MAX_SPEED                        600
#define TICK_ACCELERATION                     1000    
#define TICK_OVERSHOOT_STEP_COUNT             3
#define TICK_AFTER_TICK_WAIT                  400

#define SECOND_TICK_MAX_SPEED                 600
#define SECOND_TICK_ACCELERATION              1000    
#define SECOND_TICK_OVERSHOOT_STEP_COUNT      3
#define SECOND_TICK_AFTER_TICK_WAIT           800

#define REVERSE_DIRECTION                     -1
