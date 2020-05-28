#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "client.h"

int main(int argc, char const *argv[])
{
    int sock = connectToServer();
    chalenge1(sock);
    chalenge2(sock);
    while (1)
    {
    }
    //asd
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

void chalenge1(int sock)
{
    char *hello = "entendido\n";
    send(sock, hello, strlen(hello), 0);
}

void chalenge2(int sock)
{
    char *msg0 = "# 75 72 72 75 80 77 80 75 *\n";
    char *msg1 = "35 75 72 72 75 80 77 80 75 42\n";
    char *msg2 = "75 72 72 75 80 77 80 75\n";
    char *msg3 = "#\n";
    char *msg4 = "VALGRIND_ES_GENIAL\n";
    char *msg5 = "# left left *\n";
    char *msg6 = "#flag*\n";
    send(sock, msg6, strlen(msg6), 0);
}