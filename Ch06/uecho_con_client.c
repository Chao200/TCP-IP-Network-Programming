/*
    gcc uecho_con_client.c -o uconclient
    ./uconclient 127.0.0.1 9190
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
    int sock;
    char message[BUFSIZ];
    int str_len;
    socklen_t adr_sz;

    // from_adr 存储发送端的信息
    struct sockaddr_in serv_adr, from_adr;

    sock = socket(PF_INET, SOCK_DGRAM, 0);

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_port = htons(atoi(argv[2]));

    connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr));

    while (1)
    {
        fputs("Insert message(q to quit): ", stdout);
        fgets(message, sizeof(message), stdin);
        if (!strcmp(message, "q\n") || !strcmp(message, "Q\n")) break;

        // sendto(sock, message, strlen(message), 0,
        //         (struct sockaddr*) &serv_adr, sizeof(serv_adr));

        write(sock, message, strlen(message));

        // adr_sz = sizeof(from_adr);
        // str_len = recvfrom(sock, message, BUFSIZ, 0,
        //         (struct sockaddr*) &from_adr, &adr_sz);

        str_len = read(sock, message, sizeof(message)-1);

        message[str_len] = 0;
        printf("Message from server: %s", message);
    }
    close(sock);
    return 0;
}