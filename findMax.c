#include <stdio.h>

int findMax(int nums[], int size)
{
  int max = nums[0];

  for (int i = 0; i <= size - 1; i++)
  {
    if (nums[i] > max)
    {
      max = nums[i];
    }
  }
  return max;
}

int main()
{
  int nums[] = {4, 2, 3, 1, 5, 9, 8, 7, 6, 1231};
  int size = sizeof(nums) / sizeof(nums[0]);

  int max = findMax(nums, size);

  printf("Max is %d\n", max);

  return 0;
}
