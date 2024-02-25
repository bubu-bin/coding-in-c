#include <stdio.h>

int main()
{
    char operator;
    double firstNumber, secondNumber;
    double result;

    printf("Enter an operator (+, -, *, /):\n");
    scanf("%c", &operator);

    printf("Enter first number\n");
    scanf("%lf", &firstNumber);

    printf("Enter second number\n");
    scanf("%lf", &secondNumber);

    switch (operator)
    {
    case '+':
        result = firstNumber + secondNumber;
        break;
    case '-':
        result = firstNumber - secondNumber;
        break;
    case '*':
        result = firstNumber * secondNumber;
        break;
    case '/':
        result = firstNumber / secondNumber;
        break;
    default:
        printf("Error! operator: %c is not correct\n", operator);
    }

    printf("Result is %.2lf", result);

    return 0;
}
