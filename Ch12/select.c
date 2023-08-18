#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>
#define BUF_SIZE 38

int main(int argc, char* argv[])
{
    fd_set reads, temps;
    int result, str_len;
    char buf[BUF_SIZE];
    struct timeval timeout;

    FD_ZERO(&reads);
    FD_SET(0, &reads);

    /*
    timeout.tv_sec = 5;
    timeout.tv_usec = 5000;
    */

    while (1)
    {
        temps = reads;
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
    }
    return 0;
}