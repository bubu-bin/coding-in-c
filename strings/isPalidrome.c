#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

/**
 * Requirements:
 * - Your function should take a single `const char*` as input representing the string to check.
 * - It should return 1 (for true) if the string is a palindrome, 0 (for false) otherwise.
 * - The function must be recursive; it should call itself.
 * - You should not use any built-in functions like `strrev()` to reverse the string.
 * - Consider edge cases such as empty strings and strings with only one character.
 * - The function should be case-insensitive and ignore spaces and punctuation.
 * - You may write auxiliary functions if necessary, but the palindrome checking must be done recursively.
 * - You may use the C standard library functions `tolower()` to handle case insensitivity, and `isalpha()` to check for alphabetic characters.
 */

char *testExpressions[] = {
    "A man a plan a canal Panama",  // Is palindrome
    "No lemon, no melon",           // Is palindrome
    "Was it a car or a cat I saw?", // Is palindrome
    "No 'x' in Nixon",              // Is palindrome
    "Hello, World!",                // Not a palindrome
    "",                             // Is palindrome (empty string is considered a palindrome)
    "Madam In Eden, I'm Adam",      // Is palindrome
    "Step on no pets",              // Is palindrome
    "12321",                        // Is palindrome
    "123456",                       // Not a palindrome
    "Madam, I'm Adam",              // Is palindrome
    "A Toyota's a Toyota",          // Is palindrome
    "Not a palindrome",             // Not a palindrome
    "Race fast, safe car",          // Is palindrome
    "Never odd or even.",           // Is palindrome
    "x"};                           // Is palindrome

bool compare(char str[], int start, int end)
{
    if (start > end)
    {
        return true;
    }

    if (str[start] != str[end])
    {
        return false;
    }

    return compare(str, start + 1, end - 1);
}

bool isPalindrome(char str[])
{
    int length = strlen(str);

    if (length == 0)
    {
        return true;
    }

    if (length == 1)
    {
        return true;
    }

    char strInput[length];
    int strIndex = 0;

    for (int i = 0; i < length; i++)
    {

        if (!isalnum(str[i]))
        {
            continue;
        }

        strInput[strIndex++] = tolower(str[i]);
    }

    strInput[strIndex] = '\0';

    return compare(strInput, 0, strIndex - 1);
}

int main()
{

    for (int i = 0; i < sizeof(testExpressions) / sizeof(testExpressions[0]); i++)
    {

        bool result = isPalindrome(testExpressions[i]);
        printf("Expression %s is %s palindrome.\n", testExpressions[i], result ? "a" : "not");
    }

    return 0;
}
