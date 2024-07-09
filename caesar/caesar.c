#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2) // checks for the commandline argument count
    {
        printf("Usage: ./caesar key \n"); // shows how to use the key
        return 1;
    }

    for (int k = 0; k < strlen(argv[1]); k++) // checks for the arguments beside first argument after command
    {
        if (!isdigit(argv[1][k])) // if there is a second argument after the required one
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }
    }

    int keykey = atoi(argv[1]);                   // converts string to integer
    string plaintext = get_string("plaintext: "); // gets the string

    for (int j = 0; j < strlen(plaintext); j++) // to iterate between letters of the string
    {
        if (isalpha(plaintext[j])) // only changes the letters of the alphabet
        {
            if (islower(plaintext[j])) // command for the lower case letters
            {
                plaintext[j] =
                    (plaintext[j] - 'a' + keykey) % 26 +
                    'a'; // basically it starts from the beggining (0) and then adds the key, modulo just loops around the letters
                         // from a to z and the remainder of the modulo is added back to the first letter of the alphabet
            }

            if (isupper(plaintext[j])) // command for the lower case letters
            {
                plaintext[j] =
                    (plaintext[j] - 'A' + keykey) % 26 +
                    'A'; // basically it starts from the beggining (0) and then adds the key, modulo just loops around the letters
                         // from a to z and the remainder of the modulo is added back to the first letter of the alphabet
            }
        }
    }
    printf("ciphertext: %s\n", plaintext); //prints the text out changed
}
c