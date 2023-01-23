//how to use MAX7219 module with 8x8 LED matrix to display text or any characters on the LED

#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to CS
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime=600;

void setup() {
 
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */
void writeArduinoOnMatrix() {
  /* here is the data for the characters */

  // K
  byte R[8]={B11111100,B10000100,B10000100,B11111000,B10100000,B10010000,B10001000,B10000100};
  byte O[8]={B00011000,B00100100,B01000010,B01000010,B01000010,B01000010,B00100100,B00011000};  
  byte B[8]={B11111100,B10000100,B10000100,B11111000,B10001000,B10000100,B10000100,B11111100};
  byte J[8]={B00011110,B00000100,B00000100,B00000100,B10000100,B10000100,B01000100,B00111000};
  byte A[8]={B00111000,B01000100,B10000010,B11111110,B10000010,B10000010,B10000010,B10000010};     
  byte X[8]={ B10000001,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B10000001};
  byte love[8]={ B00000000,B01100110,B10011001,B10011001,B10000001,B01000010,B00100100,B00011000};  


  /* Letter   */
  for (int i=0; i<8; i++){
  lc.setRow(0,i,R[i]);

  }
   
  delay(delaytime);
  for(int i=0; i<8; i++){
      lc.setRow(0,i,0);// this is for blank
  }  
/////////////// END of Letter///////

  /* Letter   */
  for (int i=0; i<8; i++){
  lc.setRow(0,i,O[i]);

  }
   
  delay(delaytime);
  for(int i=0; i<8; i++){
      lc.setRow(0,i,0);// this is for blank
  }  
/////////////// END of Letter///////


  /* Letter   */
  for (int i=0; i<8; i++){
  lc.setRow(0,i,B[i]);

  }
   
  delay(delaytime);
  for(int i=0; i<8; i++){
      lc.setRow(0,i,0);// this is for blank
  }  
/////////////// END of Letter///////

  /* Letter   */
  for (int i=0; i<8; i++){
  lc.setRow(0,i,O[i]);

  }
   
  delay(delaytime);
  for(int i=0; i<8; i++){
      lc.setRow(0,i,0);// this is for blank
  }  
/////////////// END of Letter J///////

  /* Letter   */
  for (int i=0; i<8; i++){
  lc.setRow(0,i,J[i]);

  }
   
  delay(delaytime);
  for(int i=0; i<8; i++){
      lc.setRow(0,i,0);// this is for blank
  }  
/////////////// END of Letter///////

  /* Letter A  */
  for (int i=0; i<8; i++){
  lc.setRow(0,i,A[i]);

  }
   
  delay(delaytime);
  for(int i=0; i<8; i++){
      lc.setRow(0,i,0);// this is for blank
  }  
/////////////// END of Letter///////

  /* Letter X */
  for (int i=0; i<8; i++){
  lc.setRow(0,i,X[i]);

  }
   
  delay(delaytime);
  for(int i=0; i<8; i++){
      lc.setRow(0,i,0);// this is for blank
  }  
/////////////// END of Letter///////



  /* love */
  for (int i=0; i<8; i++){
  lc.setRow(0,i,love[i]);

  }
   
  delay(delaytime);
  delay(delaytime);
  for(int i=0; i<8; i++){
      lc.setRow(0,i,0);// this is for blank
  }  
/////////////// END of Letter///////

}// writeArduinoOnMatrix()  end


void loop() { 
  writeArduinoOnMatrix();

}
 
