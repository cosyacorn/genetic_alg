CC = gcc
CFLAGS = -Wall

objects=main.o showbits.o fitness.o selection2.o crossover.o mutate.o

#all: prog prog.o

#prog.o: mutate.c
#	$(CC) -c $(CFLAGS) -lm mutate.c

prog: $(objects)
	$(CC) $(CFLAGS) -o task3 $(objects)


.PHONY: clean
clean:
	rm -f $(objects) task3

.PHONY: test
test: task1
	./task3
