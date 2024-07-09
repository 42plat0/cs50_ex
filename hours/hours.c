#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    //initializes the sum variable
    int sum = 0;
    //creates a loop which checks how many weeks there are and bases i on the week count
    for (int i = 0; i < weeks; i++){
        //adds up every hour to the sum
        sum += hours[i];
    }
    //when output is total, it returns the sum
    if (output == 'T')
    {
        return sum;
    }
    //when output is average, calculates average
    else if (output == 'A')
    {
        return sum / (float) weeks;
    }
    return 0;
}