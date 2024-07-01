#include <SoftwareSerial.h>
SoftwareSerial BT(3, 4);
char val;         // value to receieve data from the serial port
int ledpin1 = 5;  // red LED
int ledpin2 = 6;  // green LED
int ledpin3 = 7;  // blue LED
int ledpin4 = 8;  // yellow LED
int ledpin5 = 9;  // white LED
int ledpin6 = 10; // purple LED
int ledpin7 = 11; // orange LED
int ledpin8 = 12; // pink LED
int ledpin9 = 13; // cyan LED

void setup()
{
    pinMode(ledpin1, OUTPUT); // set LED pins as outputs
    pinMode(ledpin2, OUTPUT);
    pinMode(ledpin3, OUTPUT);
    pinMode(ledpin4, OUTPUT);
    pinMode(ledpin5, OUTPUT);
    pinMode(ledpin6, OUTPUT);
    pinMode(ledpin7, OUTPUT);
    pinMode(ledpin8, OUTPUT);
    pinMode(ledpin9, OUTPUT);

    BT.begin(9600); // begin serial communications at 9600 bits per second (baud)
}
void alloff()
{
    digitalWrite(ledpin1, LOW); // Turn off all LEDs
    digitalWrite(ledpin2, LOW);
    digitalWrite(ledpin3, LOW);
    digitalWrite(ledpin4, LOW);
    digitalWrite(ledpin5, LOW);
    digitalWrite(ledpin6, LOW);
    digitalWrite(ledpin7, LOW);
    digitalWrite(ledpin8, LOW);
    digitalWrite(ledpin9, LOW);
}
void loop()
{
    if (BT.available()) // check if there is data to read
    {
        val = BT.read(); // read the data into our value variable
        BT.print("Reading new data: ");
        BT.println(val);
    }
    if (val == '1') // if 1 (high) is received
    {
        alloff();
        digitalWrite(ledpin1, HIGH); // Turn on the green light and off the red light
    }
    else if (val == '2') // 1 not received
    {
        alloff();
        digitalWrite(ledpin2, HIGH);
    }
    else if (val == '3')
    {
        alloff();
        digitalWrite(ledpin3, HIGH);
    }
    else if (val == '4')
    {
        alloff();
        digitalWrite(ledpin4, HIGH);
    }
    else if (val == '5')
    {
        alloff();
        digitalWrite(ledpin5, HIGH);
    }
    else if (val == '6')
    {
        alloff();
        digitalWrite(ledpin6, HIGH);
    }
    else if (val == '7')
    {
        alloff();
        digitalWrite(ledpin7, HIGH);
    }
    else if (val == '8')
    {
        alloff();
        digitalWrite(ledpin8, HIGH);
    }
    else if (val == '9')
    {
        alloff();
        digitalWrite(ledpin9, HIGH);
    }
    else if (val == '0')
    {
        alloff();
    }
    
}