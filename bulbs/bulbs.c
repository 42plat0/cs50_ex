#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string input = get_string("Message: ");
    int length = strlen(input);

    // takes each character of the string
    for (int i = 0; i < length; i++)
    {
        int tobinary = input[i];  // translates each letter to ASCII
        int binary[BITS_IN_BYTE]; // instantiates an array of 8 characters
        int index = 0;            // index for inserting later binary digits into the array

        // calculates binary numbers and adds them to the array
        for (int j = 0; j <= BITS_IN_BYTE; j++)
        {
            int binaryDigit = tobinary % 2; // gets one binary digit
            binary[index] = binaryDigit;    // adds it to the array from the beggining
            tobinary = tobinary / 2;        // divides the number by half
            index++;                        // moves onto the next character of an array
        }

        // prints binary numbers from the last one to the first
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(binary[k]); // prints lightbulbs
        }

        printf("\n");
    }
    return 0;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
