// ******************************************************************* 
// This File will be used for basic motor control for basic movement.*
// Such as yaw, roll, , position, and pitch of the drone.            *
// *******************************************************************

// Used to hover in air.
void hover()
{
   for(throttle; throttle > 1600; throttle -= 1)  // goes from current speed to 1600 degrees in steps of 1 degree  
  {                             
    motor_1.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_2.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_3.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_4.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle'                     
    Serial.println(throttle);// waits 15ms for the servo to reach the position 
  }
}
// Used to increase the drone's altitude.
void increaseAltitude()
{
  for(throttle; throttle < 2300; throttle += 1)  // goes from current speed to 2300 degrees in steps of 1 degree  
  {                         
    throttle++;         
    motor_1.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_2.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_3.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_4.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle'     
    Serial.println(throttle); // waits 15ms for the servo to reach the position 
  }
}

// Used to decrease the drone's altitude.
void decreaseAltitude()
{
  for(throttle; throttle > 1300; throttle -= 1)  // goes from current speed to 900 degrees in steps of 1 degree  
  {                                  
    motor_1.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_2.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_3.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_4.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle'                      
    Serial.println(throttle);// waits 15ms for the servo to reach the position 
  }
}

// Turns the motors off
void motorsOff()
{
   for(throttle; throttle > 900; throttle -= 1)  // goes from current speed to 900 degrees in steps of 1 degree  
  {                                  
    motor_1.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_2.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_3.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle' 
    motor_4.writeMicroseconds(throttle); // tell motor to go to position in variable 'throttle'                        
    Serial.println(throttle);// waits 15ms for the servo to reach the position 
  }
}
