/* 
 MAE 322
 2/28/2017
 Robot Motion Script version 0.1 (not stable)
 Authors: Jan Bernhard,
 Last modified: xx/xx/xxxx 

 Dependencies: Chris_Odems_MotionModule.ino

 Discription: This script holds the main commands for the MAE 322 robot.
 Capabilities: 
  - Non so far
*/
// *********************************************************************
// ************************** GLOBAL VARIABLES *************************
// *********************************************************************
#include <Servo.h>
// global variables. 

// LEDs
const int led = 13;

// Remote Control Channels
int ch1, ch2, ch3, ch4, ch5, ch6;

// Sensors
int proximitySensor; // holds proximity sensor value
int photonSensorL; // holds left photon receptor value. 
int photonSensorR; // holds left photon receptor value. 
const int tooClose = 900; // proximity sensor value for minimum distance from object.

// Servo
Servo L_Servo;
Servo R_Servo;
int Lwheel;
int Rwheel;

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

// *********************************************************************
// *********************************************************************
// *********************************************************************

void setup() {
//  Attaching Servos
L_Servo.attach(0);
R_Servo.attach(1);
// put your setup code here, to run once
// Declaring Pin modes
pinMode(led,OUTPUT); // on board LED. 
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
pinMode(8,INPUT);
pinMode(9,INPUT);
pinMode(10,INPUT);
pinMode(11,INPUT);
pinMode(12,INPUT);

// 3 flashes of the LED signals that setup was successful and
// code proceeds to infinite loop section. 
// WHEN IT BLINKS, TURN ON SERVO POWER SUPPLY
for(int i = 0; i <= 3; i++){
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(500);
}
// starting window sequence. 
//Serial.begin(9600);
//while(!Serial);
}

void loop() {
  // capture sensor input
  photonSensor1 = pulseIn(5, HIGH, 21000);
  photonSensor2 = pulseIn(6, HIGH, 21000);
//  proximitySensor = ;
  // Capture PWM of remote control:
  ch1 = pulseIn(7, HIGH, 21000); // Capture pulse width on Channel 1
  ch2 = pulseIn(8, HIGH, 21000); // Capture pulse width on Channel 2
//  ch3 = pulseIn(9, HIGH, 21000); // Capture pulse width on Channel 3
//  ch4 = pulseIn(10, HIGH, 21000); // Capture pulse width on Channel 4
  ch5 = pulseIn(11, HIGH, 21000); // Capture pulse width on Channel 5
//  ch6 = pulseIn(12, HIGH, 21000); // Capture pulse width on Channel 6
  

  // Call functions
  SetLimits();
  DriveServosRC();
//  autonomous();

}

//********************** MixLimits() ***************************
//*******  Make sure values never exceed ranges  ***************
//******  For most all servos and like controlers  *************
//****   control must fall between 1000uS and 2000uS  **********
//**************************************************************
void SetLimits() {
  if (Lwheel < 1000) {// Can be set to a value you don't wish to exceed
    Lwheel = 1000;    // to adjust maximums for your own robot
  }
  if (Lwheel > 2000) {// Can be set to a value you don't wish to exceed
    Lwheel = 2000;    // to adjust maximums for your own robot
  }
  if (Rwheel < 1000) {// Can be set to a value you don't wish to exceed
    Rwheel = 1000;    // to adjust maximums for your own robot
  }
  if (Rwheel > 2000) {// Can be set to a value you don't wish to exceed
    Rwheel = 2000;    // to adjust maximums for your own robot
  }
  pulseMotors();
}

//*******************   pulseMotors  ***************************
//pulses either mapped or direct signals generated from Mixlimits
//**************************************************************
void pulseMotors() {
  //un-comment the next two line to drive the wheels directly with the MaxLimits Set
//  R_Servo.writeMicroseconds(Rwheel);
//  L_Servo.writeMicroseconds(Lwheel);

  //un-comment the next two to map a control range.
  //*** Take the standard range of 1000 to 2000 and frame it to your own minimum and maximum
  //*** for each wheel.
  Rwheel = map(Rwheel, 1000, 2000, 1350, 1650);
  Lwheel = map(Lwheel, 1000, 2000, 1350, 1650);
  R_Servo.writeMicroseconds(Rwheel);
  L_Servo.writeMicroseconds(Lwheel);
 
  // un-comment this line do display the value being sent to the motors
//  PrintWheelCalcs(); //REMEMBER: printing values slows reaction times

}

//*****************  PrintWheelCalcs()  ************************
//*******  Prints calculated wheel output values  **************
//**************************************************************
void PrintWheelCalcs() {
  Serial.print("Right Wheel = ");
  Serial.println(Rwheel);
  Serial.print("Left Wheel = ");
  Serial.println(Lwheel);
  Serial.println(" ");
}

//*******************  DriveServosRC()  ************************
//******  Use the value collected from Ch1 and Ch2  ************
//******  on a single stick to relatively calculate  ***********
//****  speed and direction of two servo driven wheels *********
//**************************************************************
void DriveServosRC()
{
  if (ch2 <= 1500) {
    Lwheel = ch1 + ch2 - 1500;
    Rwheel = ch1 - ch2 + 1500;
    SetLimits();
  }
  if (ch2 > 1500) {
    int ch1_mod = map(ch1, 1000, 2000, 2000, 1000); // Invert the Ch1 axis to keep the math similar
    Lwheel = ch1_mod + ch2 - 1500;
    Rwheel = ch1_mod - ch2 + 1500;
    SetLimits();
  }
}

//**********************  PrintRC()  ***************************
//***  Simply print the collected RC values for diagnostics  ***
//**************************************************************
void PrintRC()
{ // print out the values you read in:
  Serial.println(" RC Control Mode ");
  Serial.print("Value Ch1 = ");
  Serial.println(ch1);
  Serial.print("Value Ch2 = ");
  Serial.println(ch2);
  Serial.print("Value Ch3 = ");
  Serial.println(ch3);
  Serial.print("Value Ch4 = ");
  Serial.println(ch4);
  Serial.print("Control = ");
  Serial.println(ch5);
  Serial.print("Value Ch6 = ");
  Serial.println(ch6);
  Serial.println(" ");
  delay(1000);
}

void autonomous() {
  while(ch5 > 1600){
    digitalWrite(led, HIGH);
    findLight();
  };
}

