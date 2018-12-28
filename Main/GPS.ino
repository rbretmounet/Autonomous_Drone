// *****************************************************************
// This file is used to get the coordinates of the current position*
// of the drone. This will be used to help the drone too know where*
// its current location is relative to its final destination.      *
// *****************************************************************

// Used to set home position of drone
void setHome()
{
    homeLattitude = (gps.location.lat());
    homeLongitude = (gps.location.lng());
    homeAltitude = (gps.altitude.feet());
}
// Used to print out all the gps data that is needed.
void printGPSData()
{
   while (gpsSerial.available())
  {
    int data = gpsSerial.read();
    if (gps.encode(data))
    {
      Serial.print ("Lattitude: ");
      Serial.println (currentLattitude);
      Serial.print ("Longitude: ");
      Serial.println (currentLongitude);
      Serial.print ("Altitude: ");
      Serial.println(currentAltitude);
      Serial.print ("Distance: ");
      Serial.println(Distance_To_Destination);
      Serial.print ("Course: ");
      Serial.println(courseChangeNeeded);
      Serial.print ("Satellites: ");
      Serial.println(numberOfSatellites);
      Serial.println(" ");
      
    }
  }
}

// Sets gps data to a variable that will be used to know the current location of the drone.
void getGPSData()
{
  currentLattitude = (gps.location.lat());
  currentLongitude = (gps.location.lng());
  currentAltitude = (gps.altitude.feet());
}

// Used to set the destination data.
void setDestination(float altitude, float lattitude, float longitude)
{
  destinationAltitude = altitude;
  destinationLongitude = longitude;
  destinationLattitude = lattitude;
}

// Used to calculated the distance to the final destination
void updateDistance()
{
  Distance_To_Destination = TinyGPSPlus::distanceBetween(currentLattitude,currentLongitude,destinationLattitude,destinationLongitude);
}

void plotCourse()
{
  Course_To_Destination = TinyGPSPlus::courseTo(currentLattitude,currentLongitude,destinationLattitude,destinationLongitude);
  courseChangeNeeded = (int)(360 + Course_To_Destination - gps.course.deg()) % 360;

}
