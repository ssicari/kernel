CC = gcc
CFLAGS = -Wall -Werror -Wpedantic
OBJECTS = main.o

all: A1

A1: $(OBJECTS)
	$(CC) $(CFLAGS) -o A1 $(OBJECTS)

A1.o: main.c
	$$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm A1 *.o
