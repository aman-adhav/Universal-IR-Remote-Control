# universalRemote

A universal IR transmitter receiver system

Proposal:

A regular human especially in the western society, has quite a few devices at his/her home, workplace, or any other area they visit. We are surrounded by devices that work on wireless communication such as IR. Taking care of all these devices such as TV Remotes, car keys, heaters, AC remotes can be a real pain. The solution for this problem is storing all IR codes and signals in one device to make it a universal transmitter and receiver. 

Parts :

1 X 3.6MM IR LED 1.5V

1 X TSOP1380 IR Receiver

1 X Arduino Uno

2 X Bread Boards

Jumper cables

1 X Red, Green or Blue LED

2 X 1kΩ Resistor

USB Cable & Laptop

Normally a device transmits or receives a particular frequency. All IR devices operate between 36 Khz - 56 KHz. If given more time to complete this summative (1-2 weeks) it would have been possible to make a graphic user interface which would help store the IR signal for the device.

![Screenshot](Uploadsimage.png)

The technology:

In the IR decoder program, the TSOP repeats the program every 65 milliseconds. The array will store a segment of 100 integers which denote how long something was on for and how long it will be off. The IR segment is then copied into the IR signal program and the signal is played when the user inputs “POWER”. 

Report : 

The initial idea was to capture frequencies from the projector remote control. The project was successful in terms of turning the projector on. However it did not store the multiple functions for the remote control. Part of the reasons were time constraints, problems with incorporating button input in the program. 

The device worked fine if there is no interference when decoding the signal. When I tested it in my room (no interference) the device functioned fine compared to workplace environment in the classroom. Multiple tests have to occur before the signal can be used. It would more effective if there is a noise filtration circuit to avoid any sources of error. The devices that functioned using this IR universal remote included:

1 X TV (LG PX8600)
1 X Air Conditioner
1 X Projector

