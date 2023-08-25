#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int oneMinute = stepsPerRevolution / 12;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);


void simpleTick(int direction) { 
  myStepper.setSpeed(18); // 18 seems to max reliable speed for this setup....
  myStepper.step(171*direction);
}

void freeRun(int direction, int rounds) {
  myStepper.setSpeed(18); // 18 seems to max reliable speed for this setup....
  myStepper.step(stepsPerRevolution*rounds*direction);
}

void oneSecondTick(int direction) {
  myStepper.setSpeed(1);
  myStepper.step(10*direction);
  myStepper.setSpeed(2);
  myStepper.step(6*direction);
  myStepper.setSpeed(3);
  myStepper.step(5*direction);
  myStepper.setSpeed(7);
  myStepper.step(150*direction);
}

void twoSecondTick(int direction) {
  myStepper.setSpeed(1);
  myStepper.step(10*direction);
  myStepper.setSpeed(2);
  myStepper.step(6*direction);
  myStepper.setSpeed(3);
  myStepper.step(5*direction);
  myStepper.setSpeed(4);
  myStepper.step(150*direction);
}


void setup() {
  // set the speed at 60 rpm:
  //myStepper.setSpeed(5);
}

void loop() {


/*
  for (int i = 0; i < 6; i++) {
    simpleTick(1);
    delay(500);
  }

  for (int i = 0; i < 3; i++) {
    simpleTick(1);
    delay(1000);
  }

  for (int i = 0; i < 6; i++) {
    simpleTick(-1);
    delay(500);
  }
 
  freeRun(-1, 3);

 // step one revolution  in one direction:
  //oneTick(1);
  delay(5000);

  // step one revolution in the other direction:
  //oneTick(-1);
  //delay(1000);

*/


simpleTick(1);
delay(50);
simpleTick(-1);
delay(50);

//freeRun(1, 1);

//delay(1000);


//freeRun(-1, 1);

}
