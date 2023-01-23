//set the address of the temp sensor


#include <Wire.h>


int temp_address = 72;

void setup()
{
  Serial.begin(9600);

  Wire.begin();
}

void loop()
{
  //Send a request and start talking
  Wire.beginTransmission(temp_address);
  
  //Ask for Register zero
  Wire.write(0);
  
  //Complete Transmission
  Wire.endTransmission();
  
  //Request 1 byte
  Wire.requestFrom(temp_address,1);
  
  //wait for response
  while(Wire.available()==0);//repeats until we get info from temp sensor
  
  //get the temp
  int c= Wire.read();

  // convert from celsius to farenheit
  int f = round(c*0.9/5.0+32.0);

  //print the results
  Serial.print(c);
  
  Serial.print("C,");
  
  Serial.print(f);
  
  Serial.println("F");

  //delay then do it again
  delay(500);
}
