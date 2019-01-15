#include<SoftwareSerial.h>

int m11 = 3;
int m12 = 4;
int m21 = 5;
int m22 = 6;

SoftwareSerial myserial(10,11);

void setup() {
  myserial.begin(38400);
  Serial.begin(115200);
  
  pinMode(m11,OUTPUT);
  pinMode(m12,OUTPUT);
  pinMode(m21,OUTPUT);
  pinMode(m22,OUTPUT); 
}

int temp;

void loop() {
 if(myserial.available()>0)
 {
     temp = myserial.read();
     Serial.write(temp);
 }

 if(temp == '0')
 {
    forward(); 
    Serial.println("Forward");
 }

 if(temp == '1')
 {
    backward(); 
    Serial.println("Backward");
 }
 
 if(temp == '2')
 {
    right(); 
    Serial.println("Right");
 }
 
 if(temp == '3')
 {
    left(); 
    Serial.println("Left");
 }

 if(temp=='4')
 {
    Stop(); 
    Serial.println("Stop");
 }

 delay(10);
}

void forward()
{
  digitalWrite(m11, HIGH);  
  digitalWrite(m12, LOW);
  digitalWrite(m21, HIGH);  
  digitalWrite(m22, LOW);    
}

void backward()
{
  digitalWrite(m11, LOW);  
  digitalWrite(m12, HIGH);
  digitalWrite(m21, LOW);  
  digitalWrite(m22, HIGH);  
}

void left()
{
  digitalWrite(m11, HIGH);  
  digitalWrite(m12, LOW);
  digitalWrite(m21, LOW);  
  digitalWrite(m22, HIGH);  
}

void right()
{
  digitalWrite(m11, LOW);  
  digitalWrite(m12, HIGH);
  digitalWrite(m21, HIGH);  
  digitalWrite(m22, LOW);  
}  

void Stop()
{
  digitalWrite(m11, LOW);  
  digitalWrite(m12, LOW);
  digitalWrite(m21, LOW);  
  digitalWrite(m22, LOW);  
}
