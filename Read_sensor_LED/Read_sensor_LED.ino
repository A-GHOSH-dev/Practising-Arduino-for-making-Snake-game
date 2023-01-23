int sensorPin = 0;
int ledPin = 1000;
void setup()
{
  analogReference(DEFAULT);//isn't necessary

  pinMode(ledPin,OUTPUT);
  
}
void loop()
{
  int val = analogRead(sensorPin);

  val=constrain(val,750,900);

  int ledLevel = map(val,750,900,255,0);

  analogWrite(ledPin,ledLevel);
}
