CC=gcc
CFLAGS=-W -Wall
LDFLAGS=
EXEC=simulator

all: $(EXEC)

simulator: main.o initialize.o
	$(CC) -o bin/simulator obj/main.o obj/initialize.o $(CFLAGS)

main.o: src/main.c initialize.o
	$(CC) -o obj/main.o -c src/main.c $(CFLAGS)

initialize.o: src/initialize.h src/struct.h
	$(CC) -o obj/initialize.o -c src/initialize.c $(CFLAGS)
