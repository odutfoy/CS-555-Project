CC=gcc
CFLAGS=-W -Wall
LDFLAGS=
EXEC=simulator

all: $(EXEC)

simulator: src/main.c
	$(CC) -o bin/simulator src/main.c $(CFLAGS)
