/*
    gcc inet_ntoa.c -o ntoa
    ./ntoa
*/
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char* argv[])
{
    struct sockaddr_in addr1, addr2;
    char* str_ptr;
    char str_arr[20];

    addr1.sin_addr.s_addr = htonl(0x1020304);
    addr2.sin_addr.s_addr = htonl(0x1010101);

    str_ptr = inet_ntoa(addr1.sin_addr);
    strcpy(str_arr, str_ptr);
    printf("address1 32 bit: %#x \n", addr1.sin_addr.s_addr);
    printf("str_ptr: Dotted-Decimal notation1: %s \n", str_ptr);

    inet_ntoa(addr2.sin_addr);
    printf("str_ptr: Dotted-Decimal notation2: %s \n", str_ptr);
    printf("str_arr: Dotted-Decimal notation3: %s \n", str_arr);

    return 0;
}