#include <cs50.h>
#include <stdio.h>

void PRINTBLOCKS (int n );

int main(void)
{
   int n = 0 ;
   bool b = true  ;
    while (b)
    {
        n = get_int("Height : ");
        if (n > 0 && n < 9)
        {
            b = false ;
            PRINTBLOCKS(n);
        }
    }
}
// function to print the blocks
void PRINTBLOCKS (int n)
{
    // to print n row
    for (int j = 1 ; j < (n + 1) ; j++)
    {
        //to leave(n-j) spaces at the beginning
        for (int i = 0 ; i < (n - j) ; i++)
        {
            printf(" ");
        }
        // to print the blocks at left side
        for (int i = 0 ; i < j ; i++)
        {
            printf("#");

        }

        printf("  ");
        //to print the blocks at right side
        for (int i = 0 ; i < j ; i++)
        {
            printf("#");
        }
        // to leave a line between each row
        printf("\n");

    }

}