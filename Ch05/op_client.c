#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define RLT_SIZE 4
#define OPSZ 4

int main(int argc, char* argv[])
{
    int sock;
    char opmsg[BUF_SIZE];
    int result, opnd_cnt, i;
    struct sockaddr_in serv_adr;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_adr.sin_port = htons(atoi(argv[2]));

    connect(sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr));
    
    fputs("Operand count: ", stdout);
    scanf("%d", &opnd_cnt);
    // 操作数的个数，转为 char 一个字节
    opmsg[0] = (char) opnd_cnt;

    for (i = 0; i < opnd_cnt; ++i)
    {
        printf("Operand %d:", i+1);
        scanf("%d", (int *)&opmsg[i*OPSZ+1]);
    }

    fgetc(stdin);
    fputs("Operator: ", stdout);
    // 操作符，+-*/
    scanf("%c", &opmsg[opnd_cnt*OPSZ+1]);

    // 写入 socket 中
    write(sock, opmsg, opnd_cnt*OPSZ+2);
    // 读取结果
    read(sock, &result, RLT_SIZE);

    printf("Operation result: %d \n", result);
    close(sock);
    return 0;
}