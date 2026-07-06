CC = gcc
CFLAGS = -Wall

OBJ = main.o apc.o add.o sub.o mul.o div.o

APC.out: $(OBJ)
	$(CC) $(OBJ) -o APC.out

main.o: main.c apc.h
	$(CC) $(CFLAGS) -c main.c

apc.o: apc.c apc.h
	$(CC) $(CFLAGS) -c apc.c

add.o: add.c apc.h
	$(CC) $(CFLAGS) -c add.c

sub.o: sub.c apc.h
	$(CC) $(CFLAGS) -c sub.c

mul.o: mul.c apc.h
	$(CC) $(CFLAGS) -c mul.c

div.o: div.c apc.h
	$(CC) $(CFLAGS) -c div.c

clean:
	rm -f *.o APC.out