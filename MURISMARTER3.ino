#include <Servo.h>              //Servo library
#include <DallasTemperature.h>  //Dallas Temp Sensor library

#define smartPin 9      // servo attachment pin
#define oneWireBus 27 
#define feedbackPin A0

OneWire oneWire = OneWire(oneWireBus);                  
DallasTemperature sensorT = DallasTemperature(&oneWire);
DeviceAddress thermometer;
Servo servo;

//UNCMOMMENT FOR UNIT A

const char CutRequest='A';
const char CheckCuts = 'C';
const char StatusRequest='E';
const String StatusStart="Status A: ";       


//UNCOMMENT FOR UNIT B
/*
const char CutRequest='B';
const char CheckCuts = 'D';
const char StatusRequest='F';
const char StatusStart='H';
const char StatusEnd='J'; 
*/

 
const unsigned long MasterTime=16200000;   //ms, will cut after 4.5 hours total ((16200000))
const unsigned long DisconnectTime=600000; //ms, will cut after 10 minutes disconnected ((600000))
static unsigned long DisconnectTimer=0;

bool go=true;
bool TempSend=false;

char Check;
char CutStatus='F'; //F if still in flight, R if released

String TempString=""; //initializing temperature string
char TempChar;
unsigned int TempIndex=0;
bool Sending=false;

unsigned long CutConfirmTimer=0;  
unsigned long CutSpam=0;

int minDegrees; // servo calibration stuff
int maxDegrees;
int minFeedback;
int maxFeedback;
int requestedAngle;
int tolerance = 1; // max feedback measurement error

void setup() {
  servo.attach(smartPin);
  calibrate(servo, feedbackPin, 0, 170); // calibrates servo for 170 degree rotation
  DallasSetup();          //begins Dallas Temp sensor
  Serial.begin(9600);     //sets serial monitor to 9600 baud
}

void loop() {

if (Serial.available()>0) //checks if serial is working
 {Check=Serial.read();}   //checks serial for input, if you input A, will CheckCut, if you input E, will Temperature

Temperature(); //does the whole temperature thing (see Xbee tab)
CheckCut();    //whole checkcut thing (see Xbee tab)

if (TempSend){
Sending=true; //get rid of sending if status is grouped into temp strings?
}

if (millis()>=MasterTime) //if time goes over master, releases
  {
  doItOnce();
  CutStatus='R';
  }

if ((millis()-DisconnectTimer)>=DisconnectTime) //if time goes over disconnecttime (communications have stopped), releases
{
 doItOnce();
 CutStatus='R';  
}
  
Check='0'; //Zero
}

  
