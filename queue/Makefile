COMPILER = gcc

CSTD = --std=c18

queue : queue.o queueM.o
	$(COMPILER) $(CSTD) queue.o queueM.o -o queue

queue.o : queue.c queue.h
	$(COMPILER) $(CSTD) -c queue.c -o queue.o

queueM.o : 
	printf "You must include 'queueMo.' in this directory in order to compile.\n"

clean :
	rm -f queue
	rm -f queue.o
