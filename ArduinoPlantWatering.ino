#include "LowPower.h"

int sensorPin = A0;
int sensorVcc = 9;
int motorVcc = 5;

unsigned long daysLastWater = 0;
unsigned long daysThreshold = 6;
unsigned long days = 3;
int sensorValue = 0;

void setup()
{
  // No setup is required for this library
  delay(500); // wait for display to boot up
  Serial.begin(9600); // set up serial port for 9600 baud (speed)
  delay(500);
  pinMode(sensorPin, INPUT);
  pinMode(sensorVcc, OUTPUT);
  pinMode(motorVcc, OUTPUT);
  digitalWrite(sensorVcc, LOW);
  digitalWrite(motorVcc, LOW);

  //Read soil moisture sensor
  digitalWrite(sensorVcc, HIGH);
  delay(100);
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  digitalWrite(sensorVcc, LOW);

  //test watering
  digitalWrite(motorVcc, HIGH);
  delay(30 * 1000);
  digitalWrite(motorVcc, LOW);
  //blink
  digitalWrite(13, HIGH);
  delay(10);
  digitalWrite(13, LOW);
}


void loop()
{
  //check every X days
  for (unsigned long i = 0; i < 24 * 450 * days; i++)    {
    // Enter power down state for 8 s with ADC and BOD module disabled
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    //!blinkLed
    digitalWrite(13, HIGH);
    delay(10);
    digitalWrite(13, LOW);
    if (i % (24 * 450) == 0)
      daysLastWater++;
  }

  //Read soil moisture sensor
  digitalWrite(sensorVcc, HIGH);
  delay(100);
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  digitalWrite(sensorVcc, LOW);

  //Water if dry or was long time ago
  if (sensorValue > 800 || daysLastWater >= daysThreshold) {
    digitalWrite(motorVcc, HIGH);
    delay(30 * 1000); //30 seconds
    digitalWrite(motorVcc, LOW);
    daysLastWater = 0;
  }

}
