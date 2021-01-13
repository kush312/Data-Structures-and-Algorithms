COMPILER = gcc

CSTD = --std=c18

bintree : bintree.o bintreeM.o
	$(COMPILER) $(CSTD) bintree.o bintreeM.o -o bintree

bintree.o : bintree.c bintree.h
	$(COMPILER) $(CSTD) -c bintree.c -o bintree.o

bintreeM.o : 
	printf "You must include 'bintreeMo.' in this directory in order to compile.\n"

clean :
	rm -f bintree
	rm -f bintree.o
