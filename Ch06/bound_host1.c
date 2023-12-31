/*
    gcc bound_host1.c -o host1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30

int main(int argc, char* argv[])
{
    int sock;
    char message[BUF_SIZE];
    struct sockaddr_in my_adr, your_adr;
    socklen_t adr_sz;
    int str_len, i;

    sock = socket(PF_INET, SOCK_DGRAM, 0);

    memset(&my_adr, 0, sizeof(my_adr));
    my_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    my_adr.sin_family = AF_INET;
    my_adr.sin_port = htons(atoi(argv[1]));

    bind(sock, (struct sockaddr*) &my_adr, sizeof(my_adr));

    for (i = 0; i < 3; ++i)
    {
        sleep(1);
        adr_sz = sizeof(your_adr);
        str_len = recvfrom(sock, message, BUF_SIZE, 0,
                (struct sockaddr*) &your_adr, &adr_sz);
        printf("Message %d : %s \n", i+1, message);
    }
    close(sock);
    return 0;
}
