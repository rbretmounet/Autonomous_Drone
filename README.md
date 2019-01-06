# Autonomous Drone
This project is an autonomous drone that uses gps cordinates to plot a path and fly to that destination. It has built in gyroscope stabilization allowing it to fly with ease. It also has a gps module used to gather crucial data of the drones current altitude, lattitude, and longituted which is then used to plot and travel its current course.
## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.
### Hardware
Arduino Nano V3:
```
https://www.amazon.com/dp/B0713XK923/?coliid=I242HYSBBB6NHF&colid=276WO2F9JN13Y&psc=0&ref_=lv_ov_lig_dp_it
```
High Quality 10-inch Quadcopter and Multirotors Props:
```
https://www.amazon.com/dp/B01CJMJ886/?coliid=IBQF3VZNVFQHU&colid=276WO2F9JN13Y&psc=0&ref_=lv_ov_lig_dp_it
```
4x 2212 920KV Brushless Motor + 4x 30A ESC:
```
https://www.amazon.com/dp/B00XQYTZQ2/?coliid=I3A6DY2IU4KQVQ&colid=276WO2F9JN13Y&psc=0&ref_=lv_ov_lig_dp_it
```
F450 Drone Frame Kit 4-Axis Airframe 450mm Quadcopter Frame:
```
https://www.amazon.com/dp/B0776WLHX7/?coliid=I1YH3AZW187K61&colid=276WO2F9JN13Y&psc=0&ref_=lv_ov_lig_dp_it
```
NEO-6M GPS Module:
```
https://www.amazon.com/dp/B075DD5746/?coliid=I3SDCP6NCJ8XCL&colid=276WO2F9JN13Y&psc=0&ref_=lv_ov_lig_dp_it
```
MPU-6050 Module:
```
https://www.amazon.com/dp/B008BOPN40/?coliid=I24WGRR2SUMA96&colid=276WO2F9JN13Y&psc=0&ref_=lv_ov_lig_dp_it
```
### Installing
* Arduino <br />
* Project <br />
#### Libraries:
* TinyGPS++ <br />
* MPU-6050 <br />

#### Arduino 
This is how to install Arduino on computer.
1) Download the latest version of Arduino at: ```https://www.arduino.cc/en/Main/Software```
2) Run the installer and follow the onscreen instrustions.

#### TinyGPS++:
This is how to install the TinyGPS++ library for the project. <br />
1) Go to: ```https://github.com/mikalhart/TinyGPSPlus/releases```
2) Click on the newest version asset download link.
3) Once you have the TinyGPS++ zip library open up Arduino.
4) Then navigate to Sketch > Include Library > Add .Zip Library and select the TinyGPS++ zip library download.
#### MPU-6050
This is how to install the MPU-6050 library for the project. <br />
1) Go to: ```https://github.com/tockn/MPU6050_tockn```
2) Click on the "Clone or Download" button and click the "Download Zip" button
3) Once you have the MPU-6050 zip library open up Arduino.
4) Then navigate to Sketch > Include Library > Add .Zip Library and select the MPU-6050 zip library download.

#### Project
This is how to install the github project.
##### Method 1:
1) Click on the "Clone or Download" button and click the "Download Zip" button
2) Extract the zip file
3) Open "Autonomous_Drone" folder
4) Open "Main" folder
5) Open "Main.ino"
##### Method 2:
1) Open terminal 
2) Navigate to desktop: ```cd Deskstop```
3) Enter in ```git clone https://github.com/rbretmounet/Autonomous_Drone.git"
4) Open "Autonomous_Drone" folder
5) Open "Main" folder
6) Open "Main.ino"

### Developer Notes
Must enter in destination gps coordinates manually in the code itself. Potential future update may be too add an app too enter gps coordinates using google maps.
