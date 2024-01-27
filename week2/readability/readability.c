#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
int count_letters(string text);
int count_words(string text) ;
int count_scentences(string text);

int main(void)
{
    //get text from user
    string text = get_string("Text: ");

    int no_of_letters = count_letters(text) ;
    int no_of_words = count_words(text);
    int no_of_scentences = count_scentences(text);


    float l = (((float)no_of_letters / no_of_words) * 100);

    float s = (((float)no_of_scentences / no_of_words) * 100) ;

    float index = (0.0588 * l) - (0.296 * s) - 15.8 ;

    if ((int) round(index) > 15)
    {
         printf("Grade 16+\n");
    }
    else if ((int) round(index) < 2)
    {
         printf ("Before Grade 1\n");
    }
    else
    {
         printf ("Grade %i\n", (int) round(index));
    }


}



//function to count no of letters
int count_letters(string text)
{
    int i = 0 ;
    int counter = 0;
    while (text[i] != '\0')
    {
        // condition to count alpha only 
        if (text[i] != 32 && isalpha(text[i]) != 0)
        {
            counter ++;
        }
        i ++;
    }
    return counter ;
}
//function to count no of words
int count_words(string text)
{
    int i = 0 ;
    int counter = 0;
    while (text[i] != '\0')
    {
        //condition to check spaces
        if (text[i] == 32)
        {
           counter ++;
        }
        i ++;
    }
    counter ++ ;
    return counter ;
}
// function to count the no of scentences
int count_scentences (string text )
{
    int i = 0 ;
    int counter = 0;
    while (text[i] != '\0')
    {
        //condition to check . ! ?
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            counter ++ ;
        }
        i ++ ;
    }
    return counter ;
}



