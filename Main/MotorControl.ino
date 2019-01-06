// ******************************************************************* 
// This File will be used for basic motor control for basic movement.*
// Such as yaw, roll, , position, and pitch of the drone.            *
// *******************************************************************

// Used to set the throttle variables to lowest possible speed.
void arm()
{
  throttle_1 = 1039;
  throttle_2 = 1039;
  throttle_3 = 1039;
  throttle_4 = 1039;
  motor_1.writeMicroseconds(throttle_1); // tell motor to go to position in variable 'throttle' 
  motor_2.writeMicroseconds(throttle_2); // tell motor to go to position in variable 'throttle' 
  motor_3.writeMicroseconds(throttle_3); // tell motor to go to position in variable 'throttle' 
  motor_4.writeMicroseconds(throttle_4); // tell motor to go to position in variable 'throttle'
}
// Used to make the pitch go forward.
void pitchForward()
{
  
}

// Used to make the pitch go backwards.
void pitchBackward()
{
  
}

// Used to make the drone yaw right.
void yawRight()
{
  
}

// Used to make the drone yaw left.
void yawLeft(int throttle)
{
 
}

// Used to make the drone roll right.
void rollRight()
{
  // While the drone is not at a 45 degree angle to the right.
    getGyroData();
    printGyroData();
    throttle_1++; // Increases the power of the left side.
    throttle_3++; // Increases the power of the left side.
    throttle_2--; // Decreases the power of the right side.
    throttle_4--; // Decreases the power of the right side.
    motor_1.writeMicroseconds(throttle_1); // tell motor to go to position in variable 'throttle' 
    motor_2.writeMicroseconds(throttle_2); // tell motor to go to position in variable 'throttle' 
    motor_3.writeMicroseconds(throttle_3); // tell motor to go to position in variable 'throttle' 
    motor_4.writeMicroseconds(throttle_4); // tell motor to go to position in variable 'throttle'    
    Serial.println(throttle_1); 
    Serial.println(throttle_2);  
    Serial.println(throttle_3);  
    Serial.println(throttle_4);     
}

// Used to make the drone roll left.
void rollLeft()
{
  // While the drone is not at a 45 degree angle to the left.
    getGyroData();
    printGyroData();
    if(throttle_1 > 1200)
    {
      throttle_1--; // Decreases the power of the left side.
    }
    if(throttle_3 > 1200)
    {
      throttle_3--; // Decreases the power of the left side.
    }
    throttle_2++; // Increases the power of the right side.
    throttle_4++; // Increases the power of the right side.
    motor_1.writeMicroseconds(throttle_1); // tell motor to go to position in variable 'throttle' 
    motor_2.writeMicroseconds(throttle_2); // tell motor to go to position in variable 'throttle' 
    motor_3.writeMicroseconds(throttle_3); // tell motor to go to position in variable 'throttle' 
    motor_4.writeMicroseconds(throttle_4); // tell motor to go to position in variable 'throttle'  
    Serial.println(throttle_1); 
    Serial.println(throttle_2);  
    Serial.println(throttle_3);  
    Serial.println(throttle_4);    
}

// Used to hover in air.
void hover()
{
  throttle_1 = 1600;
  throttle_2 = 1600;
  throttle_3 = 1600;
  throttle_4 = 1600;
  motor_1.writeMicroseconds(throttle_1); // tell motor to go to position in variable 'throttle' 
  motor_2.writeMicroseconds(throttle_2); // tell motor to go to position in variable 'throttle' 
  motor_3.writeMicroseconds(throttle_3); // tell motor to go to position in variable 'throttle' 
  motor_4.writeMicroseconds(throttle_4); // tell motor to go to position in variable 'throttle'
  if(angleY > 0)
  {
    while(angleY > 0)
    {
      rollLeft();
    }
  }
  if(angleY < 0)
  {
    while(angleY < 0)
    {
      rollRight();
    }
  }
  if(angleX > 0)
  {
    while(angleX > 0)
    {
      pitchBackward();
    }
  }
  if(angleX < 0)
  {
    while(angleX < 0)
    {
      pitchForward();
    }
  }
  
}
// Used to increase the drone's altitude.
void increaseAltitude()
{
    throttle_1++; // Increases the throttle of motor_1;
    throttle_2++; // Increases the throttle of motor_2;
    throttle_3++; // Increases the throttle of motor_3; 
    throttle_4++;// Increases the throttle of motor_4;
    motor_1.writeMicroseconds(throttle_1); // tell motor to go to position in variable 'throttle' 
    motor_2.writeMicroseconds(throttle_2); // tell motor to go to position in variable 'throttle' 
    motor_3.writeMicroseconds(throttle_3); // tell motor to go to position in variable 'throttle' 
    motor_4.writeMicroseconds(throttle_4); // tell motor to go to position in variable 'throttle'  
    Serial.println(throttle_1); 
    Serial.println(throttle_2);  
    Serial.println(throttle_3);  
    Serial.println(throttle_4);    
}
    

// Used to decrease the drone's altitude.
void decreaseAltitude()
{
   // Makes sure the motor doesnt turn off.
   if(throttle_1 > 1200 || throttle_2 > 1200 || throttle_3 > 1200 || throttle_4 > 1200)
   {
    throttle_1--; // Decrease the throttle of motor_1;
    throttle_2--; // Decrease the throttle of motor_2;
    throttle_3--; // Decrease the throttle of motor_3;
    throttle_4--; // Decrease the throttle of motor_4;
   }
    motor_1.writeMicroseconds(throttle_1); // tell motor to go to position in variable 'throttle' 
    motor_2.writeMicroseconds(throttle_2); // tell motor to go to position in variable 'throttle' 
    motor_3.writeMicroseconds(throttle_3); // tell motor to go to position in variable 'throttle' 
    motor_4.writeMicroseconds(throttle_4); // tell motor to go to position in variable 'throttle'  
    Serial.println(throttle_1); 
    Serial.println(throttle_2);  
    Serial.println(throttle_3);  
    Serial.println(throttle_4);    
}

// Turns the motors off
void motorsOff()
{
  // Makes sure throttle variable doesn go under 1100.
    throttle_1 = 1039;
    throttle_2 = 1039;
    throttle_3 = 1039;
    throttle_4 = 1039;
    motor_1.writeMicroseconds(throttle_1); // tell motor to go to position in variable 'throttle' 
    motor_2.writeMicroseconds(throttle_2); // tell motor to go to position in variable 'throttle' 
    motor_3.writeMicroseconds(throttle_3); // tell motor to go to position in variable 'throttle' 
    motor_4.writeMicroseconds(throttle_4); // tell motor to go to position in variable 'throttle'  
    Serial.println(throttle_1); 
    Serial.println(throttle_2);  
    Serial.println(throttle_3);  
    Serial.println(throttle_4);    
}
