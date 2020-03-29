#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static enum {off=0, on=1, dim=2} cases; //creates a dictionary of cases off on and the dim which lows the led light
static char counter =0;

void switcher(){
  cases = (cases + 1) % 3; //switches from 0 to 1
}

void count(){ //altenate the counter in the state of the leds
  counter = (counter + 1) % 3;
}

void state_of_leds(){ //change the states of the light from off to on and finally to dim
  char temp;
  switch (cases){
  case off: //off turn.
    temp = 0;
    break;
  case on: // it turns the light on.
    temp = 1;
    break;
  case dim: //it lows the frequency of the light.
    temp = (counter < 1);
    break;
  }
  if(red_on != temp){ // finally uses the red light.
    red_on = temp;
    led_changed = 1;
  }
}

void greenon(){
  green_on = 1; //turns on the green light
}

void greenoff(){
  green_on = 0; //turns off the green light
}


