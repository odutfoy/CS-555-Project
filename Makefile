CC=gcc
CFLAGS=-W -Wall
LDFLAGS=-lm -std=c99
EXEC=simulator
SRC=src/
BIN=bin/
OBJ=obj/

all: $(EXEC)

test: main-test.o RNG.o
	$(CC) -o $(BIN)test $(OBJ)main-test.o $(OBJ)RNG.o $(CFLAGS) $(LDFLAGS)

simulator: main.o initialize.o RNG.o
	$(CC) -o $(BIN)simulator $(OBJ)main.o $(OBJ)initialize.o $(OBJ)RNG.o $(CFLAGS) $(LDFLAGS)

main.o: $(SRC)main.c initialize.o queue.o RNG.o
	$(CC) -o $(OBJ)main.o -c $(SRC)main.c $(OBJ)RNG.o $(CFLAGS)

main-test.o: $(SRC)main-test.c RNG.o
	$(CC) -o $(OBJ)main-test.o -c $(SRC)main-test.c $(CFLAGS)

initialize.o: $(SRC)initialize.h $(SRC)struct.h queue.o
	$(CC) -o $(OBJ)initialize.o -c $(SRC)initialize.c $(CFLAGS)

queue.o: $(SRC)queue.h
	$(CC) -o $(OBJ)queue.o -c $(SRC)queue.h $(CFLAGS)

RNG.o: $(SRC)RNG.h
	$(CC) -o $(OBJ)RNG.o -c $(SRC)RNG.c $(CFLAGS)

clean:
	rm $(BIN)*
	rm $(OBJ)*
