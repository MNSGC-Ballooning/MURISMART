#include "src\Smart.h"
#include <DallasTemperature.h>

#define smartPin 4
#define oneWireBus 2
#define twoWireBus 5
#define batteryTempPin A1
#define BatHeat_ON 6 
#define BatHeat_OFF 7

//UNCMOMMENT FOR A
/*
const char CutRequest='A';
const char CutConfirm='Z';
const char CutAcknowledge='a';
const char TempRequest='O';
const char TempStart='T';
const char TempEnd='Y'; 
*/

//UNCOMMENT FOR B

const char CutRequest='B';
const char CutConfirm='X';
const char CutAcknowledge='b';
const char TempRequest='P';
const char TempStart='C';
const char TempEnd='V'; 

//Initializing Latch Relays
LatchRelay BatHeat(BatHeat_ON,BatHeat_OFF)
 

boolean released=false;
bool spam=true;

String TempString="";
char TempChar;
char Check;
unsigned int TempIndex=0;
boolean TempSend=false;
boolean Sending=false;

unsigned long CutConfirmTimer=0;
unsigned long CutSpam=0;

float t_low = 283;
float t_high = 289;
boolean coldBattery = false;


Smart smart = Smart(smartPin);



void setup() {
  smart.initialize();

  BatHeat.init(false);
  
  DallasSetup();
  
  Serial.begin(9600);
  
}

void loop() {

if (Serial.available()>0)
 {Check=Serial.read();}


Temperature();
CheckCut();
if (TempSend){
Serial.print('/');
Sending=true;
}
Check='0'; //Zero
}

  
