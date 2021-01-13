COMPILER = gcc

CSTD = --std=c18

LIB = -lm

INCLUDE = -Ilib

all: bfs dfs search search.o

bfs : bintree.o mains/bfsM.o queue.o
	$(COMPILER) $(CSTD) $(LIB) bintree.o mains/bfsM.o queue.o -o bfs

dfs : bintree.o mains/dfsM.o queue.o
	$(COMPILER) $(CSTD) $(LIB) bintree.o mains/dfsM.o queue.o -o dfs

search : bintree.o mains/searchM.o queue.o
	$(COMPILER) $(CSTD) $(LIB) bintree.o mains/searchM.o queue.o -o search

search.o: bintree.c bintree.h
	$(COMPILER) $(CSTD) $(LIB) -c -o search.o bintree.c
	
bintree.o : bintree.c bintree.h
	$(COMPILER) $(CSTD) $(LIB) $(INCLUDE) -c bintree.c
	
queue.o : lib/queue.c lib/queue.h
	$(COMPILER) $(CSTD) $(LIB) $(INCLUDE) -c lib/queue.c -o queue.o 




clean :
	rm -f bintree.o bintree
	rm -f queue.o
