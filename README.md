# RosSerialArduino-icm_20948-adafruit
RosSerialArduino icm_20948 adafruit.

1-you need to install the adafruit libraries.
link :: https://learn.adafruit.com/adafruit-tdk-invensense-icm-20948-9-dof-imu/arduino

2-Connect board VIN (red wire) to Arduino 5V if you are running a 5V board Arduino (Uno, etc.). If your board is 3V, connect to that instead.

  Connect board GND (black wire) to Arduino GND.
  
  Connect board SCL (yellow wire) to Arduino SCL.
  
  Connect board SDA (blue wire) to Arduino SDA.
  
  ![connection](https://github.com/iimata/RosSerialArduino-icm_20948-adafruit/blob/13e648956805c3180cb4ba0529a6c6d86d5f1d2c/connection.jpg)

3-after uploading the code u can run rviz and set the fixed_frame to your frame_id in the arduino code.

![rviz](https://github.com/iimata/RosSerialArduino-icm_20948-adafruit/blob/8e517d3d7e1bf755abe3adb018272e6fde22ac38/rviz.png)

![rviz1](https://github.com/iimata/RosSerialArduino-icm_20948-adafruit/blob/main/pictures/rviz1.png)

