/*
  MAE 322
  2/28/2017
  Robot Motion Script version 0.1 (not stable)
  Authors: Jan Bernhard,
  Last modified: xx/xx/xxxx

  Discription: This script holds the main commands for the MAE 322 robot.
  Capabilities:
  - Finds light and drives to it.
*/
//void forwardDistance(){
/*
   This function moves forward until it gets too close to an Obstacle.
   It checks the proximity to the next object and decides on that basis
   how fast it will move.
*/
//********************** CONSTANTS ***************************************
//int nextObject = proximitySensor;
int closeDistance = 200; //approximate proximity sensor value at 1 foot

//********************** MAIN OPERATION **********************************
// call motion module functions with step value
// start slow for increased friction then switch to fast and back to slow.
/*if(nextObject <= tooClose){
  StopBot(500);
  return;
  }
  if(nextObject < closeDistance) {
  Lwheel = left_forward_slow;
  Rwheel = right_forward_slow;
  pulseMotors();
  }
  else {
  Lwheel = left_forward_slow;
  Rwheel = right_forward_slow;
  pulseMotors();
  delay(1000);
  Lwheel = left_forward_fast;
  Rwheel = right_forward_fast;
  pulseMotors();
  delay(1000);
  Lwheel = left_forward_slow;
  Rwheel = right_forward_slow;
  pulseMotors();
  delay(1000);
  }
  }
*/

void driveStraight() {

  int tolerance = 40;
  int slow = 150; //1500 +/- value = speed
  int closeDistance = 200;

  if (C_SharpValue < closeDistance) {
    Serial.println(signalDifference);
    if (signalDifference < tolerance) {
      driveForward(100, slow);
      //checkSensors();
      photonSensorL = analogRead(L_photonSensorPin);
      photonSensorR = analogRead(R_photonSensorPin);
      C_SharpValue = analogRead(C_SharpPin);
      signalDifference = photonSensorL - photonSensorR;
      //nextObject = C_SharpValue;
    }
  }


}

void driveForward(int ms, int velocity) {
  Serial.println("Drive forward");
  Lwheel = 1500 + velocity; //change plus/minus based on motor orientation
  Rwheel = 1500 + velocity;
  pulseMotors();
  //delay(ms);

}

void tLeft() {
  Lwheel = left_forward_slow;
  Rwheel = right_backward_slow;
  pulseMotors();
    delay(200);
    Lwheel = left_stop;
    Rwheel = right_stop;
    pulseMotors();
}

void tRight() {
  Lwheel = left_backward_slow;
  Rwheel = right_forward_slow;
  pulseMotors();
   delay(200);
    Lwheel = left_stop;
    Rwheel = right_stop;
    pulseMotors();
}

void checkSensors() {
  photonSensorL = analogRead(L_photonSensorPin);
  photonSensorR = analogRead(R_photonSensorPin);
  C_SharpValue = analogRead(C_SharpPin);
  signalDifference = photonSensorL - photonSensorR;
  Serial.println(signalDifference);
}

void findLight() {
  /*
     This function makes the robot search and drive towards a bright light
     source.
  */
  //********************** CONSTANTS ***************************************
  //int brightLight; // assign value after determining it emperically
  int foundLight = 300; //min signal value for detecting light
  int tolerance = 40; //error for detecting same signal from both sensors
  //int signalDifference = photonSensorL - photonSensorR; //difference between right and left photosensor signal
  //int nextObject = C_SharpValue;
  int closeDistance = 400;


  //********************** MAIN OPERATION **********************************
  //rotate until light is initially found
  if (flag) {
    flag = false;
    while (abs(signalDifference) < foundLight) {
      //checkSensors();
      photonSensorL = analogRead(L_photonSensorPin);
      photonSensorR = analogRead(R_photonSensorPin);
      C_SharpValue = analogRead(C_SharpPin);
      signalDifference = photonSensorL - photonSensorR;
      Serial.println("finding light");
      tRight();
    }
    Serial.println("Found light");
    delay(1000);
  }

Serial.println("Initiating Stage 2");

  if (C_SharpValue < closeDistance) {
    Serial.println("Entered Stage 2");
    
    //adjust direction toward light
    // Problem here: Never enters correction: Never completes Stage 2
    if (abs(signalDifference) > tolerance) {
      Serial.println("greater than tolerance");
      if (signalDifference > tolerance) {
        tLeft();
        Serial.println("Left Correction");
      }
      if (signalDifference < tolerance) {
        tRight();
        Serial.println("Right Correction");
      }
Serial.println("Completed Stage 2");

      //checkSensors();
      photonSensorL = analogRead(L_photonSensorPin);
      photonSensorR = analogRead(R_photonSensorPin);
      C_SharpValue = analogRead(C_SharpPin);
      signalDifference = photonSensorL - photonSensorR;

      //Serial.println(C_SharpValue);
      if (C_SharpValue < closeDistance) {
        Serial.println("drive straight");
        driveStraight();
        //checkSensors();
        photonSensorL = analogRead(L_photonSensorPin);
        photonSensorR = analogRead(R_photonSensorPin);
        C_SharpValue = analogRead(C_SharpPin);
        signalDifference = photonSensorL - photonSensorR;
      }
      else {
        Serial.println("stop");
      }
    }
  }

}

