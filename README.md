# Gesture-Control-Vehicle
Gesture Controlled Vehicle is a project which is done using two arduino, two HC-05 modules, one MPU 6050, motor driver L293d and motors (along with chassis of a vehicle).
The master code is for the master arduino which will receive and manipulate the data from the gestures captured by the MPU 6050.
The slave code is for the arduino which will receive the command of forward, backward, left, right and stop. The slave arduino is given connection to the chassis and the motor driver while the master arduino is connected to MPU 6050.
The connections are available on internet.
Basic settings are also needed to be done with the bluetooth modules (to make them act as master and slave) which is connected to both master and slave arduino. This is also available on internet.
