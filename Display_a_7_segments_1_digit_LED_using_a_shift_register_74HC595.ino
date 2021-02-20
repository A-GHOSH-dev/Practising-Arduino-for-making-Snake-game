//Display a 7 segment 1 digit LED using shift register 74HC595

/*LED pin a to g connects to Q0 to Q7, pin 8 of LED connects GND
OE is LOW, MR is High
*/
//Pin connected to ST_CP of 74HC595
int latchPin=6;
//Pin connected to SH_CP of 74HC595
int clockPin=7;
////Pin connected to DS of 74HC595
int dataPin=5;
//holders for information going to pass to shifting function
byte data;

const byte dataArray[10]={
  //0bdpGFEDCBA
  //Q7Q6Q5Q4Q3Q2Q1Q0
  0b00111111,//0
  0b00000110,//1
  0b01011011,//2
  0b01001111,//3
  0b01100110,//4
  0b01101101,//5
  0b01111101,//6
  0b00000111,//7

};

void setup(){
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
}

void loop(){
  for (int j=0;j<10;j++){
    //load the light sequence you want from array
    data=dataArray[j];
    //ground latchPin and hold low for as long as you are transmitting
    digitalWrite(latchPin,LOW);
    //MSBFIRST is Most Significant Bit First and LSBFIRST means Least Significant Bit first//0b00000111 so here MSB is first digit that is 0, and LSB is last digit that is 1
    shiftOut(dataPin,clockPin, MSBFIRST,data);
    //return the latchPin high to signal chip that it will copy data from shift register to storage register
    digitalWrite(latchPin,High);
    delay(500);
  }
}
