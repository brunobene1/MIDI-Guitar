# MIDI-Guitar-and-Controller  
For this project I used an broken ps2 guitar hero controller to make a MIDI guitar and a new guitar controller to play games on the computer.  
The idea was to use the ps2 controller body and buttons and combine it with an Arduino. So inside de controller I dessolder all the button wires and ressoldered in the Arduino pro micro.  
For this project to work I decided to use an Arduino that has the ATMega32u4 micocontroller(Arduino pro micro), because this microcontroller has native USB support. With that native support I can emulate the computer keyboard for the games and also make a MIDI class complient device.  
There is support for 3 games. Guitar Hero, Clone Hero and Guitar Flash.  
In the MIDI guitar there are also 2 modes, single note mode and chord mode.       
# Modes  
There are 4 modes, wich you can change with the "start" button.  
The modes are(in order):  
1-Clone Hero  
2-Guitar Hero  
3-Guitar Flash  
4-MIDI guitar

on the MIDI guitar mode you can change between two modes with the "select" button, the modes are:    
1-Single note mode  
2-Chord mode  

![guitar_buttons_picture](https://user-images.githubusercontent.com/85142097/161838484-f7491f42-c407-4519-8660-b351ff627512.png)    
# MIDI data flow logic  
For the MIDI part to work you will need a DAW(digital audio workstation), I used the "ample sound guitar m lite ii".  
![DATA_FLOW](https://user-images.githubusercontent.com/85142097/161836724-46b668cd-d233-4ebe-b608-dfd2b11a9aa0.png)  
# Dependencies  
(both need microcontroller with native USB support, EX: ATMega32u4)  
-MIDIUSB library   
-Keyboard library  
 
