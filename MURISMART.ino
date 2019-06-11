#include "src\Smart.h"
#include <DallasTemperature.h>

#define smartPin 4
#define oneWireBus 2
#define batteryTempPin A1
#define heatOn 8
#define heatOff 9

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


Smart smart = Smart(smartPin);

////////////////Relay class////////////////
//Class Declaration
class Relay {
  protected:
    bool isOpen;
    int onPin;
    int offPin;
  public:
    Relay(int on, int off);
    const char* getRelayStatus();
    void init();
    void openRelay();
    void closeRelay();
};

//Make Relay Object
Relay batHeatRelay(heatOn,heatOff);

void setup() {
  smart.initialize();
  DallasSetup();
  Serial.begin(9600);
}

void loop() {
<<<<<<< HEAD
if (Serial.available()>0)
 {Check=Serial.read();}
=======
heat();
beacon();
 while(Serial.available()>0)
  {Check=Serial.read();}
>>>>>>> 4f57ed3b7b9738aaea50b628e61d3e31a416956f
Temperature();
CheckCut();
if (TempSend){
Serial.print('/');
Sending=true;
}
Check='0'; //Zero
}

  

