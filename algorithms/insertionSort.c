#include <stdio.h>

void insertionSort(int nums[], int size)
{
  for (int i = 1; i < size; i++)
  {
    for (int j = i; j > 0; j--)
    {
      if (nums[j - 1] > nums[j])
      {
        int temp = nums[j - 1];
        nums[j - 1] = nums[j];
        nums[j] = temp;
      }
      else
      {
        break;
      }
    }
  }
}

void printNums(int nums[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d", nums[i]);
  }
}

int main()
{
  int nums[] = {1};
  int size = sizeof(nums) / sizeof(nums[0]);

  insertionSort(nums, size);
  printNums(nums, size);

  return 0;
}
