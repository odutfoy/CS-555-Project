CC=gcc
CFLAGS=-W -Wall
LDFLAGS=-lm
EXEC=simulator
SRC=src/
BIN=bin/
OBJ=obj/
TMP=tmp/

all: $(EXEC)

simulator: main.o initialize.o queue.o utilitary.o RNG.o timing.o
	$(CC) -o $(BIN)simulator $(OBJ)main.o $(OBJ)initialize.o $(OBJ)queue.o $(OBJ)utilitary.o $(OBJ)RNG.o $(OBJ)timing.o $(CFLAGS) $(LDFLAGS)

test: main-test.o RNG.o
	$(CC) -o $(BIN)test $(OBJ)main-test.o $(OBJ)RNG.o $(CFLAGS) $(LDFLAGS)

main.o: $(SRC)main.c initialize.o
	$(CC) -o $(OBJ)main.o -c $(SRC)main.c $(CFLAGS)

main-test.o: $(SRC)main-test.c RNG.o
	$(CC) -o $(OBJ)main-test.o -c $(SRC)main-test.c $(CFLAGS)

initialize.o: $(SRC)initialize.h $(SRC)initialize.c $(SRC)struct.h
	$(CC) -o $(OBJ)initialize.o -c $(SRC)initialize.c $(CFLAGS)

queue.o: $(SRC)queue.h $(SRC)queue.c
	$(CC) -o $(OBJ)queue.o -c $(SRC)queue.c $(CFLAGS)

timing.o: $(SRC)timing.h $(SRC)timing.c
	$(CC) -o $(OBJ)timing.o -c $(SRC)timing.c $(CFLAGS)

utilitary.o: $(SRC)utilitary.h $(SRC)utilitary.c RNG.o
	$(CC) -o $(OBJ)utilitary.o -c $(SRC)utilitary.c $(OBJ)RNG.o $(CFLAGS)

RNG.o: $(SRC)RNG.h $(SRC)RNG.c
	$(CC) -o $(OBJ)RNG.o -c $(SRC)RNG.c $(CFLAGS)

clean:
	rm $(BIN)*
	rm $(OBJ)*
	rm $(TMP)*
