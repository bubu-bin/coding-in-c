#include <stdio.h>
#include <stdbool.h>

void recursiveBubbleSort(int nums[], int index)
{
    if (index == 0)
        return;

    int count = 0;

    for (int i = 0; i < index - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            int temp = nums[i];
            nums[i] = nums[i + 1];
            nums[i + 1] = temp;
            count++;
        }
    }

    // Arr is sorted
    if (count == 0)
    {
        return;
    }

    recursiveBubbleSort(nums, index - 1);
}

int main()
{
    int nums[] = {3, 4, 1, 2, 5, 2, 8};
    int size = sizeof(nums) / sizeof(int);

    recursiveBubbleSort(nums, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d", nums[i]);
    }

    return 0;
}
