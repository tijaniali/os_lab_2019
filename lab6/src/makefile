CC=gcc
CFLAGS=-I.

all: server client

server: server.c MultModulo.o MultModulo.h
	$(CC) -pthread -o server server.c MultModulo.o $(CFLAGS)

client: client.c MultModulo.o MultModulo.h
	$(CC) -pthread -o client client.c MultModulo.o $(CFLAGS)

MultiModulo.o: MultModulo.h
	$(CC) -o MultModulo.o -c MultModulo.c $(CFLAGS)

clean:
	rm server client MultModulo.o