// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(void)
{
     int hIndex;
     avg_temp placeholder;

     for (int i = 0; i < NUM_CITIES; i++)
     {
        hIndex = i;
        for(int j = i + 1; j < NUM_CITIES; j++)
        {
            if (temps[hIndex].temp < temps[j].temp)
            {
                hIndex = j;
            }
        }
        placeholder = temps[i];
        temps[i] = temps[hIndex];
        temps[hIndex] = placeholder;
     }
}

/*
    int length = 10;
    for (int i = 0; i < length - 1; i++)
    {
        int minimum_position = i;
        for (int j = i + 1; j < length; j++)
        {
            if (temps[j].temp < temps[minimum_position].temp)
            {
                minimum_position = j;
            }
            if (minimum_position != i)
            {
                int temporaryinteger = temps[i].temp;
                temps[i].temp = temps[minimum_position].temp;
                temps[minimum_position].temp = temporaryinteger;

                string temporaryInteger = temps[i].city;
                temps[i].city = temps[minimum_position].city;
                temps[minimum_position].city = temporaryInteger;
            }
        }
    }




 int counter = 1;
    avg_temp buffer;
    while (counter != 0)
    {
        counter = 0;
        for (int i = 0; i < NUM_CITIES; i++)
        {
            if (temps[i].temp < temps[i+1].temp) //jei pakeistume zenkla i daugiau ir pakeistume array length-1, gautume nuo maziuasio iki didziauiso
            {
                buffer = temps[i];
                temps[i] = temps[i + 1];
                temps[i+1] = buffer;
                counter++;
            }
        }
    }
*/