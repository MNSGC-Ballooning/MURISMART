OneWire oneWire = OneWire(oneWireBus);                    //set up a oneWire bus
DallasTemperature sensorT = DallasTemperature(&oneWire);
DeviceAddress thermometer;
float Temp;


void DallasSetup(){

  sensorT.begin();
  sensorT.getAddress(thermometer,0);
  sensorT.setResolution(thermometer,9);

}

float DallasTemp(){
   sensorT.requestTemperatures();   
  Temp = sensorT.getTempC(thermometer); 
  return Temp;
}

