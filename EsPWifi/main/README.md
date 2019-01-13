This is meant for an esp8266 daughter bord to host an access point and web site where one can control the drone.

Access Point:
*SSID: "Elmer"
*Password: "ElmerWasHere!"

Once connected to that network, one can reach any domain. For example: [http://a.com]

If the esp does not detect a station connected to the network, it will automatically disarm the system. **REMEMBER THAT ONCE THE DRONE GETS OUT OF RANGE!**

ESP sends Serial TX only at 115200 baud from pin D8. Commands are 1 character long:
*"A": Arm system
*"!": Disarm
*"L": Left
*"U": Up
*"D": Down
