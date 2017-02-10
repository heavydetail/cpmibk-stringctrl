/* @DESC: RANDOM SETDATA VIA SERIAL FOR PROCESSING LIGHT EMULATOR
 *
 * DONT EAT YELLOW SNOW.
 *
 */
#include "Arduino.h"
#include <Math.h>

int falloff[] = {80,60,40,20,0,0,20,40,60,80};
int g_brightness = 0;
int g_fade = 5;

void setup()
{
  Serial.begin(115200);
}

void sendChange(int _id, int _brightness) {
  //String scifi = "SETDATA="+x+":"+y+"\n";
  Serial.print("SETLIGHT ");
  Serial.print(_id);
  Serial.print(" ");
  Serial.println(_brightness);
}

void sendPulse() {

  sendChange(1,g_brightness-g_fade-falloff[0]);
  sendChange(5,g_brightness-g_fade-falloff[1]);
  sendChange(9,g_brightness-g_fade-falloff[2]);
  sendChange(13,g_brightness-g_fade-falloff[3]);
  sendChange(17,g_brightness-g_fade-falloff[4]); //mitte
  sendChange(21,g_brightness-g_fade-falloff[5]); //mitte
  sendChange(25,g_brightness-g_fade-falloff[6]);
  sendChange(29,g_brightness-g_fade-falloff[7]);
  sendChange(33,g_brightness-g_fade-falloff[8]);
  sendChange(37,g_brightness-g_fade-falloff[9]);

  g_brightness = g_brightness + g_fade;

  if (g_brightness <= 0 || g_brightness >= 255) {
    g_fade = -g_fade;
  }
}

void loop()
{
  //int id = random(1,38); //uncomment for random data testing
  //int brightness = random(0,255);
  //sendChange(id,brightness);

  sendPulse(); //fading pulse animation
  delay(70); //step speed control, dont go under 40 or so.
}
