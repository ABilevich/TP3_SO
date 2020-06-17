CC=gcc
CFLAGS= -pedantic -std=c99 -Wall

all: myasm myclient myserver

myasm: myasm.asm
	nasm -f elf64 myasm.asm -o myasm.o

myclient: myclient.c
	@$(CC) $(CFLAGS) myclient.c -o myclient

myserver: myserver.c
	@$(CC) $(CFLAGS) myserver.c myasm.o -o myserver

clean:
	@rm myclient myserver myasm.o

.PHONY: all clean
