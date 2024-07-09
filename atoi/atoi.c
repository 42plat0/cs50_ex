#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    int length = strlen(input);

    if (length == 1)
    {
        return (input[0] - 48);
    }
    else
    {
        int lastnumber = input[length - 1] - 48; //last character in the stirng and atimti ascii table value
        input[length - 1] = '\0'; //remove last char from the string by moving the null terminator one position to the left
        return (lastnumber + 10 * convert(input));
    }
}