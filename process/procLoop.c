#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sigint_handler(int sig)
{
    printf("BYE\n");
    exit(0);
}

int main(int argc, char const *argv[])
{
    signal(SIGINT, sigint_handler);
    pid_t pid = getpid();
    printf("Process ID: %d\n", pid);

    while (1)
    {
        printf("PLS DONT KILL ME!\n");
        sleep(1);
    }

    return 0;
}
