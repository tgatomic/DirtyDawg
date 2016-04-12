# DirtyDawg

A school project in order to learn and improve our skills in Embedded Systems.


The project consist of a RC car with custom software that detect obstacles and report
the distance to the objects by sending the data over bluetooth to the remotecontroller
where the distances is printed on a small screen. 

This in order to be able to drive the car without actually being able to see it. If there are
time and money budget over, we plan to ad a camera and FPV screen. Maybe even a second RC
car that follows the first one in its heals. 


The car will sense the distance to obbects, using an IR detection unit that will be controlled
by an atmel chip and send the information over the I2C bus over to the main controller that 
will handle the motor controll and communication over Bluetooth. 


The remote controll will have a Bluetooth module that recieves and sends controll data back to
the car. The controll will be able to do this by having an mico with custom software on it. If
the time budget allows, it can be possible to use a phone instead of the controller to controll 
the car. 