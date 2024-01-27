#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    //to know who is thw winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
// function to compute te score of each word (player)
int compute_score(string word)
{
    int score = 0;
    for (int i = 0, n = strlen(word) ; i < n ; i++)
    {
        char character = word[i];
        //for uppercase
        if (character > 64 && character < 91)
        {
            score += POINTS[character - 65];
        }
        //for lowercase
        else if (character > 96 && character < 123 )
        {
            score += POINTS[character - 97];
        }
        //not letters
        else
        {
           score += 0;
        }
    }
    return score ;
}
