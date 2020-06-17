#define PORT 8080
#include <sys/stat.h>
#include <fcntl.h>
int startServer();
void awaitMessages(int socket);
void checkResp(int socket, char *resp, char* msg, int aux);
void challenge0(int socket);
void challenge1(int socket);
void challenge2(int socket);
void challenge3(int socket);
void challenge4(int socket);
void challenge5(int socket);
void challenge6(int socket);
void challenge7(int socket);
void challenge8(int socket);
void challenge9(int socket);
void challenge10(int socket);

void printThundercatsImage();
void checkQuine(int socket);
void clearScreen();
void writeOnFd();
void gdbme();
int checkQuineFunction();
void printBasura();

char *randstring(int length);

void _nohagonada();
void _nohagonada2();
void _nohagonada3();
void _nohagonada4();
void _nohagonada5();
void _nohagonada6();
void _nohagonada7();
char *readFile(char *fileName);
void error_print(char * msg);