CC=gcc
CFLAGS=-W -Wall
LDFLAGS=-lm
EXEC=simulator
SRC=src/
BIN=bin/
OBJ=obj/
TMP=tmp/

all: $(EXEC)

simulator: main.o initialize.o queue.o utilitary.o RNG.o timing.o eventroutine.o
	$(CC) -o $(BIN)simulator $(OBJ)main.o $(OBJ)initialize.o $(OBJ)queue.o $(OBJ)utilitary.o $(OBJ)RNG.o $(OBJ)eventroutine.o $(OBJ)timing.o $(CFLAGS) $(LDFLAGS)

test: main-test.o RNG.o
	$(CC) -o $(BIN)test $(OBJ)main-test.o $(OBJ)RNG.o $(CFLAGS) $(LDFLAGS)

main.o: $(SRC)main.c initialize.o eventroutine.o timing.o
	$(CC) -o $(OBJ)main.o -c $(SRC)main.c $(CFLAGS)

main-test.o: $(SRC)main-test.c RNG.o
	$(CC) -o $(OBJ)main-test.o -c $(SRC)main-test.c $(CFLAGS)

initialize.o: $(SRC)initialize.c $(SRC)initialize.h
	$(CC) -o $(OBJ)initialize.o -c $(SRC)initialize.c $(CFLAGS)

queue.o: $(SRC)queue.c $(SRC)queue.h
	$(CC) -o $(OBJ)queue.o -c $(SRC)queue.c $(CFLAGS)

timing.o: $(SRC)timing.c $(SRC)timing.h
	$(CC) -o $(OBJ)timing.o -c $(SRC)timing.c $(CFLAGS)

utilitary.o: $(SRC)utilitary.c $(SRC)utilitary.h
	$(CC) -o $(OBJ)utilitary.o -c $(SRC)utilitary.c $(CFLAGS)

eventroutine.o: $(SRC)eventroutine.c  $(SRC)eventroutine.h
	$(CC) -o $(OBJ)eventroutine.o -c $(SRC)eventroutine.c $(CFLAGS)

RNG.o: $(SRC)RNG.c $(SRC)RNG.h
	$(CC) -o $(OBJ)RNG.o -c $(SRC)RNG.c $(CFLAGS)

clean:
	rm $(OBJ)*
	rm $(TMP)*
	rm $(BIN)*
