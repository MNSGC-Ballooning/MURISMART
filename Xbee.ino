
void CheckCut(){
  while(Serial.available()>0)
  if (Serial.read()=='B')
  {smart.release();
  delay(100);
   while (true)
  {Serial.print('X');
  }
  }

}


void beacon() {
  if (millis()-beaconTimer>4000 && !TempSend){
  Serial.print('F');
  beaconTimer=millis();}
}


void Temperature() {
while(Serial.available()>0){
if (Serial.read()=='P'){
    Serial.print('C');
    TempString=DallasTemp();
    TempSend=true;
    TempIndex=0;
   
}
}
if (TempSend){
  

  if(TempIndex<TempString.length()){  
 
     TempChar=TempString.charAt(TempIndex);
     Serial.print(TempChar);
     TempIndex++;
}

  else{
    TempSend=false;
    Serial.print('V');
  }
  
}
}
   

 /* if (Serial.read()=='P'){
    
    Serial.print('C');
    Serial.print('C');
    //TempString=String(DallasTemp());
    TempString="hello";
    TempIndex=0;
  //  delay(20);
    while (TempIndex<TempString.length())
    {TempChar=TempString.charAt(TempIndex);
      Serial.print(TempChar);
      TempIndex++;
     // delay(10);
    }
  //delay(10);
  Serial.print('V');
  Serial.print('V');
 // Serial.print('V');
    }
    }
    
}*/



