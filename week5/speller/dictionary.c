// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<cs50.h>
#include<stdio.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
bool unload(void);
int counter = 0;
char Word[LENGTH + 1];
// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashnum = hash(word);
    node *head = table[hashnum];
    node *tmp = head;
    while(tmp)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
        tmp = tmp->next;
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
    // TODO
   FILE *input = fopen(dictionary, "r");

    if (input == NULL)
    {
      return false ;
    }

 while(fscanf(input ,"%s", Word)!=EOF)
 {
      //intialize new node
      node *n= malloc(sizeof(node));
      if(n == NULL)
      {
         unload();

         return false ;
      }

        //n->word=malloc(sizeof(strlen(Word)+1));

        //copy word into pointer
        strcpy(n->word, Word);
        n->next = NULL;

        int hashnum = hash(Word);

        if (table[hashnum] == NULL)
        {
            table[hashnum] = n;
            n->next = NULL;
        }
        else
        {
           n->next= table[hashnum];
           table[hashnum]= n;
        }
       counter ++ ;

 }
fclose(input);
 return true ;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return counter ;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for ( int i =0 ; i < N ; i ++)
    {
        node *cursor;

        cursor = table[i];

        while (cursor)
        {
              node *tmp = cursor ;
              cursor = cursor->next;
              free(tmp);

        }

       free(cursor);


    }

    return true;
}
