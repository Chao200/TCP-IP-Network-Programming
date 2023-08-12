// 获取字节序

/*
    gcc order.c
    ./a.out
*/

#include <stdio.h>
#include <arpa/inet.h>

int main()
{
    // ####### 方法一 #######
    printf("####### Method 1: #######\n");
    unsigned short host_port = 0x1234;
    unsigned short net_port;
    net_port = htons(host_port);
    printf("Host ordered port: %#x \n", host_port);
    printf("Network ordered port: %#x \n", net_port);

    // ####### 方法二 #######
    printf("####### Method 2: #######\n");
    int a = 0x12345678;
    char b = a;
    printf("a = %#x \n", a);
    printf("b = %#hx \n", b);

    // ####### 方法三 #######
    printf("####### Method 3: #######\n");
    union byteorder
    {
        int a;
        char b;
    }t;
    t.a = 0x12345678;
    printf("a = %#x \n", t.a);
    printf("b = %#hx \n", t.b);

    // ####### 方法四 #######
    printf("####### Method 4: #######\n");
    int m = 0x12345678;
    char* ptr = NULL;
    ptr = (char *) &m;
    printf("m = %#x \n", m);
    printf("n = %#hx \n", *ptr);
}