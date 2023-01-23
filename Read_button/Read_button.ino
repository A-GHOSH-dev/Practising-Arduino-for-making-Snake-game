//Reads the state of the button and displays it on the screen

int buttonPin= 8;


void setup()
{
  //sets the button pin as input
  pinMode(buttonPin,INPUT);
  //Allows us to listen to serial communications from arduino
  Serial.begin(9600);
}


void loop()
{
  //print the button state to serial terminal
  Serial.println(digitalRead(buttonPin));
  delay(1000);
  //wait one second and print again 
}
