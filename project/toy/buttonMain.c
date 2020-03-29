/*
Juan Angel Garcia Reyes.
80591934.
M-W 1:30- 3:00.
Professor- Dr. Eric Freudenthal.
*/

#include <msp430.h>
 #include "libTimer.h"
 #include "buzzer.h"
 #include "switches.h"
 #include "led.h"

void main(void) {
   configureClocks();
   switch_init();
   buzzer_init();
   //led_init();
   //enableWDTInterrupts();
   
   or_sr(0x18);          // CPU off, GIE on
 }
