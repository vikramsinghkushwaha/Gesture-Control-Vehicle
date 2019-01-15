#include <MPU6050.h>
#include<Wire.h>

#include<SoftwareSerial.h>
SoftwareSerial myserial(10,11);
const int MPU=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ;
char var;


void setup(){
Wire.begin();
Wire.beginTransmission(MPU);
Wire.write(0x6B);  // PWR_MGMT_1 register
Wire.write(0);     // set to zero (wakes up the MPU-6050)
Wire.endTransmission(true);
Serial.begin(115200);
myserial.begin(38400);
}

void loop() {

Wire.beginTransmission(MPU);
Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
Wire.endTransmission(false);
Wire.requestFrom(MPU,14,true);  // request a total of 14 registers
AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C     (ACCEL_XOUT_L)     
AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)


  if(AcX < -8000)
  {
    Serial.println("AcX=");
    Serial.println(AcX);
    Serial.println("AcY=");
    Serial.println(AcY);
    Serial.println("Forward");
    myserial.write("0");
  }

  else if(AcX > 1000)
  {
    Serial.println("AcX=");
    Serial.println(AcX);
    Serial.println("AcY=");
    Serial.println(AcY);
    Serial.println("Backward");
    myserial.write("1");
  }

  if(AcY > 1000)
  {
    Serial.println("AcX=");
    Serial.println(AcX);
    Serial.println("AcY=");
    Serial.println(AcY);
    Serial.println("Right");
    myserial.write("2");
  }
  
  else if(AcY < -8000)
  {
    Serial.println("AcX=");
    Serial.println(AcX);
    Serial.println("AcY=");
    Serial.println(AcY);
    myserial.write("3");
    Serial.println("Left");
  }
  
  else if(AcY > -8000 && AcY < -5000)
  {
    Serial.println("AcX=");
    Serial.println(AcX);
    Serial.println("AcY=");
    Serial.println(AcY);
    Serial.println("Stopping the car");
    myserial.write("4");
  }
  
delay(10);
}
