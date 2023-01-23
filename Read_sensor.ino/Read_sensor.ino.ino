int sensorPin = 0;
void setup()
{
  analogReference(DEFAULT);//isn't necessary
  
  Serial.begin(600);
}
void loop()
{
  Serial.println(analogRead(sensorPin));
  delay(500);
}
