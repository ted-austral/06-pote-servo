/*
 *     Project 06-pote-servo - main.cpp
 *
 *     Austral 2022 - IntroComp - EAM
 *
 *     Servo rotates controlled by a potentiometer
 *     When angle changes, print it on serial monitor
 *
 *     ESP32 development board
 *
 */

#include <Arduino.h>

#include <Servo.h>

/*
 *  Constant definitions
 *      Defined in platformio.ini
 *      MY_SERVO    GPIO of data servo
 *      ANAIN       GPIO of ADC input
 *      RANGE       ADC range
 *      SERIAL_BAUD Serial port Baud rate
 */


#define LOOP_DELAY  250

Servo servo;            //    New object of type Servo

//  static variables

static int last_angle;

void
setup()
{
    Serial.begin(SERIAL_BAUD);
    servo.attach(MY_SERVO);
    last_angle = 0;
    delay(2000);
}

void
loop()
{
    int sensorValue, angle;

    sensorValue = analogRead(ANAIN);
    angle = map( sensorValue, 0, RANGE, 0, 180 );

    if( angle != last_angle )
    {
        Serial.printf( "angle = %d\n\r", angle );
        servo.write(angle);
        last_angle = angle;
        delay(LOOP_DELAY);
    }
}
