//#include "src\Smart.h"
//#include "src\LatchRelay.h"


//
//   HEY NATHAN NEW ADDITIONS ARE LABELED LIKE THIS
//

#include <Servo.h>              //Servo library
#include <DallasTemperature.h>  //Dallas Temp Sensor library

#define smartPin 4      //
#define oneWireBus 2    //
#define HeatOnPin 7     //assuming temp sensor is on pins 6 and 7
#define HeatOffPin 6
#define feedbackPin A0



//UNCMOMMENT FOR A

const char CutRequest='A';
const char CutConfirm='Z';
const char CutAcknowledge='a';
const char TempRequest='O';
const char TempStart='T';
const char TempEnd='Y';        //sets char values for SMART A


//UNCOMMENT FOR B
/*
const char CutRequest='B';
const char CutConfirm='X';
const char CutAcknowledge='b';
const char TempRequest='P';
const char TempStart='C';
const char TempEnd='V'; 
*/

 
const unsigned long MasterTime=16200000;   //ms, will cut after 4.5 hours total
const unsigned long DisconnectTime=600000; //ms, will cut after 10 minutes disconnected
static unsigned long DisconnectTimer=0;



boolean released=false; //initializing booleans
bool spam=true;

String TempString=""; //initializing temperature string
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

//
// New initializations:
//

int minDegrees;
int maxDegrees;
int minFeedback;
int maxFeedback;
int tolerance = 1; // max feedback measurement error

void setup() {
  servo.attach(smartPin); //servo is attached at pin 4
  servo.write(170);       //rotate 170 degrees
  DallasSetup();          //begins Dallas Temp sensor
  Serial.begin(9600);     //sets serial monitor to 9600 baud
  //HeatRelay.init(0);    //FOR ACTIVE HEATER

}

void loop() {

if (Serial.available()>0) //checks if serial is working
 {Check=Serial.read();}   

Temperature(); //does the whole temperature thing (see Xbee tab)
CheckCut();    //whole checkcut thing (see Xbee tab)

if (TempSend){
Serial.print('/');
Sending=true; //[[get rid of sending if status is grouped into temp strings?]] not my note
}


//ACTIVE HEATER STUFF
/*
if (millis()-HeatTimer>1000){
  HeatTimer=millis();
  ActiveHeating();
}
*/
if (millis()>=MasterTime) //if time goes over master, releases
  {Release();
  CutStatus='R';
  }

if ((millis()-DisconnectTimer)>=DisconnectTime) //if time goes over disconnecttime (communications have stopped), releases
{Release();
 CutStatus='R';  
}
  
Check='0'; //Zero
}

  
