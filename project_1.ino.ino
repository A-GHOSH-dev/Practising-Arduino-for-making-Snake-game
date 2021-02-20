#define LATCH_PIN 3
#define CLOCK_PIN 4
#define DATA_PIN 2
#define LATCH A5
#define CLOCK A4
#define DATA 7
#include <IRremote.h>
#include<Servo.h>
#include <Adafruit_NeoPixel.h>
#define PIN 12
#define NUMPIXELS 20
#define powerLED 8
#define motorPin 13
#define D1 A0
#define D2 A1
#define D3 A2
#define D4 A3

Servo servo_test;
Adafruit_NeoPixel p = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
const int RECV_PIN = 0;
const int RECV = 11;
IRrecv irrecv(RECV_PIN);
IRrecv irr(RECV);
decode_results results;
decode_results r;

//variables and flags
int flag=0;
int flag1=0;
int angle = 0;
unsigned long key_value = 0;
unsigned long key = 0;
int redColor = 0;
int greenColor = 0;
int blueColor = 0;

void setup(){
  Serial.begin(9600);
  
  servo_test.attach(motorPin,500,2500);
  pinMode(motorPin,OUTPUT);
  
  p.begin();
  
  irrecv.enableIRIn();
  irrecv.blink13(true);
  
  irr.enableIRIn();
  irr.blink13(true);
  
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
  
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  
  pinMode(powerLED,OUTPUT);
  
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
}

void loop(){
  if (irrecv.decode(&results)){
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;
        switch(results.value){
          case 0xFD00FF://power
          PowLed();
          break;
          case 0xFD807F://vol+
          buzzer();
          break;
          case 0xFD40BF://func/stop
            //smotor();//error
          Serial.println("smotor");
            break;
          case 0xFD20DF:// |<</prev
          dc_motor();
          break;
          case 0xFDA05F:// >|
          digits();
          break;  
          case 0xFD609F:// >>|
          npleds();
          break;               
          case 0xFD10EF://DOWN
          numbers();
          break;  
          case 0xFD906F://VOL-
          Serial.println("VOL-");
          break;  
          case 0xFD50AF://UP
          Serial.println("UP");
          break;  
          case 0xFD30CF://0
          Serial.println("0");
          break;  
          case 0xFDB04F://EQ
          Serial.println("EQ");
          break;
          case 0xFD708F://REPEAT
          Serial.println("REPEAT");
          break;
          case 0xFD08F7://1
          Serial.println("1");
          break;
          case 0xFD8877://2
          Serial.println("2");
          break;
          case 0xFD48B7://3
          Serial.println("3");
          break;
          case 0xFD28D7://4
          Serial.println("4");
          break;
          case 0xFDA857://5
          Serial.println("5");
          break;
          case 0xFD6897://6
          Serial.println("6");
          break;
          case 0xFD18E7://7
          Serial.println("7");
          break;
          case 0xFD9867://8
          Serial.println("8");
          break;
          case 0xFD58A7://9
          Serial.println("9");
          break;     
        }
        key_value = results.value;
        irrecv.resume(); 
  }
}

void PowLed(){
  if(flag==0){
    digitalWrite(powerLED,HIGH);
    flag=1;
  }
  else if(flag==1){
    digitalWrite(powerLED,LOW);
    flag=0;
  }
}

void IR_CodeFinder(){//IR button code finder
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        irrecv.resume();
  }
}

void dc_motor(){ // Control RPM of dc motor on Pin 6
  int q;
  for(q=1;q<4;q++){
    analogWrite(6,random(0,255));
    delay(1000);
  }
}
void buzzer(){ // buzzer on pin 5
  if(flag1==0){
    digitalWrite(5,HIGH);
    flag1=1;
  }
  else if(flag1==1){
    digitalWrite(5,LOW);
    flag1=0;
  }
}
void smotor(){
  digitalWrite(motorPin,HIGH);
  for(angle=0;angle<180;angle+=1){
    servo_test.write(angle);
    delay(20);
  }
  digitalWrite(motorPin,LOW);
  delay(1000);
  digitalWrite(motorPin,HIGH);
  for(angle=180;angle>0;angle=angle-1){
    servo_test.write(angle);
    delay(20);
  }
  digitalWrite(motorPin,LOW);
}

void digits(){
  zero();
  delay(1000);
  one();
  delay(1000);
  two();
  delay(1000);
  three();
  delay(1000);
  four();
  delay(1000);
  five();
  delay(1000);
  six();
  delay(1000);
  seven();
  delay(1000);
  eight();
  delay(1000);
  nine();
  delay(1000);
}

void npleds(){
  // neopixel leds changing color on pin 12
  setColor();
  for (int i=0; i < NUMPIXELS; i++) {
    p.setPixelColor(i, p.Color(redColor, greenColor, blueColor));
    p.show();
    delay(100);
  }
}
void clearall(){
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, 0b00000000);
  digitalWrite(LATCH_PIN, HIGH);
}
void zero(){
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, 0b11111100);
  digitalWrite(LATCH_PIN, HIGH);
}
void one(){
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, 0b01100000);
  digitalWrite(LATCH_PIN, HIGH);
}
void two(){
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, 0b11011010);
  digitalWrite(LATCH_PIN, HIGH);
}
void three(){
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, 0b11110010);
  digitalWrite(LATCH_PIN, HIGH);
}
void four(){
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, 0b01100110);
  digitalWrite(LATCH_PIN, HIGH);
}
void five(){
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, 0b10110110);
  digitalWrite(LATCH_PIN, HIGH);
}
void six(){
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, 0b10111110);
  digitalWrite(LATCH_PIN, HIGH);
}
void seven(){
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, 0b11100000);
  digitalWrite(LATCH_PIN, HIGH);
}
void eight(){
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, 0b11111110);
  digitalWrite(LATCH_PIN, HIGH);
}
void nine(){
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, 0b11110110);
  digitalWrite(LATCH_PIN, HIGH);
}

void numbers(){
  clearall1();
  dash();
  
  int i=1;
  for(i=1;i<=4;i++){
    switch(i){
      case 1:
      analogWrite(A0,HIGH);
      break;
      case 2:
      analogWrite(A1,HIGH);
      break;
      case 3:
      analogWrite(A2,HIGH);
      break;
      case 4:
      analogWrite(A3,HIGH);
      break;
    }
    if (irr.decode(&r)){
          if (r.value == 0XFFFFFFFF)
            r.value = key;
          switch(r.value){
            case 0xFD30CF://0
            zero1();
            break;
            case 0xFD08F7://1
            one1();
            break;
            case 0xFD8877://2
            two1();
            break;
            case 0xFD48B7://3
            three1();
            break;
            case 0xFD28D7://4
            four1();
            break;
            case 0xFDA857://5
            five1();
            break;
            case 0xFD6897://6
            six1();
            break;
            case 0xFD18E7://7
            seven1();
            break;
            case 0xFD9867://8
            eight1();
            break;
            case 0xFD58A7://9
            nine1();
            break;     
          }
          key = r.value;
          irr.resume(); 
    }
    analogWrite(A0,LOW);
    analogWrite(A1,LOW);
    analogWrite(A2,LOW);
    analogWrite(A3,LOW);
  }
}
void dash(){
  int i=1;
  for(i=1;i<=4;i++){
    switch(i){
      case 1:
      analogWrite(A0,HIGH);
      break;
      case 2:
      analogWrite(A1,HIGH);
      break;
      case 3:
      analogWrite(A2,HIGH);
      break;
      case 4:
      analogWrite(A3,HIGH);
      break;
    }
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, 0b00000010);
    digitalWrite(LATCH, HIGH);
    analogWrite(A0,LOW);
    analogWrite(A1,LOW);
    analogWrite(A2,LOW);
    analogWrite(A3,LOW);
  }
}
void clearall1(){
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, LSBFIRST, 0b00000000);
  digitalWrite(LATCH, HIGH);
}
void zero1(){
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, LSBFIRST, 0b11111100);
  digitalWrite(LATCH, HIGH);
}
void one1(){
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, LSBFIRST, 0b01100000);
  digitalWrite(LATCH, HIGH);
}
void two1(){
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, LSBFIRST, 0b11011010);
  digitalWrite(LATCH, HIGH);
}
void three1(){
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, LSBFIRST, 0b11110010);
  digitalWrite(LATCH, HIGH);
}
void four1(){
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, LSBFIRST, 0b01100110);
  digitalWrite(LATCH, HIGH);
}
void five1(){
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, LSBFIRST, 0b10110110);
  digitalWrite(LATCH, HIGH);
}
void six1(){
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, LSBFIRST, 0b10111110);
  digitalWrite(LATCH, HIGH);
}
void seven1(){
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, LSBFIRST, 0b11100000);
  digitalWrite(LATCH, HIGH);
}
void eight1(){
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, LSBFIRST, 0b11111110);
  digitalWrite(LATCH, HIGH);
}
void nine1(){
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, LSBFIRST, 0b11110110);
  digitalWrite(LATCH, HIGH);
}
void setColor(){
  redColor = random(0, 255);
  greenColor = random(0,255);
  blueColor = random(0, 255);
}
