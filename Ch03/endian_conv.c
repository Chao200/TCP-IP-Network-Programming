/*
    gcc endian_conv.c -o conv   
    ./conv 
*/
#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
    // 端口号 2 字节，16 位，16 进制表示为 4 个数
    unsigned short host_port = 0x1234;
    unsigned short net_port;
    // IPv4 4 字节，32 位，16 进制表示为 8 个数
    unsigned long host_addr = 0x12345678;
    unsigned long net_addr;

    net_port = htons(host_port);
    net_addr = htonl(host_addr);

    printf("Host ordered port: %#x \n", host_port);
    printf("Network ordered port: %#x \n", net_port);
    printf("Host ordered address: %#lx \n", host_addr);
    printf("Network ordered address: %#lx \n", net_addr);

    return 0;
}