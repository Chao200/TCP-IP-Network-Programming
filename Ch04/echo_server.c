/*
    gcc echo_server.c -o eserver
    ./eserver 9190
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[])
{
    int serv_sock, clnt_sock;
    char message[BUF_SIZE];
    int str_len, i;

    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t clnt_adr_sz;

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));

    bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr));

    listen(serv_sock, 5);

    clnt_adr_sz = sizeof(clnt_adr);

    for (i = 0; i < 5; ++i)
    {
        clnt_sock = accept(serv_sock, (struct sockaddr*) &clnt_adr, &clnt_adr_sz);
        printf("Connected client %d \n", i+1);

        while ((str_len = read(clnt_sock, message, BUF_SIZE))!=0)
        {
            write(clnt_sock, message, str_len);
        }

        close(clnt_sock);
    }
    close(serv_sock);
    return 0;
}
