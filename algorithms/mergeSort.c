#include <stdio.h>

/**
 * how to split into two halves? - take size, divide by two 8 => 4, now from 1 to that and another from 4 + 1 to size
 * how to merge them back
 * how to compare elements
 * how to split array in c
 */

void mergeSort(int nums[], int left, int right)
{
    printf("[LEFT]: %d, [RIGHT]: %d\n", left, right);

    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
    }
    else
    {
        puts("base case reached");
    }
}

int main(void)
{
    int nums[] = {4, 2, 3, 1, 4, 5, 9, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    mergeSort(nums, 0, numsSize - 1);

    /* code */
    return 0;
}
