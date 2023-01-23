/*
Ananya's First Program
*/

int ledPin=13;

void setup()  //will contain program that will learn when arduino is setup first
{
  //initialie pins as output
  pinMode(ledPin,OUTPUT);
}

//blinking LED onn/off holding for one second each time
void loop()  //will contain program that will run continuously in a loop as long as arduino is working
{
  digitalWrite(ledPin,HIGH);
  delay(1000);
  digitalWrite(ledPin,LOW);
  delay(1000);
}
