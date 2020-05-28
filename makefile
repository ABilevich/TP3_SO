CC=gcc
CFLAGS= -pedantic -std=c99 -Wall

all: client

client: client.c
	@$(CC) $(CFLAGS) client.c -o client

clean:
	@rm client

.PHONY: all clean
