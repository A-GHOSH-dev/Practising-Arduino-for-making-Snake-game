int trigPin = 13;     // Trig Pin Of HC-SR04
int echoPin = 12;     // Echo Pin Of HC-SR04
int motorR1=10;        // Motor Pins
int motorR2=9;
int motorL1=5;
int motorL2=6;
long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(motorR1,OUTPUT);    // Set Motor Pins As O/P
  pinMode(motorR2,OUTPUT);
  pinMode(motorL1,OUTPUT);
  pinMode(motorL2,OUTPUT);
  pinMode(trigPin, OUTPUT);  // Set Trig Pin As O/P To Transmit Waves
  pinMode(echoPin, INPUT);   //Set Echo Pin As I/P To Recieve Reflected Waves
}

void loop() {
  char a = Serial.read();
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH); // Transmit Waves For 10us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); // Recieve Reflected Waves
  distance = duration / 58.2; // Get Distance Distance= (Time x Speed of Sound in Air (343 m/s))/2
  delay(10);
  if (distance > 20) // Condition For Absence Of Obstacle            
  {
    digitalWrite(motorR1,LOW);
    digitalWrite(motorR2,HIGH);
    digitalWrite(motorL1,LOW);
    digitalWrite(motorL2,HIGH);                                                   
  }

  if (distance < 20) // Condition For Presence Of Obstacle
  {                
    digitalWrite(motorR1,LOW);     //Stop 
    digitalWrite(motorR2,LOW);
    digitalWrite(motorL1,LOW);
    digitalWrite(motorL2,LOW);
    delay(500);               
    digitalWrite(motorR1,HIGH);    // Move Backward 
    digitalWrite(motorR2,LOW);
    digitalWrite(motorL1,HIGH);
    digitalWrite(motorL2,LOW);
    delay(500);
    digitalWrite(motorR1,LOW);     //Stop 
    digitalWrite(motorR2,LOW);
    digitalWrite(motorL1,LOW);
    digitalWrite(motorL2,LOW);
    delay(100);       
    digitalWrite(motorR1,LOW);     // Move Left
    digitalWrite(motorR2,HIGH);
    digitalWrite(motorL1,HIGH);
    digitalWrite(motorL2,LOW);  
    delay(2000);
  }
  if(a=='S' || a=='s'){
    digitalWrite(motorR1,LOW);     //Stop 
    digitalWrite(motorR2,LOW);
    digitalWrite(motorL1,LOW);
    digitalWrite(motorL2,LOW);
  }
}
