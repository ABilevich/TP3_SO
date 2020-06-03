// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include "myserver.h"



char * responses[11] = {
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

int startServer(){
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
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
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
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 

    return new_socket; 
}

void awaitMessages(int socket){
    clearScreen();
    // challenge0(socket);
    // challenge1(socket);
    // challenge2(socket);
    // challenge3(socket);
    // challenge4(socket);
    // challenge5(socket);
    // challenge6(socket);
    // challenge7(socket);
    // challenge8(socket);
    challenge9(socket);
    challenge10(socket);
    printf("ganaste!!\n");
}

void checkResp(int socket, char * resp){
    char buffer[1024] = {0}; 
    char *token;
    int solved = 0;
    while(!solved){ 
        read(socket , buffer, 1024);
        token = strtok(buffer, "~");
        if(strcmp(buffer,resp) == 0){
            solved = 1;
        }else{
            printf("Respuesta incorrecta: %s",token);
            // sleep(1);
            // printf("%c[2K", 27);
        }
    }
    clearScreen();
}

//Lestoooo
void challenge0(int socket){
    printf("mensajesito de bienvenida, envie \"entendido\" para continuar\n");
    checkResp(socket, responses[0]);
}

//Lestoooo
void challenge1(int socket){
    printf("------------- DESAFIO -------------\n");
    printf("HASHTAG left up up left down right down left ASTERISK\n");
    checkResp(socket, responses[1]);
}

//Lestoooo
void challenge2(int socket){
    printf("------------- DESAFIO -------------\n");
    printf("https://voca.ro/hcmH7cqyqTg\n");
    checkResp(socket, responses[2]);
}

//Lestooo
void challenge3(int socket){
    printf("------------- DESAFIO -------------\n");
    printf("EBADF...\n");
    printf("\n");
    printf("write: Bad file descriptor\n");
    writeOnFd();
    checkResp(socket, responses[3]);
}

//cambiar el numerito al final
void challenge4(int socket){
    printf("------------- DESAFIO -------------\n");
    printf("respuesta = strings:377\n"); 
    checkResp(socket, responses[4]);
}

//Lestooo
void challenge5(int socket){
    printf("------------- DESAFIO -------------\n");
    printf(".data .bss .comment ? .shstrtab .symtab .strtab\n");

    checkResp(socket, responses[5]);
}

//ver
void challenge6(int socket){
    printf("------------- DESAFIO -------------\n");
    printf("mixed fds\n");
    printf("\n");
    char aux[1];
    char ans[50] = "La respuesta es in_de_ter_mi_na_do\n";
    char basura[350] = "A.hsO`h[62]VY^9a97< -:G]WFn2+<grbk2s07\"4Ie0J4sPtpTY$?l5u({W_lV,R)Uyx=@*+3]e=4aJ$p~>d50`Q\"sgkt*c<|*os8$O4Ra}YkmPY=a3cz*B^Ye/arQg!2|OsP1@3#sh9^qk-u#o< 3inkd,Ns*d8>#deR?Rg~w,*y_%42t2AcgHe.|?a\"eiErXd%_ehm$N`ecW6fi_&)iqni[RV|^;-F VaU6g%gYv\\#\"d;97Nz(tmAo-hWN{<f>BfZ$gy^t;p!Kkjfh'lsfmlaskfdj;laskfj;lsakfjl;ksadjfl;sjfl;ksajf;sfl";
    for(int i = 0; i < 34; i++){
        for(int j = 0; j < 7; j++){
               sprintf(aux, "%c", basura[(7*i)+j]);
               write(2, aux, 1);
        } 
        sprintf(aux, "%c", ans[i]);
        write(1, aux, 1);
    }
    checkResp(socket, responses[6]);
}


//Lestoooo
void challenge7(int socket){
    printf("------------- DESAFIO -------------\n");
    printThundercatsImage();
    checkResp(socket, responses[7]);
}

//Lestoooo
void challenge8(int socket){
    printf("------------- DESAFIO -------------\n");
    printf("Tango Hotel India Sierra India Sierra Alfa Whiskey Echo Sierra Oscar Mike Echo\n");
    printf("\n");
    checkResp(socket, responses[8]);
}

//ver
void challenge9(int socket){
    printf("------------- DESAFIO -------------\n");
    printf("quine\n");
    printf("\n");
    int hayQueSeguir = 1;
    while(hayQueSeguir){
        if( access( "quine.c", F_OK ) != -1 ) {
            printf("¡Genial!, ya lograron meter un programa en quine.c, veamos si hace lo que corresponde.\n");
            checkQuine(socket);
            checkResp(socket, responses[9]);
            hayQueSeguir = 0;
        } else {
            printf("no existe quine, enter para volver a chequear\n");
            checkResp(socket, "\n");
        }
    }
}

//Lestooò
void challenge10(int socket){
    printf("------------- DESAFIO -------------\n");
    printf("b gdbme y encontrá el valor mágico\n");
    gdbme();
    checkResp(socket, responses[10]);
}

void printThundercatsImage(){
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

void checkQuine(int socket){
    int hayQueSeguir = 1;
    int funka = 0;
    while(hayQueSeguir){
        //compilar
        system("gcc -pedantic -std=c99 -Wall quine.c -o quine");
        //hacer chequeo
        funka = checkQuineFunction();
        if(funka) {
            printf("La respuesta es chin_chu_lan_cha\n");
            hayQueSeguir = 0;
        } else {
            printf("no hace lo que corresponde, enter para volver a chequear\n");
            checkResp(socket, "\n");
        }
    }
}

int checkQuineFunction(){
    int fd[2], pid;
    if (pipe(fd) < 0) error_print("atr");

    if ( (pid = fork()) < 0) error_print("fork error");
    else if(pid == 0){                  //Child
        char * arg_list[] = {"./quine",NULL};
        dup2(fd[1],1);
        close(fd[0]);       
        close(fd[1]);       
        execv("./quine", arg_list);
    }
    
    //sleep(1);
    
    int i = 0;
    char c;
    char ans[10000];
    read(fd[0], ans, 1000);
    // while (read(fd[0], &c, 1) > 0) {
    //     ans[i++] = c;
    //     printf("%c",c);
    // }
    // ans[i] = '\0';
    printf("leimos %s\n", ans);
    char * scriptText = readFile("quine.c");
    printf("el archivitox dice %s\n", scriptText);
    close(fd[0]);       
    close(fd[1]);
    return !strcmp(ans, scriptText);
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
        code[n++] = (char) c;
    }

    // don't forget to terminate with the null character
    code[n] = '\0';        

    return code;
}


void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

void writeOnFd(){
    int fd = open("sale_mal",O_CREAT);
    char * resp = "la respuesta es es_go_lo_dro_bo";
    write(fd,resp,strlen(resp));
    close(fd);
}

void gdbme(){
    int aux1 = 1;
    int aux2 = 1;
    if(aux1 != aux2){
        puts("la respuesta es gdb_manda\n");
    }
}

void error_print(char * message){
   perror(message);
   exit(EXIT_FAILURE);
}