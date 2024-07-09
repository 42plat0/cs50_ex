// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool uppercase = false;
    bool digit = false;
    bool punct = false;
    bool lowercase = false;
    bool validation = false;

    int length = strlen(password);
    for (int i = 0; i < length; i++)
    {
        if (isupper(password[i])){
            uppercase = true;
        }
         if (islower(password[i])){
            lowercase = true;
        }
         if (isdigit(password[i])){
            digit = true;
        }
        if (ispunct(password[i])){
            punct = true;
        }
        if (punct == true && digit == true && uppercase == true && lowercase == true)
        {
            validation = true;
        }
    }
    return validation;
}
