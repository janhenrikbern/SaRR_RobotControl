//********************************************************
//    Forward Functions
//********************************************************
void forwardFast(int t) {
  L_Servo.writeMicroseconds(left_forward_fast);
  R_Servo.writeMicroseconds(right_forward_fast);
  delay(t);
}
void forwardSlow(int t) {
  L_Servo.writeMicroseconds(left_forward_slow);
  R_Servo.writeMicroseconds(right_forward_slow);
  delay(t);
}
//********************************************************
//    reverse Function
//********************************************************
void backwardFast(int t) {
  L_Servo.writeMicroseconds(left_backward_fast);
  R_Servo.writeMicroseconds(right_backward_fast);
  delay(t);
}
void backwardSlow(int t) {
  L_Servo.writeMicroseconds(left_backward_slow);
  R_Servo.writeMicroseconds(right_backward_slow);
  delay(t);
}
//********************************************************
//    TRight Functions
//********************************************************
void rightFast(int t) {
  L_Servo.writeMicroseconds(left_forward_fast);
  R_Servo.writeMicroseconds(right_backward_fast);
  delay(t);
}
void rightSlow(int t) {
  L_Servo.writeMicroseconds(left_forward_slow);
  R_Servo.writeMicroseconds(right_backward_slow);
  delay(t);
}
//********************************************************
//    TLeft Functions
//********************************************************
void leftFast(int t) {
  L_Servo.writeMicroseconds(left_backward_fast);
  R_Servo.writeMicroseconds(right_forward_fast);
  delay(t);
}
void leftSlow(int t) {
  L_Servo.writeMicroseconds(left_backward_slow);
  R_Servo.writeMicroseconds(right_forward_slow);
  delay(t);
}
//********************************************************
//    StopBot Function
//********************************************************
void StopBot(int t) {
  L_Servo.detach();
  R_Servo.detach();
  delay(t);
  L_Servo.attach(0);
  R_Servo.attach(1);
}
