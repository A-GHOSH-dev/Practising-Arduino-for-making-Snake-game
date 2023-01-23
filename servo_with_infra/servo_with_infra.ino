//Include the Servio Library
//Create a Servo Object
#include <Servo.h>
Servo MyServo;

//Define the Pins
int servoPin = 9;
int distPin =0;

void setup()
{
  //'Attach' the servo object
  //We dont need to set it as an output manually
  MyServo.attach(servoPin);
}

void loop()
{
  int dist = analogRead(distPin);
  int pos =map(dist,0,1023,0,180);
  
  MyServo.write(pos);
    
}
