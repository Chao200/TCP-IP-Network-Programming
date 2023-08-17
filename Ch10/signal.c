/*
    gcc signal.c -o signal
    ./signal
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void timeout(int sig)
{
    if (sig == SIGALRM) puts("Time out!");
    alarm(2);
}

void keycontrol(int sig)
{
    if (sig == SIGINT) puts("CTRL+C pressed");
}

int main(int argc, char* argv[])
{
    int i;
    signal(SIGALRM, timeout);
    signal(SIGINT, keycontrol);
    alarm(5);

    for (i = 0; i < 3; ++i)
    {
        puts("wait...");
        sleep(100);
    }
    printf("end\n");
    sleep(20);
    return 0;
}