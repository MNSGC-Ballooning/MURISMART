

void Release(){
  for(int angle = 170; angle>=0; angle-=5)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo.write(angle);              //command to rotate the servo to the specified angle
    delay(10);                       
  } 
}


