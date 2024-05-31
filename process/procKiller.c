#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *buffer = (char *)malloc(1024);
    bool run = true;
    bool procKilled = false;

    while (run)
    {
        if (procKilled)
        {
            procKilled = false;

            printf("Write 'exit' to end process or hit enter to continue ");

            fgets(buffer, 1024, stdin);
            buffer[strcspn(buffer, "\n")] = '\0';

            if (strcmp(buffer, "exit") == 0)
            {
                run = false;
                continue;
            }
        }

        printf("Insert PID to kill: ");

        fgets(buffer, 1024, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (kill(atoi(buffer), SIGKILL) == -1)
        {
            perror("Error");
        }
        else
        {
            procKilled = true;
            printf("Process killed\n");
        }
    }

    return 0;
}
