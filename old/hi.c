#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string s = "HI!";
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        printf("%i\n", s[i]);
    }
}