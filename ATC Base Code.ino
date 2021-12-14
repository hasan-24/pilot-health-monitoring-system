//ATC Code
#include <LiquidCrystal.h>
#include <SPI.h>  
#include "RF24.h"
#include <SoftwareSerial.h>

SoftwareSerial BTserial(0, 1); // RX | TX 

const int rs = 9, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

RF24 myRadio (7, 8); 
struct package
{
  int A=0;
  float B=0;
  float C=0;
  float D=0;
  float E=0;
  float F=0;
  float G=0;
  float H=0;
  float I=0;
};

byte addresses[][16] = {"0"}; 



typedef struct package Package;
Package data;

void setup() 
{ 
  lcd.begin(20, 4);
  lcd.print("Pilot Health Monitor");
  //Serial.begin(9600);
  BTserial.begin(9600);
  myRadio.begin(); 
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS ) ; 
  myRadio.openReadingPipe(1, addresses[0]);
  myRadio.startListening();
}


void loop()  
{
  if ( myRadio.available()) 
  {
    lcd.setCursor(0, 1);
    lcd.print("Connected: Band 1");
    
    while (myRadio.available())
    {
      myRadio.read( &data, sizeof(data) );
    }
    lcd.setCursor(0, 2);
    lcd.print("A:: ");
    lcd.setCursor(6, 2);
    lcd.print(data.A);
    lcd.setCursor(12, 2);
    //lcd.print("F");
    
    lcd.setCursor(0, 3);
    lcd.print("B,C: ");
    lcd.setCursor(10, 3);
    lcd.print(data.B);
    lcd.setCursor(13, 3);
    lcd.print(", ");
    lcd.setCursor(15, 3);
    lcd.print(data.C);
    
    BTserial.print(millis() / 1000);   //1- active time
    BTserial.print(",");
    BTserial.print(data.B);   //2- heartrate
    BTserial.print(",");
    BTserial.print(data.C);   //3- oxygen level
    BTserial.print(",");
    BTserial.print(data.D);   //4- temperature
    BTserial.print(",");
    BTserial.print(data.E);   //5- moisture
    BTserial.print(",");
    BTserial.print(data.F);   //6- pressure
    BTserial.print(",");
    BTserial.print(data.G);   //7- altitude
    BTserial.print(",");
    BTserial.print(data.H);   //8- movement-X
    BTserial.print(",");
    BTserial.print(data.I);   //9- movement-Y */
    delay(5000);
    
    //Serial.print("\nPackage:");
    //Serial.print(data.X);
    //Serial.print("\n");
    //Serial.println(data.Y);
  }
}
