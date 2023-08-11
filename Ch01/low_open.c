/*
    gcc low_open.c -o lopen
    sudo ./lopen
    sudo cat data.txt
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void error_handling(char *message);

int main(void)
{
    int fd;
    char buf[] = "Let's go!\n";

    // 只写打开文件，如果不存在就创建，如果存在就删除现有数据
    fd = open("data.txt", O_CREAT|O_WRONLY|O_TRUNC);
    if (fd == -1)
    {
        error_handling("open() error");
    }
    printf("file descriptor: %d \n", fd);

    // 向 fd 中写入 buf 字符串
    if (write(fd, buf, sizeof(buf)) == -1)
    {
        error_handling("write() error\n");
    }

    close(fd);
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}