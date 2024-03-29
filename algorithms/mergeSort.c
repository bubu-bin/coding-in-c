#include <stdio.h>

void merge(int nums[], int left, int mid, int right)
{
    int lLen = mid - left + 1;
    int rLen = right - mid;

    int lTemp[lLen], rTemp[rLen];

    // Copy elements into temp
    for (int i = 0; i < lLen; i++)
    {
        lTemp[i] = nums[left + i];
    }

    for (int i = 0; i < rLen; i++)
    {
        rTemp[i] = nums[mid + 1 + i];
    }

    int lIndex = 0;
    int rIndex = 0;
    int index = left;

    // Merge
    while (lIndex < lLen && rIndex < rLen)
    {
        if (lTemp[lIndex] <= rTemp[rIndex])
        {
            nums[index] = lTemp[lIndex];
            lIndex++;
        }
        else
        {
            nums[index] = rTemp[rIndex];
            rIndex++;
        }

        index++;
    }

    // Copy remaining elements
    while (lIndex < lLen)
    {
        nums[index++] = lTemp[lIndex++];
    }

    while (rIndex < rLen)
    {
        nums[index++] = rTemp[rIndex++];
    }
}

void mergeSort(int nums[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }
}

void printNums(int nums[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", nums[i]);
    }
}

int main(void)
{
    int nums[] = {4, 2, 3, 1, 9, 5, 100, 42, 8, 59, 23, 51, 55, 38};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    mergeSort(nums, 0, numsSize - 1);
    printNums(nums, numsSize);

    return 0;
}
