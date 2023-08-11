/*
    gcc fd_seri.c -o fds
    sudo ./fds
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>

int main(void)
{
    int fd1, fd2, fd3;
    // TCP
    fd1 = socket(PF_INET, SOCK_STREAM, 0);
    // 文件
    fd2 = open("test.dat", O_CREAT|O_WRONLY|O_TRUNC);
    // UDP
    fd3 = socket(PF_INET, SOCK_DGRAM, 0);

    // 输出为 3, 4, 5
    printf("file descriptor 1: %d\n", fd1);
    printf("file descriptor 2: %d\n", fd2);
    printf("file descriptor 3: %d\n", fd3);

    close(fd1); close(fd2); close(fd3);
    return 0;
}