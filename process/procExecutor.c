#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("To execute a program you need to pass additional arguments");
        return 1;
    }

    char *args[10];
    int argsI = 0;

    for (int i = 1; argv[i] != NULL; i++)
    {
        args[argsI++] = argv[i];
    }
    args[argsI] = NULL;

    execvp(args[0], args);

    perror("execvp");
    return 1;
}
