#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define OPSZ 4

int calculate(int opnum, int opnds[], char oprator);

int main(int argc, char* argv[])
{
    int serv_sock, clnt_sock;
    char opinfo[BUF_SIZE];
    int result, opnt_cnt, i;
    int recv_cnt, recv_len;
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
        opnt_cnt = 0;
        clnt_sock = accept(serv_sock, (struct sockaddr*) &clnt_adr, &clnt_adr_sz);
        // 读取操作数个数
        read(clnt_sock, &opnt_cnt, 1);

        recv_len = 0;
        // 读取操作数
        while ((opnt_cnt*OPSZ+1)>recv_len)
        {
            recv_cnt = read(clnt_sock, &opinfo[recv_len], BUF_SIZE-1);
            recv_len += recv_cnt;
        }
        result = calculate(opnt_cnt, (int*)opinfo, opinfo[recv_len-1]);
        write(clnt_sock, (char*)&result, sizeof(result));
        close(clnt_sock);

        return 0;
    }
}

int calculate(int opnum, int opnds[], char op)
{
    int result = opnds[0], i;
    switch(op)
    {
        case '+':
            for (i = 1; i < opnum; ++i) result += opnds[i];
            break;
        case '-':
            for (i = 1; i < opnum; ++i) result -= opnds[i];
            break;
        case '*':
            for (i = 1; i < opnum; ++i) result *= opnds[i];
            break;
    }
    return result;
}


