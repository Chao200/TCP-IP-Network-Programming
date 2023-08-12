/*
    gcc inet_aton.c -o aton
    ./aton
*/
#include <stdio.h>
#include <arpa/inet.h>
void error_handling(char* message);

int main(int argc, char* argv[])
{
    char *addr = "127.232.124.79";
    struct sockaddr_in addr_inet;

    if (!inet_aton(addr, &addr_inet.sin_addr))
    {
        error_handling("Conersion error");
    }
    else
    {
        printf("addr is: %s \n", addr);
        printf("Network ordered integer addr is: %#x \n", addr_inet.sin_addr.s_addr);
    }

    return 0;
}

void error_handling(char* message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}