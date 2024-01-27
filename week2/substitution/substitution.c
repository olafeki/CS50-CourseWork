#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
bool norepeatedletters(string key);
bool alphacharac(string key);
int main(int argc, string argv[])
{
    string key = argv [1];
    //check number of arguments
    if (argc != 2)
    {
        printf ("Usage: ./substitution key\n");
        return 1  ;
    }
    //check key lenght
    else if (strlen(key) != 26)
    {
           printf("Key must contain 26 characters.\n");
           return 1 ;
    }
    //check repeated letters
    else if ( norepeatedletters (key)== false)
    {
           return 1 ;
    }
    //check non alpha charac
    else if ( alphacharac (key)== false)
    {
           return 1 ;
    }
    //normal case
    else
    {
        string plaintext = get_string("plaintext:");
        int x = 0 ;
        int n= strlen(plaintext);
        char array [n];

       for (int i =0 ; i < n ; i++)
       {
            x = (int) plaintext[i];
            //for perserve upper case
            if (x > 64 && x < 91)
            {
                array[i] = toupper(key [x - 65]) ;
            }
            // to perserve lower case
            else if (x > 96 && x < 123)
            {
                array[i] = tolower(key [x - 97]) ;
            }
            //for any non alpha char
            else
            {
                array [i] = plaintext [i] ;
            }
       }
         printf("ciphertext: ");
       for (int i =0 ; i < n ; i++)
       {
            printf ("%c",array[i]);
       }
         printf("\n");
     }
}

//to avoid repeated charc
bool norepeatedletters (string key)
{
   for (int i = 0, n = strlen(key); i < n; i++)
   {
      for (int k = i + 1; k < n; k++)
      {
           if (key[i] == key[k])
           {
               return false;
           }
      }
   }
   return true;
}
//to check non alpha charac
bool alphacharac (string key)
{
  for (int i =0 ; i < strlen(key); i++)
  {
    if (isalpha(key [i]) == 0 )
    {
        return false ;
    }
  }
 return true ;
}