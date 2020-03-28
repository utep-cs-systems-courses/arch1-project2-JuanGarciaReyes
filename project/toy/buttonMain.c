 #include <msp430.h>
 #include "libTimer.h"
 #include "buzzer.h"
 #include "switches.h"

 void main(void) {
   configureClocks();
   switch_init();
   buzzer_init();

   or_sr(0x18);          // CPU off, GIE on
 }
