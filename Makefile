CC=gcc
CFLAGS=-W -Wall
LDFLAGS=
EXEC=simulator

all: $(EXEC)

simulator: main.o initialize.o
	$(CC) -o bin/simulator obj/main.o obj/initialize.o $(CFLAGS)

main.o: src/main.c initialize.o queue.o
	$(CC) -o obj/main.o -c src/main.c $(CFLAGS)

initialize.o: src/initialize.h src/struct.h queue.o
	$(CC) -o obj/initialize.o -c src/initialize.c $(CFLAGS)

queue.o: src/queue.h
	$(CC) -o obj/queue.o -c src/queue.h $(CFLAGS)
