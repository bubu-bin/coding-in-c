#include <stdbool.h>
#include <stdio.h>
#include <math.h>

/**
 * Requirments
 * - Your program should implement the binary search algorithm to find a target element in a sorted array
 * - The function should return the index of the target element if found, or -1 if not found.
 * - Your binary search should be implemented as a recursive function.
 * - You should handle cases where the target element is not in the array.
 * - Your program should display the result (index or "not found")
 */

int binarySearch(int target, int start, int end, int arr[])
{
    if (start > end)
    {
        return -1;
    }

    int mid = (start + end) / 2;
    int value = arr[mid];

    if (value == target)
    {
        return mid;
    }
    else if (value > target)
    {
        return binarySearch(target, start, mid - 1, arr);
    }
    else
    {
        return binarySearch(target, mid + 1, end, arr);
    }
}

int main()
{
    int sortedArray[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
    int size = sizeof(sortedArray) / sizeof(sortedArray)[0];
    int targetElement = 100;

    int index;
    index = binarySearch(targetElement, 0, size - 1, sortedArray);

    if (index == -1)
    {
        printf("target not found");
    }
    else
    {
        printf("target found at index %d", index);
    }

    return 0;
}
