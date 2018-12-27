// ******************************************************************* 
// This File will be used for basic motor control for basic movement.*
// Such as yaw, roll, , position, and pitch of the drone.            *
// *******************************************************************

// Used to hover in air.
void hover()
{
   for(int i = 2300; i > 1600; i -= 1)  // goes from 2300 degrees to 1600 degrees in steps of 1 degree  
  {
    throttle--;                                  
    motor_1.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_2.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_3.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_4.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    delay(15);                       
    Serial.println(throttle);// waits 15ms for the servo to reach the position 
  }
}
// Used to increase the drone's altitude.
void increaseAltitude()
{
  for(int i = 900; i < 2300; i += 1)  // goes from 0 degrees to 2300 degrees in steps of 1 degree  
  {                         
    throttle++;         
    motor_1.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_2.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_3.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_4.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    delay(15);       
    Serial.println(throttle); // waits 15ms for the servo to reach the position 
  }
}

// Used to decrease the drone's altitude.
void decreaseAltitude()
{
  for(int i = 2300; i > 900; i -= 1)  // goes from 2300 degrees to 900 degrees in steps of 1 degree  
  {
    throttle--;                                  
    motor_1.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_2.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_3.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_4.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    delay(15);                       
    Serial.println(throttle);// waits 15ms for the servo to reach the position 
  }
}
