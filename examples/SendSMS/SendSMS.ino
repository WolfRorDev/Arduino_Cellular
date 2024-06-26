/*
 * This example shows how to send an SMS message using the Arduino_Cellular library.
 * 
 * Instructions:
 * 1. Insert a SIM card with or without PIN code in the Arduino Pro 4G Module.
 * 2. Provide sufficient power to the Arduino Pro 4G Module. Ideally, use a 5V power supply
 *    with a current rating of at least 2A and connect it to the VIN and GND pins.
 * 3. Make sure the SIM card has enough credit to send SMS messages.
 * 4. Specify the APN, GPRS username, and GPRS password of your mobile network provider.
 * 5. Specify the PIN code of your SIM card if it has one.
 * 6. Specify the phone number of the recipient and the message you want to send. 
 * 7. Upload the sketch to the connected Arduino board.
 * 
 * Initial author: Sebastian Romero @sebromero
 */
#include "ArduinoCellular.h"

ArduinoCellular cellular = ArduinoCellular();

void setup(){
    Serial.begin(115200);
    while (!Serial);
    delay(1000); // Give the serial monitor some time to start

    // cellular.setDebugStream(Serial); // Uncomment this line to enable debug output
    cellular.begin();

    String pinCode = ""; // If your SIM card has a PIN code, specify it here e.g. "1234"
    if(pinCode.length() > 0 && !cellular.unlockSIM(pinCode)){
        Serial.println("Failed to unlock SIM card.");
        while(true); // Stop here
    }

    Serial.println("Connecting to network...");
    cellular.connect(); // APN settings are not required for sending SMS
    Serial.println("Connected!");

    Serial.println("Sending SMS...");
    cellular.sendSMS("<INSERT_NUMBER_HERE>", "bleep bleep");
    Serial.println("Done.");
}

void loop(){
    delay(1000);
}
