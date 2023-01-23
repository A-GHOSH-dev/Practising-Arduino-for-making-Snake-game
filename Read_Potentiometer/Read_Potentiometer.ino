//reads the state of potentiometer and displays it on the screen
int potPin = 0;

void setup()
{
  // sets the potentiometer pin as input
  pinMode(potPin,INPUT);

  //Allows use to listen to serial communications from arduino
  Serial.begin(9600);
}

void loop()
{
  //print the pot state to a serial terminal
  Serial.println(analogRead(potPin));//reads value from 0-5V and assigns a digital value from 0-1023
  delay(1000); //1000ms=1s
  //wait 1 sec and then print again
}
