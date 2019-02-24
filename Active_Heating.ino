//Heater variables
int turnOnTemp = 0;               //temperature below which heater should turn on (in degrees C)
int turnOffTemp = 1;              //temperature above which heater should turn off (in degrees C)
bool heaterOn; 

void heat(){
  if(getBatteryTemp() < turnOnTemp) {          //turn on heater if too cold
    //Serial.println(String(loopCount) + "," + " Active heating: turning ON");
    batHeatRelay.openRelay();}
  else if(getBatteryTemp() > turnOffTemp) {       //turn off heater if warm enough
    //Serial.println(String(loopCount) + "," + " Active heating: turning OFF");
    batHeatRelay.closeRelay();}
  else {                                        //leave heater status unchanged
    //Serial.println(String(loopCount) + "," + " Active heating: no change needed");
  }
}
