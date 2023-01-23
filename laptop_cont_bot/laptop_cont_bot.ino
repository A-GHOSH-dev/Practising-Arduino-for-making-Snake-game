int motorR1=10;        // Motor Pins
int motorR2=9;
int motorL1=5;
int motorL2=6;
char x;

void setup ()
{
  Serial.begin (9600);
  pinMode(motorR1,OUTPUT);
  pinMode(motorR2,OUTPUT);
  pinMode(motorL1,OUTPUT);
  pinMode(motorL2,OUTPUT);
}

void loop()
{ 
  x=Serial.read();                             // taking input from keyboard
  if(x=='W' || x=='w')                           //forward using letter 'w'
  {
    digitalWrite(motorR1,LOW);
    digitalWrite(motorR2,HIGH);
    digitalWrite(motorL1,LOW);
    digitalWrite(motorL2,HIGH);
  }
  else if (x=='s' || x=='S')                    //backward
  {
    digitalWrite(motorR1,HIGH);
    digitalWrite(motorR2,LOW);
    digitalWrite(motorL1,HIGH);
    digitalWrite(motorL2,LOW);
  }
  else if (x=='a' || x=='A')                    //left 
  {
    digitalWrite(motorR1,LOW);
    digitalWrite(motorR2,HIGH);
    digitalWrite(motorL1,HIGH);
    digitalWrite(motorL2,LOW);
  }
  else if (x=='d' || x=='D')                    //right
  {
    digitalWrite(motorR1,HIGH);
    digitalWrite(motorR2,LOW);
    digitalWrite(motorL1,LOW);
    digitalWrite(motorL2,HIGH);
  }
  else if (x==' ')                              //stop
  {
    digitalWrite(motorR1,LOW);
    digitalWrite(motorR2,LOW);
    digitalWrite(motorL1,LOW);
    digitalWrite(motorL2,LOW);
  }
}
