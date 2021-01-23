# TinyCNC-Etch-a-Sketch
This is a modification of the 3D printed TinyCNC project by [PlotterBot](http://plotterbot.com/2013/12/how-to-build-a-tiny-3-axis-cnc-drawing-robot/).
## Extra hardware
* 2x rotary encoders (with push button)
## Software requirements
* Arduino IDE
* Servo.h extension
* Encoder.h extension
## Wiring
Stepper motor control pins 
* Z Axis - Pin 10
* X Axis - Pin 11
* Y Axis - Pin 12
* Encoder X Axis A - Pin 2
* Encoder X Axis B - Pin 3
* Encoder Y Axis A - Pin 4
* Encoder Y Axis B - Pin 5
* Encoder X button - Pin 6
* Encoder Y button - Pin 7
## Control
### Encoder X
Moves X axis in both directions
Push button raises the Z axis for movement without drawing
### Encoder Y
Moves the Y axis in both directions
Push button lowers the Z axis to allow drawing
## About 
This software is offered without warranty and was intended for use on an Arduino Nano clone, it may work on other Arduino based boards and/or other microcontrollers. It's a very simple script thrown together in half an hour to test the concept. You are free to modify and imporve this in any way you feel necessary.
