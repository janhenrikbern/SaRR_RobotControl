/* motion_module.ino
 C.D.Odom
 2/17/2015
 robot servo module

// These movement functions are the HIGHEST LEVEL of the movement commands.
// They  call the STEP functions below (which calls the createPulse function at the bottom) 
//to move some given number of steps.
*/

void forwardFast(int x) {
  for (int i = 0; i <= x ; i++) {
    forwardStepFast();
  }
}

void forwardSlow(int x) {
  for (int i = 0; i <= x ; i++) {
    forwardStepSlow();
  }
}

void backwardSlow(int x) {
  for (int i = 0; i <= x ; i++) {
    backwardStepSlow();
  }
}

void backwardFast(int x) {
  for (int i = 0; i <= x ; i++) {
    backwardStepFast();
  }
}
void rightFast(int x) {
  for (int i = 0; i <= x ; i++) {
    rightStepFast();
  }
}

void rightSlow(int x) {
  for (int i = 0; i <= x ; i++) {
    rightStepSlow();
  }
}

void leftSlow(int x) {
  for (int i = 0; i <= x ; i++) {
    leftStepSlow();
  }
}
void leftFast(int x) {
  for (int i = 0; i <= x ; i++) {
    leftStepFast();
  }
}

// These STEP functions are the SECOND LOWEST LEVEL of the movement commands.
// They simply take one "step" with the robot's two wheels by calling the createPulse function twice (one for each wheel).
// It is CRITICAL that you keep the 20ms delay, because it is necessary to give the motors time to respond!

void forwardStepFast() {
  createPulse(leftServo, left_forward_fast);
  createPulse(rightServo, right_forward_fast);
  delay(20);      // do NOT alter this delay time!      // do NOT alter this delay time!
}

void forwardStepSlow() {
  createPulse(leftServo, left_forward_slow);
  createPulse(rightServo, right_forward_slow);
  delay(20);      // do NOT alter this delay time!
}

void backwardStepSlow() {
  createPulse(leftServo, left_backward_slow);
  createPulse(rightServo, right_backward_slow);
  delay(20);      // do NOT alter this delay time!
}

void backwardStepFast() {
  createPulse(leftServo, left_backward_fast);
  createPulse(rightServo, right_backward_fast);
  delay(20);      // do NOT alter this delay time!
}

void rightStepSlow() {
  createPulse(leftServo, left_forward_slow);
  createPulse(rightServo, right_backward_slow);
  delay(20);      // do NOT alter this delay time!
}

void leftStepSlow() {
  createPulse(leftServo, left_backward_slow);
  createPulse(rightServo, right_forward_slow);
  delay(20);      // do NOT alter this delay time!
}

void rightStepFast() {
  createPulse(leftServo, left_forward_fast);
  createPulse(rightServo, right_backward_fast);
  delay(20);      // do NOT alter this delay time!
}

void leftStepFast() {
  createPulse(leftServo, left_backward_fast);
  createPulse(rightServo, right_forward_fast);
  delay(20);      // do NOT alter this delay time!
}

// createPulse is the LOWEST LEVEL (most basic) of the movement commands.
// It simply creates a single pulse of a given pulse width on a given pin.

void createPulse(byte servoPin, int pulseWidth) {
  // take one step with one servo
  digitalWrite(servoPin, HIGH);        // create the rising edge of the pulse
  delayMicroseconds(pulseWidth);       // precisely set pulse width in microseconds!
  digitalWrite(servoPin, LOW);         // create the falling edge of the pulse
}
