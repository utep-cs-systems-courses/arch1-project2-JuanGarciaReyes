/*
Juan Angel Garcia Reyes.
80591934.
M-W 1:30- 3:00.
Professor- Dr. Eric Freudenthal.
*/

#include <msp430.h>
#include "led.h"

unsigned char red_on = 0, green_on = 0, led_state = 0;
unsigned char led_changed = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


void led_init()
{
  P1DIR |= LEDS;// bits attached to leds are output
  led_changed = 1;
  led_update();
}

void led_update()
{
  if (led_changed) {
    char ledFlags = greenVal[red_on] | redVal[green_on]; //changed the red_on into greenVal because it was not working as I wanted to
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;     // set bit for on leds
    led_changed = 0;
  }
}
