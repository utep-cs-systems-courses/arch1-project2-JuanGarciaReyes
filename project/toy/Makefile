# makfile configuration
COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf

#additional rules for files
button.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o buzzer.o switches.o buttonMain.o led.o wdInterruptHandler.o stateMachines.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	msp430loader.sh button.elf

clean:
	rm -f *.o *.elf

switches.o: switches.c switches.h

p1_interrupt_handler.o: p1_interrupt_handler.c switches.h

buzzer.o: buzzer.c buzzer.h

led.o: led.c led.h

wdInterruptHandler.o: stateMachines.h wdInterruptHandler.c

stateMachines.o: led.h stateMachines.h
