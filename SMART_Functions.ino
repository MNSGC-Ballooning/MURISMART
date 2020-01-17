void doItOnce(){
  if (go) {
    Release();
    }
  go=false;
  }

int Release(){
  for(int angle = 170; angle>=0; angle-=5)     // command to move from 170 degrees to 0 degrees 
  {  
      servo.write(angle); 
      delay(100);                       // executes command every 100 milliseconds      
  } 
  CutStatus = 'R';
}

void calibrate(Servo servo, int analogPin, int minPos, int maxPos) //necessary to get accurate feedback
{
  // Move to the minimum position and record the feedback value
  servo.write(minPos);
  minDegrees = minPos;
  delay(2000); // make sure it has time to get there and settle
  minFeedback = analogRead(analogPin);
  
  // Move to the maximum position and record the feedback value
  servo.write(maxPos);
  maxDegrees = maxPos;
  delay(2000); // make sure it has time to get there and settle
  maxFeedback = analogRead(analogPin);
}

int getPos(int analogPin)
{
  return map(analogRead(analogPin), minFeedback, maxFeedback, minDegrees, maxDegrees); // not sure how this works but it returns the angle sooooo we'll take it
}
