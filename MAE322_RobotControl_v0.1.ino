/* 
 MAE 322
 2/28/2017
 Robot Motion Script version 0.1 (not stable)

 Last modified: xx/xx/xxxx

 Dependencies: Chris_Odems_MotionModule.ino

 Discription: This script holds the main commands for the MAE 322 robot.
 Capabilities: 
  - Non so far
*/


// global variables. 

// LEDs
int onboardLEDPin = 13;

// Sensors
int proximitySensor; // holds proximity sensor value
int photoSensor; // holds photo receptor value. 

// Servo
const int rightServo = 0;
const int leftServo = 1;

// Servo output adjustment
const int left_forward_fast = 2000;       // CCW Fast
const int left_forward_slow = 1650;
const int left_stop = 1500;               // Center position
const int left_backward_slow = 1350;
const int left_backward_fast = 1000;      // CW Fast

const int right_forward_fast = 1000;      // CW Fast
const int right_forward_slow = 1325;
const int right_stop = 1500;              // Center position
const int right_backward_slow = 1650;
const int right_backward_fast = 2000;      // CCW Fast

void setup() {
// put your setup code here, to run once
// Declaring Pin modes
pinMode(onboardLEDPin, OUTPUT)
pinMode(rightServo, OUTPUT)
pinMode(leftServo, OUTPUT)
// starting window sequence. 
Serial.begin(9600);
while(!Serial);

// 3 flashes of the LED signals that setup was successful and
// code proceeds to infinite loop section. 
// WHEN IT BLINKS, TURN ON SERVO POWER SUPPLY
for(i = 0; i <= 3; i++){
  digitalWrite(onboardLEDPin, HIGH);
  delay(500)
  digitalWrite(onboardLEDPin, LOW);
  delay(500)
}
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Output to right servo unit: " + (String) rightServo)
Serial.println("Output to left servo unit: " + (String) leftServo)

}

void forwardDistance(int distance){
  /*
   * This function moves forward for a given distance. 
   * It checks the proximity to the next object and decides on that basis
   * how fast it will move. 
   */
  //********************** CONSTANTS ***************************************
  int stepValue;
  int stepValueSlow;
  int stepValueFast;
  int nextObject;
  int closeDistance;
  int farDistance;

  //********************** INITIAL CALCULATIONS ****************************
  // find conversion of distance [m] to step

  // convert proximitySensor value to distance to next object

  // Find distance ratio of slowForward() to fastForward().

  
  //********************** MAIN OPERATION **********************************
  // call motion module functions with step value
  // start slow for increased friction then switch to fast and back to slow.
  if(nextObject < closeDistance) {
    forwardSlow(stepValue)
  }
  else {
  forwardSlow(stepValueSlow);
  forwardFast(stepValueFast);
  forwardSlow(stepValueSlow);  
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
  while(photoSensor < brightLight){
    rightSlow(rotationSpeed)
  }
  while(photoSensor >= brightLight){
    forwardDistance(distanceSteps)
    if(proximitySensor > tooClose){
      break
    }
  }
}

