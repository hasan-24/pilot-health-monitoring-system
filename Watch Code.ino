//Watch
#include <math.h> 
#include <SPI.h>  
#include "RF24.h"
#include <Arduino.h>
#include <Wire.h>
#include <BMP180I2C.h>
#define I2C_ADDRESS 0x77

const int xpin = A1;                  // x-axis
const int ypin = A2;                  // y-axis

BMP180I2C bmp180(I2C_ADDRESS);

RF24 myRadio (7, 8);
byte addresses[][6] = {"0"};

struct package
{
  int X = 0;
  int Y = 0;
  float Z = 0;
};


typedef struct package Package;
Package data;


void setup()
{
  Serial.begin(9600);
  while (!Serial);
  Wire.begin();
  if (!bmp180.begin())
  {
    while (1);
  }
  bmp180.resetToDefaults();
  bmp180.setSamplingMode(BMP180MI::MODE_UHR);
  }
  myRadio.begin();  
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS ) ; 
  myRadio.openWritingPipe( addresses[0]);
  delay(1000);
}

void loop()
{

  data.X = analogRead(xpin);
  data.Y = analogRead(ypin);
  data.Z = temp;

  Serial.print("Pilot Status: ");
  Serial.println(temp);
  Serial.print("Stress Level: ");
  Serial.println(temp);
  Serial.print("Active Time: ");
  Serial.println(temp);
  Serial.print("Heart Rate: ");
  Serial.println(temp);
  Serial.print("Oxygen Level: ");
  Serial.println(temp);
  Serial.print("Body Temperature: ");
  Serial.println(temp);
  Serial.print("Moisture Level: ");
  Serial.println(temp);
  Serial.print("Air Pressure: ");
  Serial.println(temp);
  Serial.print("Altitude: ");
  Serial.println(temp);
  Serial.print("Movement-X: ");
  Serial.println(analogRead(xpin));
  Serial.print("Movement-Y: ");
  Serial.println(analogRead(ypin));
  ///////////////////////////////////
  Serial.println();
  Serial.print("\nPackage:");
  delay(500);

}
