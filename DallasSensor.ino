float Temp;
String TempS;

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
