#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>


int main (void)
{
    char *p = get_string("p :");

    char *t = malloc(strlen(p) + 1);

    for (int i = 0; i < strlen(p) + 1; i ++)
    {
        t[i] = p[i];
    }

        t[0] = toupper(t[0]);

        printf("%s\n", p);
        printf("%s\n", t);

}