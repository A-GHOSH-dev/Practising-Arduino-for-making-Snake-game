int ledPin = 11;
int switchPin = 8;
boolean lastButton=LOW;
boolean currentButton = LOW;
int ledLevel = 0; 
//since we are communicating with PWM pins, they have brightness level we have values from 0-255 to control the brightness.

void setup()
{
  pinMode(switchPin,INPUT);
  pinMode(ledPin,OUTPUT);
}
boolean debounce(boolean last)
{
  boolean current = digitalRead(switchPin);
  if (last!=current)
  {
    delay(5);
    current=digitalRead(switchPin);
  }
  return current;
}

void loop()
{
  currentButton = debounce(lastButton);
  if (lastButton== LOW && currentButton == HIGH)
  {
    ledLevel=ledLevel+51;
  }
  lastButton=digitalRead(switchPin);
  
  if (ledLevel>255) ledLevel = 0;
  analogWrite(ledPin,ledLevel);
}
