
void CheckCut(){

  if (Check==CutRequest)
  {smart.release();
  delay(100);
  CutConfirmTimer=millis();
   while (millis()-CutConfirmTimer<=60000)
  {
    if (Serial.read()!=CutAcknowledge && spam){
      if (millis()-CutSpam>1000){
        Serial.print(CutConfirm);
        CutSpam=millis();
      }
    }
    else{
      spam=false;      
    }
  }
  while(true)
  {
    smart.release(); //Otherwise will reset, and could
    //chillax,good job
  }
  
  }
}



void Temperature() {

<<<<<<< HEAD
if (Check==TempRequest && !TempSend){
    Serial.print(TempStart);
    TempString=DallasTemp();
=======
if (Check=='P'){
    Serial.print('C');
    TempString=DallasTemp()+','+ getBatteryTemp();
>>>>>>> 4f57ed3b7b9738aaea50b628e61d3e31a416956f
    TempSend=true;
    TempIndex=0;
   
}

if (Sending){
  

  if(TempIndex<TempString.length()){  
 
     TempChar=TempString.charAt(TempIndex);
     Serial.print(TempChar);
     TempIndex++;
}

  else{
    TempSend=false;
    Sending=false;
    Serial.print(TempEnd);
  }
  
}
}


