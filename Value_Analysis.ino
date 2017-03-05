/* 
 MAE 322
 2/28/2017
 Robot Motion Script version 0.1 (not stable)
 Authors: Jan Bernhard,
 Last modified: xx/xx/xxxx 

 Discription: This script holds the main commands for the MAE 322 robot.
 Capabilities: 
  - Non so far
*/


// global variables. 

// LEDs
int led = 13;

// Remote Control Channels
int ch1, ch2, ch3, ch4, ch5, ch6;

// Sensors
int proximitySensor; // holds proximity sensor value
int photonSensor; // holds photo receptor value. 

//// Servo
//const int rightServo = 0;
//const int leftServo = 1;
//
//// Servo output adjustment
//const int left_forward_fast = 2000;       // CCW Fast
//const int left_forward_slow = 1650;
//const int left_stop = 1500;               // Center position
//const int left_backward_slow = 1350;
//const int left_backward_fast = 1000;      // CW Fast
//
//const int right_forward_fast = 1000;      // CW Fast
//const int right_forward_slow = 1325;
//const int right_stop = 1500;              // Center position
//const int right_backward_slow = 1650;
//const int right_backward_fast = 2000;      // CCW Fast

void setup() {
// put your setup code here, to run once
// Declaring Pin modes
pinMode(led, OUTPUT);
pinMode(7,INPUT);
pinMode(8,INPUT);
pinMode(9,INPUT);
pinMode(10,INPUT);
pinMode(11,INPUT);
pinMode(12,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);

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
Serial.begin(9600);
while(!Serial);
}

void loop() {
  // Capture PWM of remote control:
//  ch1 = pulseIn(11, HIGH, 21000); // Capture pulse width on Channel 1
//  ch2 = pulseIn(12, HIGH, 21000); // Capture pulse width on Channel 2
//  ch3 = pulseIn(14, HIGH, 21000); // Capture pulse width on Channel 3
//  ch4 = pulseIn(15, HIGH, 21000); // Capture pulse width on Channel 4
//  ch5 = pulseIn(16, HIGH, 21000); // Capture pulse width on Channel 5
//  ch6 = pulseIn(17, HIGH, 21000); // Capture pulse width on Channel 6

  // Capture sensor values
  photonSensor = pulseIn(5,HIGH, 21000);
  proximitySensor = pulseIn(6,HIGH, 21000);
  // Call functions
  
  // put your main code here, to run repeatedly:
  Serial.println("Value to right servo unit: " + (String) proximitySensor);
  Serial.println("Value to left servo unit: " + (String) photonSensor);

}


