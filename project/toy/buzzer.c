/*
Juan Angel Garcia Reyes.
80591934.
M-W 1:30- 3:00.
Professor- Dr. Eric Freudenthal.
*/

#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init()
{

  /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
  */

  timerAUpmode();/* used to drive speaker */
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;/* enable output to speaker (P2.6) */
}


void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */{
  CCR0 = cycles;
  CCR1 = cycles >> 1;/* one half cycle */
}

void lostWoods(){
  int keys[20] = {1400, 1136, 1012, 0, 1400, 1136, 1012, 0, 1400, 1136, 1012, 758, 851, 0, 1012, 956, 1012, 1276, 1517, 0}; //these are the frequencies for each tone on lost woods from Zelda videogame
  int i=0;
  for(i; i < 20; i ++){ //for loop that buzz each frequencies as the necesaries 
    buzzer_set_period(keys[i]);
    __delay_cycles(4000000); // this is a method from msp430 which creates a dalay in the sound making it easier to sound.
  }
  buzzer_set_period(0); //stops the sound
}



void bolero(){
  int keys[19] = {1400, 1702, 1400, 1702, 1136, 1400, 1136, 1136, 1400, 0, 0, 0, 1400, 1702, 1136, 1400, 1136, 1400}; //frequencies for the song of zelda bolero of fire
  int i = 0;
  while(i < 20){
    buzzer_set_period(keys[i]);//plays each frequencies
    __delay_cycles(4000000); 
    i++;
  }
  buzzer_set_period(0);
}



void switchStatement(){ //it plays both of the songs, with an each statement
  int i = 0;
  while( i < 2){
    switch(i)
      {
      case 0:
	for(int j=0; j<2 ; j++){ //it plays lostWoods two times
	  lostWoods();
	}
	break;
      case 1:
	for(int k=0; k<2 ; k++){
	  bolero(); //it plays bolero two times.
	}
	break;
      }
   i++;
  }
}

void buzzeroff(){ //it stops the sound
  buzzer_set_period(0);
}
