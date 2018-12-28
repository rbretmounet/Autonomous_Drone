// ****************************************************************** 
// Used to link all of the functions and different components of the*
// entire project                                                   *
// ******************************************************************
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#include <MPU6050_tockn.h>
#include <Wire.h>

// Function Prototypes
void increaseAltitude();
void decreaseAltitude();
void printGPSData(); 
void getGPSData();
void hover();
void setHome();
void setDestination(float, float, float);
void updateDistance();
void motorsOff();
void plotCourse();
void printGyroData();
void getGyroData();

Servo motor_1; // Used to communicate values to the esc analog pin connected to motor 1.
Servo motor_2; // Used to communicate values to the esc analog pin connected to motor 2.
Servo motor_3; // Used to communicate values to the esc analog pin connected to motor 3.
Servo motor_4; // Used to communicate values to the esc analog pin connected to motor 4.
SoftwareSerial gpsSerial(4,3); // Declares pin used to print out gps data.
TinyGPSPlus gps; // Declares a gps object.
MPU6050 mpu6050(Wire); // Declares a gyro object
float homeLattitude,homeLongitude,homeAltitude,currentLattitude, currentLongitude, currentAltitude, 
      destinationLattitude, destinationLongitude, destinationAltitude, doubleAltitude; // Used to store data from gps.
float angleX, angleY, angleZ;
unsigned long Distance_To_Destination, Course_To_Destination; // Used to store the distance from the final destination
int throttle = 900; // Used to control the throttle speed of the motor.
int courseChangeNeeded; // Used to store the amount of degrees needed to correct course.
int numberOfSatellites = gps.satellites.value(); // Used to store the amount satellites being used.


void setup() 
{
  motor_1.attach(9); // Declares the pin of the first esc. 
  motor_2.attach(10); // Declares the pin of the second esc.
  motor_3.attach(11); // Declares the pin of the third esc.
  motor_4.attach(12); // Declares the pin of the fourth esc.  
  Serial.begin(9600);
  gpsSerial.begin(9600);
  Wire.begin(9600);
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true); // Calibrates gyroscope.
  // Makes sure the value is set to the true number.
  /*while (homeLattitude == 0 || homeLongitude == 0 || homeAltitude == 0 || numberOfSatellites == 0)
  {
    setHome();
    printGPSData(); 
  }*/
  setDestination(259.2, 38.088646, -122.158883);
}

void loop()
{
  
  // Makes sure that the gps gets a lat and long before starting the logic.
  while(currentLattitude == 0 || currentLongitude == 0 || currentAltitude == 0 || numberOfSatellites == 0)
  {
    getGyroData();
    getGPSData();
    updateDistance();
    plotCourse();
    printGPSData();
    printGyroData(); 
  }
  // Updates the gps data, distance to destination and plots the course from new point and the current Gyro angles.
  if (currentLattitude != 0 || currentLongitude != 0 || currentAltitude != 0 || numberOfSatellites != 0)
  {
    getGyroData();
    getGPSData();
    updateDistance();
    plotCourse();
    printGPSData();
    printGyroData();
  }
  // Used to make the drone go two times the height of the original altitude.
  doubleAltitude = (homeAltitude*2);
  
  // When the drone reaches the destination.
  if(Distance_To_Destination <= 10)
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
    // Stop the drone for course correction.
    hover();

    // Logic for course correction to make sure drone is heading in the right direction.
    if (courseChangeNeeded >= 345 || courseChangeNeeded < 15)
    {
      // Keep going straight.
    }
    else if (courseChangeNeeded >= 315 && courseChangeNeeded < 345)
    {
      // Veer slightly to the left.
    }
    else if (courseChangeNeeded >= 15 && courseChangeNeeded < 45)
    {
      //Veer slightly to the right.
    }
    else if (courseChangeNeeded >= 255 && courseChangeNeeded < 315)
    {
      // Turn to the left.
    }
    else if (courseChangeNeeded >= 45 && courseChangeNeeded < 105)
    {
      // Turn to the right.
    }
    else
    {
      // Turn completely around.
    }

  // Stops the drone if their are no connections to satellites.
  while (numberOfSatellites == 0)
  {
      hover();
  }
 }
} 
