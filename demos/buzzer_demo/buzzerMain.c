#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

int main() {
    configureClocks();
    buzzer_init();
    switchStatement();
    //buzzer_set_period(1000);/* start buzzing!!! */
    //buzzer_set_period(500);
    //buzzer_set_period(100);
    //buzzer_set_period(500);
    //buzzer_set_period(400);
    or_sr(0x18);          // CPU off, GIE on
}
