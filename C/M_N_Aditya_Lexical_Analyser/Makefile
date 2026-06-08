CC=gcc

OBJ=main.o lexer.o tokens.o

all: lexer

lexer: $(OBJ)
	gcc $(OBJ) -o lexical_analyser

main.o: main.c lexer.h
	gcc -c main.c

lexer.o: lexer.c lexer.h tokens.h
	gcc -c lexer.c

tokens.o: tokens.c tokens.h
	gcc -c tokens.c

clean:
	rm -f *.o lexical_analyser