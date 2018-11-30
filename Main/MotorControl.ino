// ******************************************************************* 
// This File will be used for basic motor control for basic movement.*
// Such as yaw, roll, , position, and pitch of the drone.            *
// *******************************************************************
#include <Servo.h>
// Function prototypes
void upwardMovement(Servo &, Servo &, Servo &, Servo &, int);

Servo motor_1; // Used to communicate values to the esc analog pin connected to motor 1.
Servo motor_2; // Used to communicate values to the esc analog pin connected to motor 2.
Servo motor_3; // Used to communicate values to the esc analog pin connected to motor 3.
Servo motor_4; // Used to communicate values to the esc analog pin connected to motor 4.
int throttle = 0; // Used to control the throttle speed of the motor.

void setup() 
{
  motor_1.attach(9); // Declares the pin of the first esc. 
  motor_2.attach(9); // Declares the pin of the second esc.
  motor_3.attach(9); // Declares the pin of the third esc.
  motor_4.attach(9); // Declares the pin of the fourth esc.  
}

void loop() 
{
  upwardMovement(motor_1,motor_2,motor_3,motor_4,throttle);

}
// Used to increase the drone's altitude.
void upwardMovement (Servo &motor_1, Servo &motor_2, Servo &motor_3, Servo &motor_4, int throttle)
{
  
}

