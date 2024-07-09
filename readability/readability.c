#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    count_letters(text);
    count_words(text);
    count_sentences(text);

    float perhundredletters = (double)count_letters(text) / count_words(text) * 100;
    float perhundredsentences = (double)count_sentences(text) / count_words(text) * 100;

    float index = 0.0588 * (float)perhundredletters - 0.296 * (float)perhundredsentences - 15.8;

    int roundedindex = round(index);
    if (roundedindex > 16)
    {
        printf("Grade 16+\n");
    }
    if (roundedindex < 1)
    {
        printf("Before Grade 1\n");
    }
    if (roundedindex <= 16 && roundedindex > 1)
    {
        printf("Grade %i\n", roundedindex);
    }
//DOESNT HANDLE
//Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, "and what is the use of a book," thought Alice "without pictures or conversation?"


}
int count_letters(string text)
{
    int lettersum = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if(isalpha(text[i]))
        {
            lettersum++;
        }
    }
return lettersum;
}

int count_words(string text)
{
    int wordsum = 1;

    for (int i = 0; i < strlen(text); i++)
    {
        if(isblank(text[i]))
        {
            wordsum++;
        }
    }
    return wordsum;
}

int count_sentences(string text)
{
    int sentencesum = 0;
    char apo = '\'';
    char doubleapo = '\"';

    for (int i = 0; i < strlen(text); i++)
    {
        if(ispunct(text[i]) && text[i] != ',' && text[i] != ';' && text[i] != apo && text[i] != '-' && text[i] != ':' && text[i] != doubleapo)
        {
            sentencesum++;
        }
    }
    return sentencesum;
}
