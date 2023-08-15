/*
    gcc gethostbyname.c -o hostname
    ./hostname www.baidu.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char* argv[])
{
    int i;
    struct hostent* host;

    host = gethostbyname(argv[1]);

    printf("Official name: %s \n", host->h_name);

    for (i = 0; host->h_aliases[i]; ++i)
    {
        printf("Aliases %d: %s \n", i+1, host->h_aliases[i]);
    }

    printf("Address type: %s \n", 
        (host->h_addrtype==AF_INET)? "IPv4" : "IPv6");
    
    for (i = 0; host->h_addr_list[i]; ++i)
    {
        // printf("%#x\n", *((struct in_addr*)host->h_addr_list[i]));
        printf("IP addr %d: %s \n", i+1,
            inet_ntoa(*(struct in_addr*)host->h_addr_list[i]));
    }

    return 0;
}