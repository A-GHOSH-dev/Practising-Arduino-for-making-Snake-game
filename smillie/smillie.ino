/***************************************************
 * 8x8 LED MATRIX PROJECT
scrolling text massege by using array
**************************************************
*/



int dataPinRow= A1;
int clockPinRow= 13;
int latchPinRow= A0;

int dataPinCol= 3;
int clockPinCol= 5;
int latchPinCol=4;
int j;
byte A[]={
B00000000,
B01100110,
B01100110,
B01100110,
B00000000,
B00000000,
B01000010,
B00111100};
byte B[]={

B00000000,
B00000000,
B01100110,
B00000000,
B00000000,
B00000000,
B01000010,
B00111100};

byte C[]={

B00000000,
B01100110,
B01100110,
B01100110,
B00000000,
B00000000,
B01000010,
B00111100};
byte D[]={

B00000000,
B00110011,
B00110011,
B00110011,
B00000000,
B00000000,
B01111110,
B00000000};
byte E[]={

B00000000,
B01100110,
B01100110,
B01100110,
B00000000,
B00000000,
B01000010,
B00111100};

byte F[]={

B00000000,
B00000000,
B01100110,
B00000000,
B00000000,
B00000000,
B01000010,
B00111100};

byte G[]={

B00000000,
B01100110,
B01100110,
B01100110,
B00000000,
B00000000,
B01000010,
B00111100};

byte H[]={

B00000000,
B11011000,
B11011000,
B11011000,
B00000000,
B00000000,
B00111100,
B01000010};

byte I[]={
B00000000,
B01100110,
B10011001,
B00000000,
B00000000,
B00000000,
B01000010,
B00111100};


int timer =2 ;
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
  for (int i=0; i<50; i++)
  {
    for(int j=0; j<8; j++)
    {
    byte font = A[j];
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
    
    
  }}
if ( j=7);
{
  for (int i=0; i<5; i++)
  {
for (int j=0; j<8; j++)

{
  byte font = B[j];
  
    byte gndDataFinal = gndData << j; //00000000
    byte RowData=~gndDataFinal;  //11111110
    digitalWrite(latchPinRow, LOW);
    shiftOut(dataPinRow, clockPinRow, MSBFIRST, RowData);
    digitalWrite(latchPinRow,HIGH);
   
    {
      digitalWrite (latchPinCol, LOW);
      shiftOut(dataPinCol, clockPinCol, MSBFIRST, font);
      digitalWrite (latchPinCol, HIGH);
    }delay(timer);
}
}

}
if (j= 14);
{
  for (int i=0; i<50; i++)
  {
for (int j=0; j<8; j++)

{
  byte font = C[j];
  
    byte gndDataFinal = gndData << j; //00000000
    byte RowData=~gndDataFinal;  //11111110
    digitalWrite(latchPinRow, LOW);
    shiftOut(dataPinRow, clockPinRow, MSBFIRST, RowData);
    digitalWrite(latchPinRow,HIGH);
   
    {
      digitalWrite (latchPinCol, LOW);
      shiftOut(dataPinCol, clockPinCol, MSBFIRST, font);
      digitalWrite (latchPinCol, HIGH);
    }delay(timer);
}
}
}
if (j=22);
{
  
  for (int i=0; i<50; i++)
  {
for (int j=0; j<8; j++)

{
  byte font = D[j];
  
    byte gndDataFinal = gndData << j; //00000000
    byte RowData=~gndDataFinal;  //11111110
    digitalWrite(latchPinRow, LOW);
    shiftOut(dataPinRow, clockPinRow, MSBFIRST, RowData);
    digitalWrite(latchPinRow,HIGH);
   
    {
      digitalWrite (latchPinCol, LOW);
      shiftOut(dataPinCol, clockPinCol, MSBFIRST, font);
      digitalWrite (latchPinCol, HIGH);
    }delay(timer);
}
}
}
if (j=30);
{
  for (int i=0; i<5; i++)
  {
for (int j=0; j<8; j++)

{
  byte font = E[j];
  
    byte gndDataFinal = gndData << j; //00000000
    byte RowData=~gndDataFinal;  //11111110
    digitalWrite(latchPinRow, LOW);
    shiftOut(dataPinRow, clockPinRow, MSBFIRST, RowData);
    digitalWrite(latchPinRow,HIGH);
   
    {
      digitalWrite (latchPinCol, LOW);
      shiftOut(dataPinCol, clockPinCol, MSBFIRST, font);
      digitalWrite (latchPinCol, HIGH);
    }delay(timer);
}
}
}
if (j=38);
{
   for (int i=0; i<5; i++)
  {
for (int j=0; j<8; j++)

{
  byte font = F[j];
  
    byte gndDataFinal = gndData << j; //00000000
    byte RowData=~gndDataFinal;  //11111110
    digitalWrite(latchPinRow, LOW);
    shiftOut(dataPinRow, clockPinRow, MSBFIRST, RowData);
    digitalWrite(latchPinRow,HIGH);
   
    {
      digitalWrite (latchPinCol, LOW);
      shiftOut(dataPinCol, clockPinCol, MSBFIRST, font);
      digitalWrite (latchPinCol, HIGH);
    }delay(timer);
}
}
}
if (j=48);
{
   for (int i=0; i<50; i++)
  {
for (int j=0; j<8; j++)

{
  byte font = G[j];
  
    byte gndDataFinal = gndData << j; //00000000
    byte RowData=~gndDataFinal;  //11111110
    digitalWrite(latchPinRow, LOW);
    shiftOut(dataPinRow, clockPinRow, MSBFIRST, RowData);
    digitalWrite(latchPinRow,HIGH);
   
    {
      digitalWrite (latchPinCol, LOW);
      shiftOut(dataPinCol, clockPinCol, MSBFIRST, font);
      digitalWrite (latchPinCol, HIGH);
    }delay(timer);
}
  }
}
if (j=56);
{
  for (int i=0; i<50; i++)
  {
for (int j=0; j<8; j++)

{
  byte font = H[j];
  
    byte gndDataFinal = gndData << j; //00000000
    byte RowData=~gndDataFinal;  //11111110
    digitalWrite(latchPinRow, LOW);
    shiftOut(dataPinRow, clockPinRow, MSBFIRST, RowData);
    digitalWrite(latchPinRow,HIGH);
   
    {
      digitalWrite (latchPinCol, LOW);
      shiftOut(dataPinCol, clockPinCol, MSBFIRST, font);
      digitalWrite (latchPinCol, HIGH);
    }delay(timer);
}
}
}
if (j=64);
{
  for (int i=0; i<50; i++)
  {
for (int j=0; j<8; j++)

{
  byte font = I[j];
  
    byte gndDataFinal = gndData << j; //00000000
    byte RowData=~gndDataFinal;  //11111110
    digitalWrite(latchPinRow, LOW);
    shiftOut(dataPinRow, clockPinRow, MSBFIRST, RowData);
    digitalWrite(latchPinRow,HIGH);
   
    {
      digitalWrite (latchPinCol, LOW);
      shiftOut(dataPinCol, clockPinCol, MSBFIRST, font);
      digitalWrite (latchPinCol, HIGH);
    }delay(timer);
}
}
}
}
