
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

    // challenge1(sock);
    // challenge2(sock);
    // challenge3(sock);
    // challenge4(sock);
    // challenge5(sock);
    // challenge6(sock);
    // challenge7(sock);
    // challenge8(sock);
    // challenge9(sock);
    // challenge10(sock);
    // challenge11(sock);

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

void challenge1(int sock)
{
    char *hello = "entendido\n";
    send(sock, hello, strlen(hello), 0);
}

void challenge2(int sock)
{
    char *msg = "0854780\n";
    send(sock, msg, strlen(msg), 0);
}

void challenge3(int sock)
{
    char *msg = "martin luther king\n";
    send(sock, msg, strlen(msg), 0);
}

void challenge4(int sock)
{
    char *msg = "es_go_lo_dro_bo\n";
    send(sock, msg, strlen(msg), 0);
}

void challenge5(int sock)
{
    char *msg = "too_easy\n";
    send(sock, msg, strlen(msg), 0);
}

void challenge6(int sock)
{
    char *msg = ".RUN_ME\n";
    send(sock, msg, strlen(msg), 0);
}

void challenge7(int sock)
{
    char *msg = "in_de_ter_mi_na_do\n";
    send(sock, msg, strlen(msg), 0);
}

void challenge8(int sock)
{
    char *msg = "thunder thunder thunder thundercats\n";
    send(sock, msg, strlen(msg), 0);
}

void challenge9(int sock)
{
    char *msg = "this is awesome\n";
    send(sock, msg, strlen(msg), 0);
}

void challenge10(int sock)
{
    char *msg = "chin_chu_lan_cha\n";
    send(sock, msg, strlen(msg), 0);
}

void challenge11(int sock)
{
    char *msg = "gdb_manda\n";
    send(sock, msg, strlen(msg), 0);
}
