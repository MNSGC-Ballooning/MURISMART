OneWire oneWire = OneWire(oneWireBus);                    //set up a oneWire bus
DallasTemperature sensorT1 = DallasTemperature(&oneWire);
DeviceAddress thermometer1;

OneWire twoWire = OneWire(twoWireBus);                    //set up a twoWire bus
DallasTemperature sensorT2 = DallasTemperature(&twoWire); //use this sensor as the one next to the battery
DeviceAddress thermometer2;
float Temp;


void DallasSetup(){

  sensorT1.begin();
  sensorT1.getAddress(thermometer1,0);          //Garrett, what does the integer that's passed as an argument mean?
  sensorT1.setResolution(thermometer1,9);

  sensorT2.begin();
  sensorT2.getAddress(thermometer2,0);
  sensorT2.setResolution(thermometer2,9);

}

float DallasTemp1(){
  sensorT1.requestTemperatures();   
  Temp = sensorT1.getTempC(thermometer1); 
  return Temp;
}

float DallasTemp2(){
  sensorT2.requestTemperatures();   
  Temp = sensorT2.getTempC(thermometer2); 
  return Temp;
}
