
void CheckCut(){

  if (Check==CutRequest && spam) //if check has same char as cutrequest and spam is true (should be)
  {Release();                    //releases  
  CutStatus='R';                 //CutStatus becomes released
  //delay(100);
  CutConfirmTimer=millis();      //cutconfirmtimer records time
   while (millis()-CutConfirmTimer<=60000 && spam) //while time - cut time is less than or equal to 1 minute (aka for next minute)
  {
    if (Serial.read()!=CutAcknowledge){  //if cut isn't acknowledged
      if (millis()-CutSpam>1000){ //for the next 1 s
        //smart.release(); //Just in case
        Serial.print(CutConfirm); //show that cut is complete
        CutSpam=millis();         //cutspam becomes this time
      }
    }
    else{
      spam=false;      //otherwise, no more releasing
    }
  }

  }
}



void Temperature() {


if (Check==TempRequest && !TempSend){        //if Check has same char as TempRequest and TempSend is not false (aka true)
    Serial.print(TempStart);                 //print 'T'
    TempString=DallasTemp()+":"+CutStatus;   //TempString becomes Temperature: F (if still in flight) or R (if releases)
    TempSend=true;
    TempIndex=0;
    DisconnectTimer=millis();    //have recieved a status request, so reset the timer for disconnect cut
   
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
