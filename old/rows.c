#include <stdio.h>
#include <cs50.h>

int get_size(void);
void printgrid(int p);

int main (void)
{
    int n = get_size();
    printgrid(n);
}

int get_size(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);
    return n;
}

void printgrid(int p)
{
    for (int i = 0; i < p; i++)
    {
        for(int j = 0; j < p; j++)
        {
        printf("#");
        }
    
        printf("\n");
    }
}