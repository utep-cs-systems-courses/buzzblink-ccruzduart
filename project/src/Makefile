COMMON_OBJECTS = wdinterrupt.o main.o switches.o states.o buzzer.o
CPU	       = msp430g2553
CFLAGS	       = -mmcu=${CPU} -I../h
LDFLAGS        = -L/opt/ti/msp430_gcc/include

CC	       = msp430-elf-gcc
AS             = msp430-elf-as

all: project2.elf

project2-c.elf: ${COMMON_OBJECTS} led-c.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

project2-s.elf: ${COMMON_OBJECTS} led-s.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load-c: project2-c.elf
	msp430loader.sh project2-c.elf

load-s: project2-s.elf
	msp430loader.sh project2-s.elf

clean:
	rm -f *.o *.elf

$(COMMON_OBJECTS): led-c.c led.h switches.h buzzer.h states.h 
