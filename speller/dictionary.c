// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dictionary.h"
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

unsigned int wordCount = 0;


// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int index = hash(word);

    node *current = table[index];
    // printf("Checking word: %s at index: %u\n", word, index); // Debug print
    while(current != NULL)
    {
        size_t len = strcspn(current->word, "\n");
        if (strncasecmp(current->word, word, len) == 0 && word[len] == '\0')
        {
            return true;
        }
        current = current->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open dictionary
    FILE *source = fopen(dictionary, "r");

    if (source == NULL)
    {
        return false;
    }
    // reading line by line, max 256 bytes
    char buffer[LENGTH + 1];

    // Initialize hash table
    for (int i = 0; i < N; i++) {
        table[i] = NULL;
    }

    //read each word of dictionary
    while(fgets(buffer, LENGTH + 1, source))
    {
        //allocate memory for node
        node *n = malloc(sizeof(node));
        if (n == NULL){
            return false;
        }

        //add word to node
        strcpy(n->word, buffer);
        n->next = NULL;

        //hash word
        unsigned int index = hash(buffer);

        //add word to hash table
        if (table[index] == NULL)
        {
            table[index] = n;
        //on collision make a linked list
        }
        else
        {
            n->next = table[index];
            table[index] = n;
        }
        wordCount++;
    }
    fclose(source);
    // close dictionary fyile
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return wordCount;

}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO: Handle base case
    node *current;
    node *next_node;

    for (int i = 0; i < N; i++)
    {
        current = table[i];
        while (current != NULL)
        {
            next_node = current->next;
            free(current);
            current = next_node;
        }
        if(i == N - 1)
        {
            return true;
        }
    }
    // TODO
    return false;
}
