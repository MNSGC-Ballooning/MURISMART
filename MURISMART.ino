//#include "src\Smart.h"
//#include "src\LatchRelay.h"

#include <Servo.h>
#include <DallasTemperature.h>

#define smartPin 4
#define oneWireBus 2
#define HeatOnPin 7
#define HeatOffPin 6



//UNCMOMMENT FOR A

const char CutRequest='A';
const char CutConfirm='Z';
const char CutAcknowledge='a';
const char TempRequest='O';
const char TempStart='T';
const char TempEnd='Y'; 


//UNCOMMENT FOR B
/*
const char CutRequest='B';
const char CutConfirm='X';
const char CutAcknowledge='b';
const char TempRequest='P';
const char TempStart='C';
const char TempEnd='V'; 
*/

 
const unsigned long MasterTime=18000000; //ms, will cut after 5 hours
const unsigned long DisconnectTime=600000; //minutes
static unsigned long DisconnectTimer=0;



boolean released=false;
bool spam=true;

String TempString="";
char TempChar;
char Check;
char CutStatus='F'; //F if still in flight, R if released
unsigned int TempIndex=0;
boolean TempSend=false;
boolean Sending=false;

//Heater stuff
unsigned long CutConfirmTimer=0;
unsigned long CutSpam=0;
//unsigned long HeatTimer=0; //FOR ACTIVE HEATER



//LatchRelay HeatRelay=LatchRelay(HeatOnPin, HeatOffPin);
Servo servo;

void setup() {
  servo.attach(smartPin);
  servo.write(170);
  DallasSetup();
  Serial.begin(9600);
  //HeatRelay.init(0);
}

void loop() {

if (Serial.available()>0)
 {Check=Serial.read();}

Temperature();
CheckCut();

if (TempSend){
Serial.print('/');
Sending=true; //get rid of sending if status is grouped into temp strings?
}


//ACTIVE HEATER STUFF
/*
if (millis()-HeatTimer>1000){
  HeatTimer=millis();
  ActiveHeating();
}
*/
if (millis()>=MasterTime)
  {Release();
  CutStatus='R';
  }

if ((millis()-DisconnectTimer)>=DisconnectTime)
{Release();
 CutStatus='R';  
}
  
Check='0'; //Zero
}

  

