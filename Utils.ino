//Relay class functions
Relay::Relay(int on,int off)
  : onPin(on)
  , offPin(off)
  , isOpen(false)
  {}
const char* Relay::getRelayStatus(){
  const char _open[] = "ON";
  const char _closed[] = "CLOSED";
  if (isOpen){
    return (_open);
  }
  else {
    return (_closed);
  }
}
void Relay::init(){
  pinMode(onPin,OUTPUT);
  pinMode(offPin,OUTPUT);
  delay(100);
  digitalWrite(offPin,HIGH);
  delay(10);
  digitalWrite(offPin,LOW);
  heaterOn = false;
}
void Relay::openRelay(){
  isOpen = true;
  digitalWrite(onPin,HIGH);
  delay(10);
  digitalWrite(onPin,LOW);
  heaterOn = true;
}
void Relay::closeRelay(){
  isOpen = false;
  digitalWrite(offPin,HIGH);
  delay(10);
  digitalWrite(offPin,LOW);
  heaterOn = false;
}

//function to read the internal temp sensor and return the current temp in C
float getBatteryTemp() {
  return (analogRead(batteryTempPin)*(5.0/1024)-.5)/.01;
}
