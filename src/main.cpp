#include <Arduino.h>

/**
 * @file main.ino
 * @brief Embedded Touch Detection System using TTP223
 * @author Vedansh
 * @date 2026-02-28
 *
 * @details
 * This program reads digital touch input from the TTP223 capacitive touch sensor.
 * When the sensor is touched, it outputs a HIGH signal; otherwise, it remains LOW.
 * The system continuously monitors the touch state and displays structured
 * messages on the Serial Monitor indicating whether touch is detected or not.
 */

// Define touch sensor digital pin (Use pin 2)
#define TOUCH_PIN 2

// Variable to store touch state (HIGH or LOW)
int touchState;

/**
 * @brief Initializes serial communication and configures touch sensor pin.
 */
void setup() {

    // Initialize Serial communication (9600 baud rate)
    Serial.begin(9600);

    // Configure touch pin as INPUT
    pinMode(TOUCH_PIN, INPUT);

    // Print system initialization message
    Serial.println("TTP223 Touch Detection System Initialized");
}

/**
 * @brief Continuously reads touch input and prints detection status.
 */
void loop() {

    // Read digital value from touch sensor
    touchState = digitalRead(TOUCH_PIN);

    // If touch detected (HIGH), print message
    if (touchState == HIGH) {
        Serial.println("Touch Detected");
    } else {
        Serial.println("No Touch");
    }

    // Add small delay (200–500ms) for stable readings
    delay(300);
}
