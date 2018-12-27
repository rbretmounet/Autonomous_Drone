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
void updateDistance();
void motorsOff();
void plotCourse();

Servo motor_1; // Used to communicate values to the esc analog pin connected to motor 1.
Servo motor_2; // Used to communicate values to the esc analog pin connected to motor 2.
Servo motor_3; // Used to communicate values to the esc analog pin connected to motor 3.
Servo motor_4; // Used to communicate values to the esc analog pin connected to motor 4.
SoftwareSerial gpsSerial(4,3); // Declares pin used to print out gps data.
TinyGPSPlus gps; // Declares a gps object.
float homeLattitude,homeLongitude,homeAltitude,currentLattitude, currentLongitude, currentAltitude, 
      destinationLattitude, destinationLongitude, destinationAltitude, doubleAltitude; // Used to store data from gps.
unsigned long Distance_To_Destination, Course_To_Destination; // Used to store the distance from the final destination
int throttle = 900; // Used to control the throttle speed of the motor.
int courseChangeNeeded; // Used to store the amount of degegrees needed to correct course.

void setup() 
{
  motor_1.attach(9); // Declares the pin of the first esc. 
  motor_2.attach(10); // Declares the pin of the second esc.
  motor_3.attach(11); // Declares the pin of the third esc.
  motor_4.attach(12); // Declares the pin of the fourth esc.  
  Serial.begin(9600);
  gpsSerial.begin(9600);
  // Makes sure the value is set to the true number.
  /*while (homeLattitude == 0 && homeLongitude == 0 && homeAltitude == 0)
  {
    setHome();
    Serial.println(homeAltitude);
  }*/
  setDestination(259.2, 38.088646, -122.158883);
}

void loop()
{
   // Makes sure that the gps gets a lat and long before starting the logic.
  while(currentLattitude == 0 || currentLongitude == 0 || currentAltitude == 0)
  {
    getData();
    updateDistance();
    plotCourse();
    printData();
  }
  // Updates the current lat and long.
  if(currentLattitude != 0 || currentLongitude != 0)
  {
    getData();
    updateDistance();
    plotCourse();
    printData();
  }
  doubleAltitude = (homeAltitude*2);
  // When the drone reaches the destination.
  if(Distance_To_Destination < 10)
  {
    // Stop the drone in the air and hover.
    hover();

    // Decrease altitude until the drones altitude is equal to the destination altitude.
    while(currentAltitude > destinationAltitude)
    {
      decreaseAltitude;
      if(currentAltitude == destinationAltitude)
      {
        motorsOff();
      }
    }
  }
  // Otherwise it means that the drone isnt at the final destination.
  else
  {
    // Increase the altitude until the drones altitude is 2 times higher.
    while(currentAltitude < doubleAltitude)
    {
      increaseAltitude();
    }
    hover();
  }
}
