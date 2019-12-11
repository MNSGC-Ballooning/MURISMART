

void Release(){

  //
  // New init:
  //
  
  int prevAngle = 175;

  for(int angle = 170; angle>=0; angle-=5)     // command to move from 170 degrees to 0 degrees 
  {                                
    //
    // pretty much everything in here is new
    //

    
    calibrate(servo, feedbackPin, angle, prevAngle); // calibrates the servo between current and previous requested angle
                                                       // does so by moving servo, so write command unnecessary
    Serial.print("Requested angle: ");
    Serial.print(angle);
    Serial.println();
    Serial.print("Actual angle: ");
    Serial.print(getPos(feedbackPin));
    Serial.println();

    prevAngle = angle;

        
    
    delay(10);                       // executes command every 10 milliseconds
  } 
  
}

//
// Two new functions added below:
//

void calibrate(Servo servo, int analogPin, int minPos, int maxPos)
{
  // Move to the minimum position and record the feedback value
  servo.write(minPos);
  minDegrees = minPos;
  delay(100); // make sure it has time to get there and settle
  minFeedback = analogRead(analogPin);
  
  // Move to the maximum position and record the feedback value
  servo.write(maxPos);
  maxDegrees = maxPos;
  delay(100); // make sure it has time to get there and settle
  maxFeedback = analogRead(analogPin);
}

int getPos(int analogPin)
{
  return map(analogRead(analogPin), minFeedback, maxFeedback, minDegrees, maxDegrees);
}
