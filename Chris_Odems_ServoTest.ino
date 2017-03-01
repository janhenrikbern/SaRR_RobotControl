//Basic Motion test

// globals
// LEDs
int onboardLEDPin = 13;                    // for diagnostics

// Servos
const int leftServo = 0;
const int rightServo = 1;

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
  Serial.begin(9600);
  pinMode(leftServo, OUTPUT);
  pinMode(rightServo, OUTPUT);
  pinMode(onboardLEDPin, OUTPUT);
// A great diagnostic tool!  When it blinks, turn on servo power
  for (int i = 0; i < 3; i++) {
    digitalWrite(onboardLEDPin, HIGH);
    delay(500);
    digitalWrite(onboardLEDPin, LOW);
    delay(500);        
  }
  // don't forget to open the Serial Monitor
}

void loop() {
  // call your functions here:
testSetup();
  while (true);       // pause code forever!
}


void testSetup() {
    // test the servo motors
    forwardFast(75);
    backwardFast(75);
    forwardSlow(75);
    backwardSlow(75);
    rightFast(75);
    leftFast(75);
    rightSlow(75);
    leftSlow(75);
}
