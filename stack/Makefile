COMPILER = gcc

CSTD = --std=c18

stack : stack.o stackM.o
	$(COMPILER) $(CSTD) stack.o stackM.o -o stack

stack.o : stack.c stack.h
	$(COMPILER) $(CSTD) -c stack.c -o stack.o

stackM.o : 
	printf "You must include 'stackMo.' in this directory in order to compile.\n"

clean :
	rm -f stack
	rm -f stack.o
