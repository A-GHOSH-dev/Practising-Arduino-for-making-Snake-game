#include <Servo.h>        
#include <NewPing.h>      



/*Here's a list of some of the features of NewPing:

Works with many different ultrasonic sensor models: HC-SR04, SRF05, SRF06, DYP-ME007, JSN-SR04T & Parallax PING)))™.
Option to interface with all but the SRF06 sensor using only one Arduino pin.
Doesn't lag for a full second if no ping echo is received like all other ultrasonic libraries.
Compatible with the entire Arduino line-up (and clones), Teensy family (including $19.80 96Mhz 32 bit Teensy 3.2) and non-AVR microcontrollers.
Ping sensors consistently and reliably at up to 30 times per second.
Timer interrupt method for event-driven sketches.
Built-in digital filter method ping_median() for easy error correction.
Uses port registers when accessing pins for faster execution and smaller code size.
Allows setting of a maximum distance where pings beyond that distance are read as no ping or clear.
Ease of using multiple sensors (sketch that pings 3 sensors - sketch that pings 15 sensors using timers).
More accurate distance calculation (cm, inches & microseconds).
Doesn't use pulseIn, which is slow and gives incorrect results with some ultrasonic sensor models.
Actively developed with features being added and bugs/issues addressed.
*/




// L298N Control Pins
const int LeftMotorForward = 4;
const int LeftMotorBackward = 5;
const int RightMotorForward = 6;
const int RightMotorBackward = 7;

#define TRIGGER_PIN  A1  
#define ECHO_PIN     A2  
#define MAX_DISTANCE 250 

Servo myServo;  
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

boolean goesForward = false;
int distance = 100;

void setup()
{
  
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
  myServo.attach(10);   /9---?
  myServo.write(115);    
  delay(2000);              
  distance = readPing();    
  delay(100);               
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop()
{  
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 20) 
  {
    moveStop();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distanceRight >= distanceLeft)
    {
      turnRight();
      delay(300);
      moveStop();
    }
    else
    {
      turnLeft();
      delay(300);
      moveStop();
    }
  
  }
  else
  {
    moveForward(); 
  }

    distance = readPing();
}

int lookRight()     //right looking
{  
  myServo.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  myServo.write(115);
  return distance;
}

int lookLeft()      // left looking 
{
  myServo.write(180);
  delay(500);
  int distance = readPing();
  delay(100);
  myServo.write(115);
  return distance;
}

int readPing()      //reading the ping
{
  delay(100);                 // 29ms should be the shortest delay between pings.
  int cm = sonar.ping_cm();   //get the distance in cm
  if (cm==0)
  {
    cm=250;
  }
  return cm;
}

void moveStop()       //stop moving
{
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward()    //start moving
{
    digitalWrite(RightMotorForward, HIGH);
    digitalWrite(RightMotorBackward, LOW);
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(LeftMotorBackward, LOW);
}

void moveBackward()   // move back
{
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, HIGH);
}

void turnRight()      // turn right
{
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
}

void turnLeft()       // turn left
{
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, HIGH);
}
