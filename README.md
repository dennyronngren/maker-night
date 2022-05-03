# Makers night

Welcome to the makers night code repository, the purpose for this repository is to make it easy for everyone to contribute to the fun things that 
we are building on our first of the month meetings.

If you run into any issues with the code here or the repository post in the #maker_night slack channel. 


# Motor shield manual
[PDF manual](https://cdn-learn.adafruit.com/downloads/pdf/adafruit-motor-shield.pdf)
[Adafruit motor shield downloads](https://learn.adafruit.com/adafruit-motor-shield/downloads)
[Adafruit motor shield arduino page downloads](https://www.arduino.cc/reference/en/libraries/adafruit-motor-shield-library/)

# Control arduino with keys
Download and install the [Arduino IDE](https://www.arduino.cc/en/software) and the [Processing IDE](https://processing.org/).

make sure that you don't start them with sudo on first run. In that case you with create all config files with sudo, hence they become unaccessable for your user. 

In Arduino IDE press Sketch -> Include Library -> Manage Libraries -> Search for "adafruit motor shield library" and install the V1 version since we use V1 board. 

[Arduino forum thread](https://forum.arduino.cc/t/how-to-use-arrow-keys/399707/7) for controlling with arrows on keyboard, which is the code below. 

Connect the Arduino to the computer, download the Arduino code below. Then fire up Processing and add the Processing code below. 

Press play in Processing, and voila, you can now control the robot with the keys. 

## Fix permission to serial
[Source](https://forum.arduino.cc/t/permission-denied-on-dev-ttyacm0/475568/14)

`sudo chmod a+rw /dev/ttyACM0`
`sudo usermod -a -G dialout $USER`

log in and out
