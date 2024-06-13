CC=gcc
RM=rm -rf
FLAG=-lrt  

all: server client

server: server.c
	$(CC) server.c -o server $(FLAG)

client: client.c
	$(CC) client.c -o client $(FLAG)

.PHONY: clean

clean:
	$(RM) server client
