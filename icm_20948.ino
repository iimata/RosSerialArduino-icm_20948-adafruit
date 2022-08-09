/*

2022-8-8 by :: Mahmoud AL-Tamimi

2022-8-8 Email :: mhmwdnbyl960@gmail.com

2022-8-8 Linkedin :: https://www.linkedin.com/in/mahmoud-tamimi-733021217/

*/
#include <Adafruit_ICM20X.h>
#include <Adafruit_ICM20948.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <ros.h>
#include <sensor_msgs/Imu.h>

ros::NodeHandle  nh;
sensor_msgs::Imu imu_msg;
ros::Publisher imu_pub("/imu/data", &imu_msg);
long sequence = 0;

Adafruit_ICM20948 icm;
uint16_t measurement_delay_us = 65535; // Delay between measurements for testing
#define ICM_CS 10
#define ICM_SCK 13
#define ICM_MISO 12
#define ICM_MOSI 11
int status;

void setup() {
Serial.begin(115200);
while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit ICM20948 test!");

  if (!icm.begin_I2C()) {
    // if (!icm.begin_SPI(ICM_CS)) {
    // if (!icm.begin_SPI(ICM_CS, ICM_SCK, ICM_MISO, ICM_MOSI)) {
    Serial.println("Failed to find ICM20948 chip");
    while (1) {
      delay(10);
    }
  }


 
   //  icm.setAccelRateDivisor(4095);
  uint16_t accel_divisor = icm.getAccelRateDivisor();
  float accel_rate = 1125 / (1.0 + accel_divisor);

  

  //  icm.setGyroRateDivisor(255);
  uint8_t gyro_divisor = icm.getGyroRateDivisor();
  float gyro_rate = 1100 / (1.0 + gyro_divisor);

  
 

  nh.initNode();
 nh.advertise(imu_pub);
 
 

  

}

void loop() {

  //  /* Get a new normalized sensor event */
  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t mag;
  sensors_event_t temp;
  icm.getEvent(&accel, &gyro, &temp, &mag);
imu_msg.header.seq = sequence++;
  imu_msg.header.stamp = nh.now();
  imu_msg.header.frame_id  ="base_link";//put your frame_id

  //Linear Acceleration 
  imu_msg.linear_acceleration.x = accel.acceleration.x ;
  imu_msg.linear_acceleration.y = accel.acceleration.y ;
  imu_msg.linear_acceleration.z = accel.acceleration.z ;
 
  //Angular Velocity
  imu_msg.angular_velocity.x = gyro.gyro.x ;
  imu_msg.angular_velocity.y = gyro.gyro.y ; 
  imu_msg.angular_velocity.z = gyro.gyro.z ;  

  //Orientation
  imu_msg.orientation.x = 0 ;
  imu_msg.orientation.y = 0 ;
  imu_msg.orientation.z = 0 ;
  imu_msg.orientation.w = 0 ;

  imu_pub.publish(&imu_msg);
  nh.spinOnce();

  

  delay(10);

 
}
