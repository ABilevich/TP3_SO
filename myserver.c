// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "myserver.h"
#include <time.h>

char *responses[11] = {
    "entendido\n",
    "0854780\n",
    "martin luther king\n",
    "es_go_lo_dro_bo\n",
    "too_easy\n",
    ".RUN_ME\n",
    "in_de_ter_mi_na_do\n",
    "thunder thunder thunder thundercats\n",
    "this is awesome\n",
    "chin_chu_lan_cha\n",
    "gdb_manda\n",
};

int main(int argc, char const *argv[])
{
    int socket = startServer();
    awaitMessages(socket);
}

int startServer()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t *)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    return new_socket;
}

void awaitMessages(int socket)
{
    clearScreen();
    challenge0(socket);
    challenge1(socket);
    challenge2(socket);
    challenge3(socket);
    challenge4(socket);
    challenge5(socket);
    challenge6(socket);
    challenge7(socket);
    challenge8(socket);
    challenge9(socket);
    challenge10(socket);
    printf("ganaste!!\n");
}

void checkResp(int socket, char *resp, char* msg, int aux)
{
    char buffer[1024] = {0};
    char *token;
    int solved = 0;
    while (!solved)
    {
        read(socket, buffer, 1024);
        token = strtok(buffer, "~");
        if (strcmp(buffer, resp) == 0)
        {
            solved = 1;
        }
        else
        {
            printf("Respuesta incorrecta: %s", token);
            sleep(1);
            clearScreen();
            printf(msg);
            if(aux == 6){
                printBasura();
            }else if(aux == 7){
                printThundercatsImage();
            }
        }
    }
    clearScreen();
}

//Lestoooo
void challenge0(int socket)
{
    clearScreen();
    char * msg = "Saludos aventurero. ¿Preparado para tener una experiencia progratastica? \n Envie \"entendido\" para continuar\n";
    printf(msg);
    checkResp(socket, responses[0], msg, 0);
}

//Lestoooo
void challenge1(int socket)
{
    char * msg = "------------- DESAFIO -------------\nHASHTAG left up up left down right down left ASTERISK\n";
    printf(msg);
    checkResp(socket, responses[1], msg, 1);
}

//Lestoooo
void challenge2(int socket)
{
    char * msg = "------------- DESAFIO -------------\nhttps://voca.ro/hcmH7cqyqTg\n";
    printf(msg);
    checkResp(socket, responses[2], msg, 2);
}

//Lestooo
void challenge3(int socket)
{
    char * msg = "------------- DESAFIO -------------\nEBADF...\n\nwrite: Bad file descriptor\n";
    printf(msg);
    writeOnFd();
    checkResp(socket, responses[3], msg, 3);
}

//cambiar el numerito al final
void challenge4(int socket)
{
    char * msg = "------------- DESAFIO -------------\nrespuesta = strings:63\n";
    printf(msg);
    checkResp(socket, responses[4], msg, 4);
}

//Lestooo
void challenge5(int socket)
{
    char * msg = "------------- DESAFIO -------------\n.data .bss .comment ? .shstrtab .symtab .strtab\n";
    printf(msg);
    checkResp(socket, responses[5], msg, 5);
}

//ver
void challenge6(int socket)
{
    char * msg = "------------- DESAFIO -------------\nmixed fds\n\n";
    printf(msg);
    printBasura();
    checkResp(socket, responses[6], msg, 6);
}

//Lestoooo
void challenge7(int socket)
{
    char * msg = "------------- DESAFIO -------------\n";
    printf(msg);
    printThundercatsImage();
    checkResp(socket, responses[7], msg,7);
}

//Lestoooo
void challenge8(int socket)
{
    char * msg = "------------- DESAFIO -------------\nTango Hotel India Sierra India Sierra Alfa Whiskey Echo Sierra Oscar Mike Echo\n\n";
    printf(msg);
    checkResp(socket, responses[8], msg, 8);
}

//ver
void challenge9(int socket)
{
    printf("------------- DESAFIO -------------\n");
    printf("quine\n");
    printf("\n");
    int hayQueSeguir = 1;
    while (hayQueSeguir)
    {
        if (access("quine.c", F_OK) != -1)
        {
            char* msg2 = "¡Genial!, ya lograron meter un programa en quine.c, veamos si hace lo que corresponde.\n";
            printf(msg2);
            checkQuine(socket);
            
            hayQueSeguir = 0;
        }
        else
        {
            char * msg1 = "no existe quine, enter para volver a chequear\n";
            printf(msg1);
            checkResp(socket, "\n", msg1, 9);
        }
    }
}

//Lestooò
void challenge10(int socket)
{
    char * msg = "------------- DESAFIO -------------\nb gdbme y encontrá el valor mágico\n";
    printf(msg);
    gdbme();
    checkResp(socket, responses[10], msg, 10);
}

void printBasura(){
    char aux[1];
    char ans[50] = "La respuesta es in_de_ter_mi_na_do\n";
    char * basura = randstring(350);
    for (int i = 0; i < 34; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            aux[0] = basura[(7 * i) + j];
            write(2, aux, 1);
        }
        aux[0] = ans[i];
        write(1, aux, 1);
    }
    free(basura); 

}

char *randstring(int length) {    
    static int mySeed = 25011984;
    char *string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
    size_t stringLen = strlen(string);        
    char *randomString = NULL;

    srand(time(NULL) * length + ++mySeed);

    if (length < 1) {
        length = 1;
    }

    randomString = malloc(sizeof(char) * (length +1));

    if (randomString) {
        short key = 0;

        for (int n = 0;n < length;n++) {            
            key = rand() % stringLen;          
            randomString[n] = string[key];
        }

        randomString[length] = '\0';

        return randomString;        
    }
    else {
        printf("No memory");
        exit(1);
    }
}

void printThundercatsImage()
{
    printf("Logo: \n");
    printf("\n");
    printf("___________________________________________(###############/___________________________________________\n");
    printf("____________________________________###.........................###____________________________________\n");
    printf("________________________________##...................................##________________________________\n");
    printf("____________________________##...........................................#&____________________________\n");
    printf("__________________________#.................................................#__________________________\n");
    printf("_______________________&#..........................................########...#/_______________________\n");
    printf("______________________#................................#################....##..#______________________\n");
    printf("____________________#..........................###############.........#########..#____________________\n");
    printf("___________________#......................###..##################################&.#___________________\n");
    printf("__________________#....................##....######################################.#__________________\n");
    printf("_________________#...................##...####################..&##################&.#_________________\n");
    printf("________________#.................##...############################&..##############.&#________________\n");
    printf("________________#.............&#######################################..#############.#________________\n");
    printf("_______________*#.........&#############################################.############.#________________\n");
    printf("_______________##......#################################################..###########.#(_______________\n");
    printf("_______________/#....####################...........#####################.###########.#._______________\n");
    printf("________________#.&#################..................##################..###########.#________________\n");
    printf("________________#....#############....................##################.&###########.#________________\n");
    printf("_________________##...#########.......................################..........####.#_________________\n");
    printf("_________________.#....#######........................##############&.............#.#__________________\n");
    printf("___________________#......####&......................###########...................#___________________\n");
    printf("____________________##......####....................########......................#____________________\n");
    printf("_____________________###.......###.................#######.....................###_____________________\n");
    printf("_______________________##........................#########.....#..............##_______________________\n");
    printf("_________________________##............&##&&##################..............##_________________________\n");
    printf("____________________________##..............################.............##____________________________\n");
    printf("_______________________________##...........#..##########.............##_______________________________\n");
    printf("___________________________________.##...........................##/___________________________________\n");
    printf("__________________________________________######&&...&#######__________________________________________\n");
}

void checkQuine(int socket)
{
    int hayQueSeguir = 1;
    int funka = 0;
    while (hayQueSeguir)
    {
        //compilar
        system("gcc -pedantic -std=c99 -Wall quine.c -o quine");
        //hacer chequeo
        funka = checkQuineFunction();
        if (funka)
        {
            char * msg = "La respuesta es chin_chu_lan_cha\n";
            printf(msg);
            checkResp(socket, responses[9], msg, 9);
            hayQueSeguir = 0;
        }
        else
        {
            char * msg = "no hace lo que corresponde, enter para volver a chequear\n";
            printf(msg);
            checkResp(socket, "\n",msg, 9);
        }
    }
}

int checkQuineFunction()
{
    int fd[2], pid;
    if (pipe(fd) < 0)
        error_print("atr");

    if ((pid = fork()) < 0)
        error_print("fork error");
    else if (pid == 0)
    { //Child
        char *arg_list[] = {"./quine", NULL};
        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]);
        execv("./quine", arg_list);
    }

    char ans[1000] = {0};
    read(fd[0], ans, 1000);
    printf("leimos %s\n", ans);
    char *scriptText = readFile("quine.c");
    printf("el archivitox dice %s\n", scriptText);
    close(fd[0]);
    close(fd[1]);
    int resp = !strcmp(ans, scriptText);
    free(scriptText);
    return resp;
}

char *readFile(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    char *code;
    size_t n = 0;
    int c;

    if (file == NULL)
        return NULL; //could not open file

    code = malloc(10000);

    while ((c = fgetc(file)) != EOF)
    {
        code[n++] = (char)c;
    }

    // don't forget to terminate with the null character
    code[n] = '\0';

    return code;
}

void clearScreen()
{
    system("clear");
}

void writeOnFd()
{
    int fd = open("sale_mal", O_CREAT);
    char *resp = "la respuesta es es_go_lo_dro_bo";
    write(fd, resp, strlen(resp));
    close(fd);
}

void gdbme()
{
    int aux1 = 1;
    int aux2 = 1;
    if (aux1 != aux2)
    {
        puts("la respuesta es gdb_manda\n");
    }
}

void error_print(char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}