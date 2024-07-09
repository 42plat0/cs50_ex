#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // print hashes
    for (int i = 0; i < n; i++)
    {
        for (int k = n; k > i + 1; k--)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");

        for (int x = 0; x <= i; x++)
        {
            printf("#");
        }
        printf("\n");
    }
}
