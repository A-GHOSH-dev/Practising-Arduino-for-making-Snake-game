int ledPin = 13;
int switchPin = 8;

void setup()
{
  pinMode(switchPin,INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop()
{
  if (digitalRead(switchPin)==HIGH)
  {
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }
}
