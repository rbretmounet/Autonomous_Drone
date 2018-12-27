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
  homeAltitude = (gps.altitude.meters());
}
// Used to print out all the gps data that is needed.
void printData()
{
   while (gpsSerial.available())
  {
    int data = gpsSerial.read();
    if (gps.encode(data))
    {
      Serial.print ("lattitude: ");
      Serial.println (currentLattitude);
      Serial.println("");
      Serial.print ("longitude: ");
      Serial.println (currentLongitude);
      Serial.println("");
      Serial.print ("altitude: ");
      Serial.println(currentAltitude);
      Serial.println("");
      Serial.print ("distance: ");
      Serial.println(Distance_To_Destination);
    }
  }
}

// Sets gps data to a variable that will be used to know the current location of the drone.
void getData()
{
  currentLattitude = (gps.location.lat());
  currentLongitude = (gps.location.lng());
  currentAltitude = (gps.altitude.meters());
}

// Used to set the destination data.
void setDestination(float altitude, float lattitude, float longitude)
{
  destinationAltitude = altitude;
  destinationLongitude = longitude;
  destinationLattitude = lattitude;
}

// Used to calculated the distance to the final destination
void updateDistance(float desLongitude, float desLattitude, float currLongitude, float currLattitude)
{
  Distance_To_Destination = TinyGPSPlus::distanceBetween(desLattitude,desLongitude,currLattitude,currLongitude);
}
