#include <stdio.h>

/**
 * @Note: Recursive maximum index finder
 */

int prefixMax(int *arr, int i)
{
    if (i > 0)
    {
        int j = prefixMax(arr, i - 1);

        if (arr[i] < arr[j])
        {
            return j;
        }
    }

    return i;
}

int main()
{
    int nums[] = {5, 2, 1, 1, 10, 2, 1, 10};
    int lastIndex = (sizeof(nums) / sizeof(int)) - 1;
    int maxNumIndex = prefixMax(nums, lastIndex);

    printf("max num index is %d with value %d", maxNumIndex, nums[maxNumIndex]);
    return 0;
}
