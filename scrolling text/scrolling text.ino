/***************************************************
 * 8x8 LED MATRIX PROJECT
scrolling text massege by using array
written by RAJIV PARBAT
**************************************************
*/



int dataPinRow= A1;
int clockPinRow= 13;
int latchPinRow= A0;

int dataPinCol= 3;
int clockPinCol= 5;
int latchPinCol=4;

byte A[1][96]={
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,

B00111100, 
B01100110, 
B01100110, 
B01111110, 
B01111110, 
B01100110, 
B01100110,
B01100110,

B00000000,

B01111100,
B01111110,
B01100110,
B01100110,
B01100110,
B01100110,
B01111110,
B01111100,

B00000000,

B01111110,
B01111110,
B00011000,
B00011000,
B00011000,
B00011000,
B01111110,
B01111110,

B00000000,


B00000000,
B01100110,
B11111111,
B11111111,
B01111110,
B00111100,
B00011000,
B00000000,

B00000000,

B01111100,
B01100110,
B01100110,
B01111100,
B01111000,
B01111100,
B01100110,
B01100110,

B00000000,

B00111100, 
B01100110, 
B01100110, 
B01111110, 
B01111110, 
B01100110, 
B01100110,
B01100110,

B00000000,

B01111110,
B01111110,
B00011000,
B00011000,
B00011000,
B01011000,
B01111000,
B00111000,

B00000000,

B01111110,
B01111110,
B00011000,
B00011000,
B00011000,
B00011000,
B01111110,
B01111110,

B00000000,

B01100110,
B01100110,
B01100110,
B01100110,
B01100110,
B01100110,
B00111100,
B00011000,

B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000};
int timer =2  ;
byte gndData = 00000001;
byte gndDataFinal =0 ;
int k;
void setup() {
  // put your setup code here, to run once:
pinMode(dataPinRow,OUTPUT);
pinMode(clockPinRow, OUTPUT);
pinMode(latchPinRow, OUTPUT);

pinMode(dataPinCol, OUTPUT);
pinMode(clockPinCol, OUTPUT);
pinMode(latchPinCol, OUTPUT);



}

void loop() {
  // put your main code here, to run repeatedly:
  for (int x=0; x<89; x++)
  {
    for(int a=0; a<15; a++)
    {
for (byte i=0; i<1; i++)
{
  for (byte j=0; j<=7; j++)
  
  {
  int k=x+j;
    byte font = A[i][k];
    byte gndDataFinal = gndData << j; //00000000
    byte RowData=~gndDataFinal;  //11111110
    digitalWrite(latchPinRow, LOW);
    shiftOut(dataPinRow, clockPinRow, MSBFIRST, RowData);
    digitalWrite(latchPinRow,HIGH);
   
    {
      digitalWrite (latchPinCol, LOW);
      shiftOut(dataPinCol, clockPinCol, MSBFIRST, font);
      digitalWrite (latchPinCol, HIGH);
      
    }
     delay(timer);
    
    
  }
}

  }}}
