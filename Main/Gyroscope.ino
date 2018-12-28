// *************************************************************************
// This files is used to tell what the current orientation of the drone is.*
// It will be used to keep the drone level and to adjust the direction it  *
// will face.                                                              *
// *************************************************************************

void printGyroData()
{
  mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(angleX);
  Serial.print("\tangley : ");
  Serial.print(angleY);
  Serial.print("\tangleZ : ");
  Serial.println(angleZ);
}
void getGyroData()
{
  angleX = mpu6050.getAngleX();
  angleY = mpu6050.getAngleY();
  angleZ = mpu6050.getAngleZ();
}
