#include <stdio.h>

int recursiveSum(int num, int max)
{
    if (num == 10)
    {
        return num;
    }

    int result = recursiveSum(num + 1, max);
    return result + num;
}

int main()
{
    int sum = recursiveSum(0, 12);
    printf("sum is %d", sum);
    return 0;
}
