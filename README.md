# SimpleLiFi
A simple set of programs to allow one Arduino to send binary data to another Arduino using only light and a light-detecting sensor
## Direction of use
1. Connect a small light (LED/Laser/etc) to the digital pin 13 of one Arduino
2. Connect a digital light detection sensor (Photo-resistor/Photo-transistor/etc) to another Arduino's digital pin 13
3. Download and flash both the "recv"(receiver) and "send"(sender) code to each of the Arduinos
4. Open up a serial monitor for each on of the Arduino
5. Line up the light and the detector
6. Using the serial monitor, send some binary data to the "sender" from the host computer(the computer that you plugged the Arduino into)
7. The data would now being sent by turning the light on and off rapidly
8. Watch as status messeges are returned from the "sender" to the host computer, and the data received by the "receiver" being returned to the computer in which you plugged the "receiver" Arduino into
9. Feel free to adapt this project into your onw applications
## Troubleshooting
If the data are being corrupted, make sure that your hardware is functional, and the delay on both the transmitter and the receiver is the same(the start bit delay, labled "startBitTiming" in the code as an integer need to be slightly longer than the same variable in the transmitter), and if the issue persists, try increasing the delay used in both the receiver and the transmitter
