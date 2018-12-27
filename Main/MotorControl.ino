// ******************************************************************* 
// This File will be used for basic motor control for basic movement.*
// Such as yaw, roll, , position, and pitch of the drone.            *
// *******************************************************************
#include <Servo.h>

Servo motor_1; // Used to communicate values to the esc analog pin connected to motor 1.
Servo motor_2; // Used to communicate values to the esc analog pin connected to motor 2.
Servo motor_3; // Used to communicate values to the esc analog pin connected to motor 3.
Servo motor_4; // Used to communicate values to the esc analog pin connected to motor 4.
int throttle = 900; // Used to control the throttle speed of the motor.

void setup() 
{
  motor_1.attach(9); // Declares the pin of the first esc. 
  motor_2.attach(10); // Declares the pin of the second esc.
  motor_3.attach(11); // Declares the pin of the third esc.
  motor_4.attach(12); // Declares the pin of the fourth esc.  
  Serial.begin(9600);
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
void decreaseAltitude()
{
  for(int i = 2300; i > 900; i -= 1)  // goes from 2300 degrees to 0 degrees in steps of 1 degree  
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
