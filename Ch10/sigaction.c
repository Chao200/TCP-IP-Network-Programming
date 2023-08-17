/*
    gcc sigaction.c -o sigaction
    ./sigaction
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void timeout(int sig)
{
    if (sig == SIGALRM) puts("Time out!");
    alarm(2);
}

int main(int argc, char* argv[])
{
    int i;
    struct sigaction act;
    // 信号函数指针
    act.sa_handler = timeout;
    // 初始化为 0
    sigemptyset(&act.sa_mask);
    // 初始化为 0
    act.sa_flags = 0;
    sigaction(SIGALRM, &act, 0);

    alarm(2);

    for (i = 0; i < 3; ++i)
    {
        puts("wait...");
        sleep(100);
    }
    return 0;
}