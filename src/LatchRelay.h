#ifndef LatchRelay_h
#define LatchRelay_h

#include <Arduino.h>

class LatchRelay {
  public:
    //Constructor
    LatchRelay(byte onPin, byte offPin);
    //Call one of these during setup()
    void init(); //Leave switch in current position
    void init(bool startState); //set switch to a default state
    //Set the relay state using true/false or 1/0
    void setState(bool state);
    //Poll current relay state
    bool getState();
  private:
    //Pins used to control the relay
    byte onPin, offPin;
    //Boolean to track relay state
    bool currentState;
};

#endif