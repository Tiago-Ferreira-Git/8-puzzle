# AED, last modified abl 2020.05.29
#
# To compile prog:
#    make

#-----------------------------------------------------------------------
#   Compiler Flags

CC= gcc
CFLAGS= -g -Wall -ansi -pedantic

main: main.o tree.o queue.o
	gcc $(CFLAGS) -o main tree.o main.o queue.o

main.o: main.c tree.h queue.h
	gcc $(CFLAGS) -c main.c

tree.o: tree.c tree.h queue.h
	gcc $(CFLAGS) -c tree.c

queue.o: queue.c tree.h queue.h
	gcc $(CFLAGS) -c queue.c

clean:
	rm -f *.o labt *.~

