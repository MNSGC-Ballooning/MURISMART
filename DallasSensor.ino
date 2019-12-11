OneWire oneWire = OneWire(oneWireBus);                    //set up a oneWire bus
DallasTemperature sensorT = DallasTemperature(&oneWire);
DeviceAddress thermometer;
float Temp;
String TempS;
//static String HeatStatus="N";
void DallasSetup(){

  sensorT.begin(); //starts temp sensor
  sensorT.getAddress(thermometer,0);
  sensorT.setResolution(thermometer,9);

}

String DallasTemp(){
  sensorT.requestTemperatures();   
  Temp = sensorT.getTempC(thermometer); 
  TempS=String(Temp);
  return TempS; //creates string DallasTemp, tells temp (duh?)
}
/*
void ActiveHeating(){

  if (Temp<10.0){
    HeatRelay.setState(1);
    HeatStatus="H";
  }
  if (Temp>16.0){
    HeatRelay.setState(0);  
    HeatStatus="N"; 
  }
}
*/
