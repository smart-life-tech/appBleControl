#include <SoftwareSerial.h>

// Bluetooth setup
SoftwareSerial BT(3, 4);
char val; // value to receive data from the serial port

// Relay pins
const int relayPins[] = {8, 9, 10, 11, 12, 13, 14, 15};

void setup()
{
    Serial.begin(9600);
    BT.begin(9600); // begin serial communications at 9600 bits per second (baud)

    // Initialize relay pins as outputs and set them to LOW
    for (int i = 0; i < 8; i++)
    {
        pinMode(relayPins[i], OUTPUT);
        digitalWrite(relayPins[i], LOW);
    }
}

void loop()
{
    // Check if there is data to read from Bluetooth
    if (BT.available())
    {
        val = BT.read(); // read the data into our value variable
        BT.print("Reading new data: ");
        BT.println(val);

        // Assuming val corresponds to relay pin control in a specific format
        // For example: 'A' = relay pin 8 ON, 'a' = relay pin 8 OFF
        int relayIndex = (val >= 'A' && val <= 'H') ? val - 'A' : (val >= 'a' && val <= 'h') ? val - 'a'
                                                                                             : -1;
        if (relayIndex >= 0 && relayIndex < 8)
        {
            digitalWrite(relayPins[relayIndex], (val >= 'A' && val <= 'H') ? HIGH : LOW);
        }
    }

    // Check if there is data to read from Serial
    if (Serial.available())
    {
        String teststr = Serial.readString(); // read until timeout
        Serial.println(teststr);

        String addr_lo = teststr.substring(7, 9);
        String data_hi = teststr.substring(9, 11);

        // Control the relays based on the addr_lo and data_hi values
        for (int i = 0; i < 8; i++)
        {
            String n = String(i + 8);
            String relayAddr = String(i + 8, HEX);
            relayAddr.toUpperCase();
            if (addr_lo == relayAddr && data_hi == "FF")
            {
                Serial.print("Trigger pin ");
                Serial.print(relayPins[i]);
                Serial.println(" ON");
                digitalWrite(relayPins[i], HIGH);
            }
            else if (addr_lo == relayAddr && data_hi == "00")
            {
                Serial.print("Trigger pin ");
                Serial.print(relayPins[i]);
                Serial.println(" OFF");
                digitalWrite(relayPins[i], LOW);
            }
        }
    }

    delay(100);
}
