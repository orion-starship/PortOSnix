# Makefile for minithreads on x86_64 Linux

# You probably only need to modify the MAIN variable to build the desired file

CC = gcc

CFLAGS = -mno-red-zone -fno-omit-frame-pointer -ggdb -O0 -I. -Wdeclaration-after-statement

OUTPUT = minithread

# change this to the name of the file you want to link with minithreads,
# dropping the ".c": so to use "sieve.c", change to "MAIN = sieve".
#
# Note that you must write your own test programs.

MAIN = test_queue

OBJ = \
	random.o \
	minithread.o \
	machineprimitives_x86_64_asm.o \
	machineprimitives_x86_64.o \
	machineprimitives.o \
	queue.o \
	$(MAIN).o \
	synch.o \

all: portos

.c.obj:
	$(CC) $(CFLAGS) $<

machineprimitives_x86_64_asm.o: machineprimitives_x86_64_asm.S
	$(CC) -c machineprimitives_x86_64_asm.S -o machineprimitives_x86_64_asm.o

portos: start.o end.o $(OBJ) $(SYSTEMOBJ)
	$(CC) $(LFLAGS) $(LIB) start.o $(OBJ) end.o $(LFLAGS) -o $(OUTPUT)

clean:
	rm -f *.o
	rm -f $(OUTPUT)

#depend:
#	gcc -MM *.c 2>/dev/null | sed -e "s/\.o/.obj/" > depend


include Depend
