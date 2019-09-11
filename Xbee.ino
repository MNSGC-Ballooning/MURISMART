
void CheckCut(){

  if (Check==CutRequest && spam)
  {Release();
  CutStatus='R';
  //delay(100);
  CutConfirmTimer=millis();
   while (millis()-CutConfirmTimer<=60000 && spam)
  {
    if (Serial.read()!=CutAcknowledge){
      if (millis()-CutSpam>1000){
        //smart.release(); //Just in case
        Serial.print(CutConfirm);
        CutSpam=millis();
      }
    }
    else{
      spam=false;      
    }
  }

  }
}



void Temperature() {


if (Check==TempRequest && !TempSend){
    Serial.print(TempStart);
    TempString=DallasTemp()+":"+CutStatus;
    TempSend=true;
    TempIndex=0;
    DisconnectTimer=millis(); //have recieved a status request, so reset the timer for disconnect cut
   
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


