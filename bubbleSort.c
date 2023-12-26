#include <stdio.h>

void bubbleSort(int nums[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - 1 - i; j++)
    {
      if (nums[j] > nums[j + 1])
      {
        int temp = nums[j];

        nums[j] = nums[j + 1];
        nums[j + 1] = temp;
      }
    }
  }
}

int main()
{
  int nums[] = {4, 2, 3, 1};
  int size = sizeof(nums) / sizeof(nums[0]);

  bubbleSort(nums, size);

  for (int i = 0; i < size; i++)
  {
    printf("%d ", nums[i]);
  }

  printf("\n");

  return 0;
}
