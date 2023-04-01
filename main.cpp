//Q2) Multiple instances of interrupts being triggered: 

 //The reason why there are multiple instances being printed is from something called bounce. This is where the mechanical contacts physically bounce off each other and take a fraction of a second to make full contact. The “bounce” of the switch can cause multiple signals to be triggered.  

//Q3) Hardware solution to avoid triggering multiple interrupts: 

//Hardware solutions can include the use of an SR Latch and a double throw switch, as well as a logic chip that uses hysteresis like the 74HC14. For SR Latch two resistors would be required to generate a logic one for the gates and the switch pulls one input to the ground. Even though the switch may bounce between the contacts when it is triggered, the switch will never bounce back to the other contact. Hysteresis means that instead of one voltage threshold, right in the middle, there are two: one-third and two-thirds of the maximum logic voltage. A switch with hysteresis uses the upper threshold when last seen in the low state, and the lower threshold when it’s in the high state. This circuit can also be used in conjunction with a low-pass RC circuit to smooth out any ripples and then use the logic chip to provide hysteresis. A software solution was to add a delay to the function so that when the button was pressed it would not read it until the bounce had occurred but was also quick enough that the user could rapidly tap the button without encountering the effects of the wait function. 

// Include the mbed and C12832 libraries
#include "mbed.h"
#include "C12832.h"

// Create a C12832 LCD object on pins p5, p7, p6, p8, and p11
C12832 lcd(p5, p7, p6, p8, p11);

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
        // Clear the LCD screen
    lcd.cls();
    // Display "Center" on the LCD
    lcd.printf("Center");
    // Wait function for delay
    wait(0.14);

}

// This function is called when the "up" button is pressed
void uppress() {
    // Print "Up" to the serial port
    pc.printf("Up\r\n");
        // Clear the LCD screen
    lcd.cls();
    // Display "Up" on the LCD
    lcd.printf("Up");
    // Wait function for delay
    wait(0.14);


}

// This function is called when the "down" button is pressed
void downpress() {
    // Print "Down" to the serial port
    pc.printf("Down\r\n");
        // Clear the LCD screen
    lcd.cls();
    // Display "Down" on the LCD
    lcd.printf("Down");
    // Wait function for delay
    wait(0.14);


}

// This function is called when the "left" button is pressed
void leftpress() {
    // Print "Left" to the serial port
    pc.printf("Left\r\n");
        // Clear the LCD screen
    lcd.cls();
    // Display "Left" on the LCD
    lcd.printf("Left");
    // Wait function for delay
    wait(0.14);


}

// This function is called when the "right" button is pressed
void rightpress() {
    // Print "Right" to the serial port
    pc.printf("Right\r\n");
        // Clear the LCD screen
    lcd.cls();
    // Display "Right" on the LCD
    lcd.printf("Right");

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
