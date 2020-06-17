
// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "myclient.h"

int main(int argc, char const *argv[])
{
    int sock = connectToServer();

    awaitInput(sock);
    return 0;
}

int connectToServer()
{
    int sock = 0;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    return sock;
}

void awaitInput(int sock)
{
    char *msg = malloc(100);
    do
    {
        gets(msg);
        printf("sending: %s\n", msg);
        strcat(msg, "\n");
        strcat(msg, "~");
        send(sock, msg, strlen(msg), 0);
    } while (strcmp(msg, "exit") != 0);
}
