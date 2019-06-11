void actHeat(){
  // Compare digital temp. to critical temp.:  
  if(150 < DallasTemp2() < t_low) {
    coldBattery = true; // if temperature is below low critical temperature
  }
  if(DallasTemp2() > t_high) {
    coldBattery = false; // if temperature is above high critical temperature
  }


//turn heater on/off:
  if(coldBattery && BatHeat.getState()==false){
    BatHeat.setState(true);
  }
  else if(!coldBattery && BatHeat.getState()==true){
    BatHeat.setState(false);
  }
