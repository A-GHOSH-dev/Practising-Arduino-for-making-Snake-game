int ledPin = 13;
int switchPin = 8;
boolean lastButton=LOW;
boolean currentButton = LOW;
boolean ledOn= false;


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
    ledOn!=ledOn;
  }
  lastButton=digitalRead(switchPin);
  digitalWrite(ledPin,ledOn);
}
