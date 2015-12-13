CC=gcc
CFLAGS=-W -Wall
LDFLAGS=-lm
EXEC=simulator
SRC=src/
BIN=bin/
OBJ=obj/
TMP=tmp/

all: $(EXEC)

simulator: main.o initialize.o queue.o utilitary.o RNG.o timing.o eventroutine.o struct.o
	$(CC) -o $(BIN)simulator $(OBJ)main.o $(OBJ)initialize.o $(OBJ)queue.o $(OBJ)utilitary.o $(OBJ)RNG.o $(OBJ)eventroutine.o $(OBJ)timing.o $(OBJ)struct.o $(CFLAGS) $(LDFLAGS)

test: main-test.o RNG.o
	$(CC) -o $(BIN)test $(OBJ)main-test.o $(OBJ)RNG.o $(CFLAGS) $(LDFLAGS)

main.o: $(SRC)main.c initialize.o eventroutine.o timing.o
	$(CC) -o $(OBJ)main.o -c $(SRC)main.c $(CFLAGS)

main-test.o: $(SRC)main-test.c RNG.o
	$(CC) -o $(OBJ)main-test.o -c $(SRC)main-test.c $(CFLAGS)

initialize.o: $(SRC)initialize.h $(SRC)initialize.c struct.o
	$(CC) -o $(OBJ)initialize.o -c $(SRC)initialize.c $(OBJ)struct.o $(CFLAGS)

queue.o: $(SRC)queue.h $(SRC)queue.c
	$(CC) -o $(OBJ)queue.o -c $(SRC)queue.c $(CFLAGS)

timing.o: $(SRC)timing.h $(SRC)timing.c struct.o queue.o
	$(CC) -o $(OBJ)timing.o -c $(SRC)timing.c $(OBJ)struct.o $(OBJ)queue.o $(CFLAGS)

utilitary.o: $(SRC)utilitary.h $(SRC)utilitary.c
	$(CC) -o $(OBJ)utilitary.o -c $(SRC)utilitary.c $(CFLAGS)

eventroutine.o: $(SRC)eventroutine.h $(SRC)eventroutine.c
	$(CC) -o $(OBJ)eventroutine.o -c $(SRC)eventroutine.c $(CFLAGS)

struct.o: $(SRC)struct.h
	$(CC) -o $(OBJ)struct.o -c $(SRC)struct.h $(CFLAGS)

RNG.o: $(SRC)RNG.h $(SRC)RNG.c
	$(CC) -o $(OBJ)RNG.o -c $(SRC)RNG.c $(CFLAGS)

clean:
	rm $(BIN)*
	rm $(OBJ)*
	rm $(TMP)*
