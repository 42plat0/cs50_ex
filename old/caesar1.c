#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }

    for (int k = 0; k < strlen(argv[1]); k++)
    {
        if (!isdigit(argv[1][k]))
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }
    }

    int keykey = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    int length = strlen(plaintext);

    for (int j = 0; j < length; j++)
    {
    
    printf("ciphertext: %s\n", plaintext);
}
