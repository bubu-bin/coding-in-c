/*
 * This program demonstrates the creation and manipulation of a dynamically allocated array in C.
 * It includes:
 *   - Creating a pointer to dynamically allocate memory for an array of integers.
 *   - Populating the array with values.
 *   - Expanding the array to add a new element.
 *   - Proper memory management including handling allocation failures and freeing memory.
 */

#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("value is %d \n", arr[i]);
    }
}

int main()
{
    int size = 5;
    int *arr = malloc(size * sizeof(int));

    if (arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = i * 2;
    }

    int newValue = 10;
    size = size + 1;
    int *temp = realloc(arr, size * sizeof(int));

    if (temp == NULL)
    {
        free(arr);
        fprintf(stderr, "Memory reallocation failed\n");
        return 1;
    }

    temp[size - 1] = newValue;

    printArr(temp, size);

    free(temp);
    return 0;
}
