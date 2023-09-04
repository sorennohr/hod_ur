
#define MOTOR_PIN_1 7
#define MOTOR_PIN_2 6

#define RESET_AND_START_BUTTON_PIN            12
#define START_POS_INDICATOR_PIN               8

#define CONTROLLER_PROGRAM_STATE_READY        1
#define CONTROLLER_PROGRAM_STATE_RESETTING    2
#define CONTROLLER_PROGRAM_STATE_RUNNING      3
#define CONTROLLER_PROGRAM_STATE_DONE         4

#define TASK_TYPE_ACCELERATION                1
#define TASK_TYPE_CONSTANT_SPEED              2
#define TASK_TYPE_DELAY                       3

#define STEPS_PR_ROUND                        400
#define ONE_ROUND                             1*STEPS_PR_ROUND
#define REVERSE_DIRECTION                     -1
#define ONE_TWELVETH_ROUND                    STEPS_PR_ROUND/12
