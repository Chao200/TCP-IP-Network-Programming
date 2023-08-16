/*
    gcc wait.c wait
    ./wait
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int status;
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Here1\n");
        return 3;
    }
    else
    {
        printf("Child1 PID: %d \n", pid);
        pid = fork();
        if (pid == 0)
        {
            printf("Here2\n");
            exit(7);
        }
        else
        {
            printf("Child2 PID: %d \n", pid);
            wait(&status);
            if (WIFEXITED(status))
            {
                printf("Child send one: %d \n", WEXITSTATUS(status));
            }
            wait(&status);
            if (WIFEXITED(status))
            {
                printf("Child send two: %d \n", WEXITSTATUS(status));
            }
            sleep(10);
        }
    }
}