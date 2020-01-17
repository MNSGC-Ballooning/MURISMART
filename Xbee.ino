
void CheckCut(){

  if (Check==CheckCuts) //if CheckCuts is called by 'A' or 'B' 
  {  
    Serial.print("Checking cut status! Close to 0 degrees implies full cut, close to 170 implies no cut!");
    Serial.println();

    Serial.print("Angle: ");
    Serial.print(getPos(feedbackPin));
    Serial.println();

    Serial.print("Status: ");
    Serial.print(CutStatus);
    Serial.println();
  }

  if (Check==CutRequest)
  {
    Serial.print("Releasing...");
    Serial.println();
    Release();                    //releases  
    Serial.print("Final angle: ");
    Serial.print(getPos(feedbackPin));
    Serial.println();

    if(abs(getPos(feedbackPin))>15)
    {
      Serial.print("You may not be fully released. Perhaps try again?");
      Serial.println();
    }
    else{
      Serial.print("Successfully released! But maybe still double check.");
      Serial.println();
      CutConfirmTimer=millis();
    }
  }
}

void Temperature() {

if (Check==StatusRequest){        // Temp requested by 'E' or 'F'
    Serial.print(StatusStart);                 //print 'Start'
    TempString= "Temp = "+ DallasTemp()+" C, cut status: " + CutStatus;   //TempString becomes Temperature: F (if still in flight) or R (if releases)
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
    Serial.println();
  }
  
}
}
