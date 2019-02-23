#include "src\Smart.h"
#include <DallasTemperature.h>

#define smartPin 5
#define oneWireBus 2




boolean released=false;

String TempString="";
char TempChar;
char Check;
unsigned int TempIndex=0;
boolean TempSend=false;


unsigned long beaconTimer=0;
unsigned long tempTimer=0;

Smart smart = Smart(smartPin);

void setup() {
  smart.initialize();
  DallasSetup();
  Serial.begin(9600);
}

void loop() {
beacon();
 while(Serial.available()>0)
  {Check=Serial.read();}
Temperature();
CheckCut();
Check='y';
Serial.print('/');  //Differentiate between characters
}

  

