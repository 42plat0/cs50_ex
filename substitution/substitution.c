#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string key = "VCHPRZGJNTLSKFBDQWAXEUYMOI";

int main(int argc, string argv[])
{
    if (argc != 2) // if there are not only 2 arugments;
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    for (int k = 0; k < strlen(argv[1]); k++)
    {
        if (!isalpha(argv[1][k])) // if the argument is not alphabetical symbols;
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }
        if (strlen(argv[1]) != 26) // if the argument is more or less than 26 charaters which key requires;
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

        for (int j = k + 1; j < strlen(argv[1]);
             j++) // this nested for loop checks each letter and looks for the duplicates, if there is duplicate it says so;
        {
            if (argv[1][k] == argv[1][j])
            {
                printf("No duplicate letters!\n");
                return 1;
            }
        }
    }

    string plaintext = get_string("plaintext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                int index = plaintext[i] - 'A'; // starts from the zero like a,b,c,d, etc.
                plaintext[i] = argv[1][index];  // indexes how many letters its in the other position and makes plaintext turn into
                                               // letters the ones which are provided by the key
                plaintext[i] = toupper(argv[1][index]); // turns letters into the uppercase letters
            }
            if (islower(plaintext[i])) // for lowercase letters
            {
                int index = plaintext[i] - 'a';
                plaintext[i] = tolower(argv[1][index]); // turns letters into the lowercase letters
            }
        }
    }
    printf("ciphertext: %s\n", plaintext); // prints the text out changed
    return 0;
}