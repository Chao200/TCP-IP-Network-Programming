/*
    gcc uecho_server.c -o userver
    ./userver 9190
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFSIZE 30

int main(int argc, char* argv[])
{
    int serv_sock;
    char message[BUFSIZ];
    int str_len;
    socklen_t clnt_adr_sz;
    struct sockaddr_in serv_adr, clnt_adr;

    serv_sock = socket(PF_INET, SOCK_DGRAM, 0);
    
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_port = htons(atoi(argv[1]));

    bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr));

    while (1)
    {
        clnt_adr_sz = sizeof(clnt_adr);
        str_len = recvfrom(serv_sock, message, BUFSIZ,
                     0, (struct sockaddr*) &clnt_adr, &clnt_adr_sz);
        sendto(serv_sock, message, str_len, 
                    0, (struct sockaddr*) &clnt_adr, clnt_adr_sz);
    }
    close(serv_sock);
    return 0;
}