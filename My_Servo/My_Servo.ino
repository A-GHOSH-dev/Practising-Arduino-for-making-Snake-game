//Include the Servio Library
//Create a Servo Object
#include <Servo.h>
Servo MyServo;

//Define the Pins
int servoPin = 9;

void setup()
{
  //'Attach' the servo object
  //We dont need to set it as an output manually
  MyServo.attach(servoPin);
}

void loop()
{
  //Lets Turn the servo from 0 to 180
  // in increments of 20 degrees
  for (int i=0; i <=180; i=i+20)
  {
   MyServo.write(i);
   delay(1000); 
  }
}
