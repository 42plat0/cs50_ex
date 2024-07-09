#include <cs50.h>
#include <stdio.h>
#include <math.h>

int check_card(long card);
int multiply_sum(int last_digit);
int every_other_digit(long credit_card);
bool isValidAmex(long credit_card, int numDigits);
bool isValidMastercard(long credit_card, int numDigits);
bool isValidVisa(long credit_card, int numDigits);

int main(void)
{
    long cardnumber = get_long("Number: ");
    int sumeveryother = every_other_digit(cardnumber);
    int numDigits = check_card(cardnumber);

    bool amex = isValidAmex(cardnumber, numDigits);
    bool mc = isValidMastercard(cardnumber, numDigits);
    bool visa = isValidVisa(cardnumber, numDigits);


    if (sumeveryother % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (amex == true)
    {
        printf("AMEX\n");
    }
    else if (mc == true)
    {
        printf("MASTERCARD\n");
    }
    else if (visa == true)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int check_card(long card)
{
    int sum = 0;
    while (card > 0)
    {
        card = card / 10;
        sum++;
    }
    return sum;
}

int every_other_digit(long credit_card)
{
    int sum = 0;
    bool isAlternateDigit = false;
    while (credit_card > 0)
    {
        if (isAlternateDigit == true)
        {
            int last_digit = credit_card % 10; // gets the last digit of the number
            int product = multiply_sum(last_digit);
            sum += product;
        }
        else
        {
            int last_digit = credit_card % 10; // gets the last digit of the number
            sum += last_digit;
        }
        isAlternateDigit = !isAlternateDigit;
        credit_card = credit_card / 10; // removes the last digit of the number
    }
    return sum;
}

int multiply_sum(int last_digit)
{
    int multiply = last_digit * 2;
    int sum = 0;
    while (multiply > 0)
    {
        int last_digit_multiply = multiply % 10;
        sum += last_digit_multiply;
        multiply = multiply / 10;
    }
    return sum;
}

bool isValidAmex(long credit_card, int numDigits)
{
    int first_two_digits = credit_card / pow(10, 13);
    if ((numDigits == 15) && (first_two_digits == 34 || first_two_digits == 37))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isValidMastercard(long credit_card, int numDigits)
{
    int first_two_digits = credit_card / pow(10, 14);
    if ((numDigits == 16) && (first_two_digits >= 51 && first_two_digits <= 55))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isValidVisa(long credit_card, int numDigits)
{
    if (numDigits == 13)
    {
        int firstDigit = credit_card / pow(10, 12);
        if(firstDigit == 4)
        {
            return true;
        }
    }
    else if (numDigits == 16)
    {
        int firstDigit = credit_card / pow(10, 15);
        if(firstDigit == 4)
        {
            return true;
        }
    }else
    {
        return false;
    }
return 0;
}

