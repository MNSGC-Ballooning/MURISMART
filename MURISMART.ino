#include "src\Smart.h"
#include <DallasTemperature.h>

#define smartPin 5
#define oneWireBus 2
#define batteryTempPin A1
#define heatOn 8
#define heatOff 9



boolean released=false;

String TempString="";
char TempChar;
char Check;
unsigned int TempIndex=0;
boolean TempSend=false;


unsigned long beaconTimer=0;
unsigned long tempTimer=0;

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
heat();
beacon();
 while(Serial.available()>0)
  {Check=Serial.read();}
Temperature();
CheckCut();
Check='y';
Serial.print('/');  //Differentiate between characters
}

  

