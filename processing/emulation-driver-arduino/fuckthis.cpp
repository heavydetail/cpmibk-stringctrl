/*
 *
 * DONT EAT YELLOW SNOW
 *
 */

#include "Arduino.h"
#include <ArduinoJson.h>
#include <Math.h>

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

#define RAND_MAX 255;

StaticJsonBuffer<200> jsonBuffer;
int dataindex = 0;

void setup()
{
  Serial.begin(9600);

  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);




}

void loop()
{

  JsonObject& root = jsonBuffer.createObject();
  root["id"] = dataindex;
  root["data"] = random();
  dataindex++;

  root.printTo(Serial);
  Serial.write('\n');

  //int bytesSent = Serial.write('{id:1,data:128}$'); //send the string “hello” and return the length of the string.

  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  // wait for a second
  delay(1000);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
   // wait for a second
  delay(1000);
}
