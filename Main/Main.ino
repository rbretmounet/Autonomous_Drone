// ****************************************************************** 
// Used to link all of the functions and different components of the*
// entire project                                                   *
// ******************************************************************
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Servo.h>

// Function Prototypes
void increaseAltitude();
void decreaseAltitude();
void printData();
void getData();
void hover();
void setHome();
void setDestination(float, float, float);
void updateDistance(float, float, float, float);
void motorsOff();

Servo motor_1; // Used to communicate values to the esc analog pin connected to motor 1.
Servo motor_2; // Used to communicate values to the esc analog pin connected to motor 2.
Servo motor_3; // Used to communicate values to the esc analog pin connected to motor 3.
Servo motor_4; // Used to communicate values to the esc analog pin connected to motor 4.
SoftwareSerial gpsSerial(4,3); // Declares pin used to print out gps data.
TinyGPSPlus gps; // Declares a gps object.
float homeLattitude,homeLongitude,homeAltitude,currentLattitude, currentLongitude, currentAltitude, 
      destinationLattitude, destinationLongitude, destinationAltitude; // Used to store data from gps.
unsigned long Distance_To_Destination; // Used to store the distance from the final destination
int throttle = 900; // Used to control the throttle speed of the motor.


void setup() 
{
  motor_1.attach(9); // Declares the pin of the first esc. 
  motor_2.attach(10); // Declares the pin of the second esc.
  motor_3.attach(11); // Declares the pin of the third esc.
  motor_4.attach(12); // Declares the pin of the fourth esc.  
  Serial.begin(9600);
  gpsSerial.begin(9600);
  setHome();
  setDestination(79.0, 38.088651, -122.158895);
}

void loop()
{
  getData();
  updateDistance(destinationLongitude,destinationLattitude,currentLongitude,currentLattitude);
  printData();
  // When the drone reaches the destination.
  if(Distance_To_Destination == 0)
  {
    // Stop the drone in the air and hover.
    hover();

    // Decrease altitude until the drones altitude is equal to the destination altitude.
    while(currentAltitude != destinationAltitude)
    {
      decreaseAltitude;
      if(currentAltitude == destinationAltitude)
      {
        motorsOff();
      }
    }
  }
  // Increase the altitude until the drones altitude is 2 times higher.
  while(currentAltitude != (currentAltitude*2))
  {
    increaseAltitude();
  }
}
