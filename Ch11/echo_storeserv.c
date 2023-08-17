#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/wait.h>
#define BUF_SIZE 100
// void error_handling(char *message);
void read_childproc(int sig);

int main(int argc, char* argv[])
{
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_ard;
    int fds[2];

    pid_t pid;
    struct sigaction act;
    socklen_t adr_sz;
    int str_len, state;
    char buf[BUF_SIZE];

    act.sa_handler = read_childproc;
    sigemptyset(&act.sa_mask);
    act.sa_mask = 0;
    state = sigaction(SIGCHLD, &act, 0);
}

// void error_handling(char *message)
// {
//     fputs(message, stderr);
//     fputc('\n', stderr);
//     exit(1);
// }

void read_childproc(int sig)
{
    pid_t pid;
    int status;
    pid = waitpid(-1, &status, WNOHANG);
    printf("removed proc id: %d \n", pid);
}