# RosSerialArduino-icm_20948-adafruit
RosSerialArduino icm_20948 adafruit.

1-you need to install the adafruit libraries.
link :: https://learn.adafruit.com/adafruit-tdk-invensense-icm-20948-9-dof-imu/arduino

2-Connect board VIN (red wire) to Arduino 5V if you are running a 5V board Arduino (Uno, etc.). If your board is 3V, connect to that instead.

  Connect board GND (black wire) to Arduino GND.
  
  Connect board SCL (yellow wire) to Arduino SCL.
  
  Connect board SDA (blue wire) to Arduino SDA.
  
  
3-after uploading the code u can run rviz and set the fixed_frame to your frame_id in the arduino code.

![Alt text](url "rviz.png")
