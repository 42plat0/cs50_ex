#include <stdio.h>
#include <cs50.h>


int main (void)
{
    int n = 100;
    char *p = &n;

    string s = "Hi!";
    string *a = &s;
   printf("%p\n", p);
}