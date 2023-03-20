#include "mbed.h"

// Create a Serial object named "pc" on the USB serial connection
Serial pc(USBTX, USBRX);

// Create InterruptIn objects for each of the five buttons
InterruptIn center(p14);
InterruptIn up(p15);
InterruptIn down(p12);
InterruptIn left(p13);
InterruptIn right(p16);

// This function is called when the "center" button is pressed
void centerpress() {
    // Print "Center" to the serial port
    pc.printf("Center\r\n");
}

// This function is called when the "up" button is pressed
void uppress() {
    // Print "Up" to the serial port
    pc.printf("Up\r\n");
}

// This function is called when the "down" button is pressed
void downpress() {
    // Print "Down" to the serial port
    pc.printf("Down\r\n");
}

// This function is called when the "left" button is pressed
void leftpress() {
    // Print "Left" to the serial port
    pc.printf("Left\r\n");
}

// This function is called when the "right" button is pressed
void rightpress() {
    // Print "Right" to the serial port
    pc.printf("Right\r\n");
}

int main() {
    // Attach the centerpress function to the rising edge of the "center" button
    center.rise(&centerpress);
    
    // Attach the uppress function to the rising edge of the "up" button
    up.rise(&uppress);
    
    // Attach the downpress function to the rising edge of the "down" button
    down.rise(&downpress);
    
    // Attach the leftpress function to the rising edge of the "left" button
    left.rise(&leftpress);
    
    // Attach the rightpress function to the rising edge of the "right" button
    right.rise(&rightpress);

    // Enter an infinite loop to keep the program running indefinitely
    while(1) {}
}
