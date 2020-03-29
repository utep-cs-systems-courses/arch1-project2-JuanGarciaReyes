#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count == 125) {
    switcher();
  }
  
  count();
  state_of_leds();
  led_update();
}
