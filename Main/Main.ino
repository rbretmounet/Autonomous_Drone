// ****************************************************************** 
// Used to link all of the functions and different components of the*
// entire project                                                   *
// ******************************************************************
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#include <MPU6050_tockn.h>
#include <Wire.h>
/*Notes:
  Y axis = Roll
  X axis = Pitch
  Z axis = Yaw
  Motor_1 = front left 
  Motor_2 = front right
  Motor_3 = back left
  Motor_4 = back right
  Motor_1  \  / Motor_2
            \/
            /\
    Motor_3/  \ Motor_4
  */
Servo motor_1; // Used to communicate values to the esc analog pin connected to motor 1.
Servo motor_2; // Used to communicate values to the esc analog pin connected to motor 2.
Servo motor_3; // Used to communicate values to the esc analog pin connected to motor 3.
Servo motor_4; // Used to communicate values to the esc analog pin connected to motor 4.
int throttle_1;
int throttle_2; 
int throttle_3; 
int throttle_4;
SoftwareSerial gpsSerial(4,3); // Declares pin used to print out gps data.
TinyGPSPlus gps; // Declares a gps object.
MPU6050 mpu6050(Wire); // Declares a gyro object
float homeLattitude,homeLongitude,homeAltitude,currentLattitude, currentLongitude, currentAltitude, 
      destinationLattitude, destinationLongitude, destinationAltitude, doubleAltitude; // Used to store data from gps.
float angleX, angleY, angleZ;
unsigned long Distance_To_Destination, Course_To_Destination; // Used to store the distance from the final destination
int courseChangeNeeded; // Used to store the amount of degrees needed to correct course.
int numberOfSatellites = 1; // Used to store the amount satellites being used.


#define ESP_REMOTE false    // change to true to enable the esp daughter card with wifi remote.

#if ESP_REMOTE
  bool Armed = false;
  #define ESPRXPIN 99
  SoftwareSerial espSerial(ESPRXPIN,99); // Declares pin used to print out gps data.
#endif

void setup() 
{
  motor_1.attach(9); // Declares the pin of the first esc. 
  motor_2.attach(10); // Declares the pin of the second esc.
  motor_3.attach(11); // Declares the pin of the third esc.
  motor_4.attach(12); // Declares the pin of the fourth esc.  
  arm();
  Serial.begin(9600);
  gpsSerial.begin(115200);
  Wire.begin(9600);
  mpu6050.begin();
  //mpu6050.calcGyroOffsets(true); // Calibrates gyroscope.
  // Sets the gps data, distance to destination and plots the course from new point and the current Gyro angles.
  /*while (homeLattitude == 0 || homeLongitude == 0 || homeAltitude == 0 || numberOfSatellites == 0)
  {
    setHome();
    getGyroData();
    getGPSData();
    updateDistance();
    plotCourse();
    printGPSData();
    printGyroData(); 
  }
  setDestination(259.2, 38.088646, -122.158883);*/

#if ESP_REMOTE
  Armed = false;
  espSerial.begin(115200);
#endif
  
}

void loop()
{

#if ESP_REMOTE
  while (espSerial.available()>0)
  {
    char c = espSerial.read();
    switch (c)
    {
       case 'A':
        Armed = true;
        break;
       case '!':
        Armed = false;
        break;
        
       case 'D':
        break;        
       case 'U':
        break;
       case 'L':
        break;
       case 'R':
        break;
    }
  }  
#endif

  /* Updates the gps data, distance to destination and plots the course from new point and the current Gyro angles.
    getGyroData();
    getGPSData();
    updateDistance();
    plotCourse();
    printGPSData();
    printGyroData();*/
  /*// Used to make the drone go two times the height of the original altitude.
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
 }*/
  
} 
