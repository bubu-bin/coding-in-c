#include <stdio.h>

/**
 * This program demonstrates how to manually copy a string in C.
 */

int main()
{
    char str[6] = "Hello";
    char copiedStr[6];

    for (int i = 0; str[i] != '\0'; i++)
    {
        copiedStr[i] = str[i];
    }

    copiedStr[sizeof(str) - 1] = '\0';

    printf("Value is: %s", copiedStr);

    /* code */
    return 0;
}
