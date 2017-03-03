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
void forwardDistance(){
  /*
   * This function moves forward until it gets too close to an Obstacle.  
   * It checks the proximity to the next object and decides on that basis
   * how fast it will move. 
   */
  //********************** CONSTANTS ***************************************
  int stepValue;
  int stepValueSlow;
  int stepValueFast;
  int nextObject = photonSensor;
  int closeDistance = 500;
  
  //********************** MAIN OPERATION **********************************
  // call motion module functions with step value
  // start slow for increased friction then switch to fast and back to slow.
  if(nextObject <= tooClose){
    StopBot(500);
    while(nextObject < tooClose){
    nextObject = pulseIn(6, HIGH, 21000);
    Lwheel = 1450;
    Rwheel = 1550;
    pulseMotors();
    }
  }
  if(nextObject < closeDistance) {
    Lwheel = 1550;
    Rwheel = 1550;
    pulseMotors();
  }
  else {
    Lwheel = 1550;
    Rwheel = 1550;
    pulseMotors();
    delay(1000);
    Lwheel = 1650;
    Rwheel = 1650;
    pulseMotors();
    delay(1000);
    Lwheel = 1550;
    Rwheel = 1550;
    pulseMotors();
    delay(1000);  
  }


}

void findLight() {
  /*
   * This function makes the robot search and drive towards a bright light 
   * source. 
   */
 //********************** CONSTANTS ***************************************
  int brightLight; // assign value after determining it emperically
  int rotationSpeed = 1; // sets step speed of rotation
  int distanceSteps = 0.2; // meters
  int tooClose; // proximity sensor value for certain distance from object.

 //********************** MAIN OPERATION **********************************
  while(photonSensor < brightLight){
    rightSlow(rotationSpeed);
  }
  while(photonSensor >= brightLight){
    forwardDistance();
    if(proximitySensor > tooClose){
      break;
    };
  };
}
