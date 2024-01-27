#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long card_number;
    int get_last_digit;
    int other_digit;
    int other_sum = 0;
    long start_number = 0;
    int checksum = 0;
    int counter = 0;

    bool visa_digits;
    bool amex_start;
    bool mastercard_start;

    //Get the card number
    card_number = get_long("Number: ");
    //Run the loop on all numb-s in card
    while (card_number != 0)
    {
        // last digit
        get_last_digit = card_number % 10;

        //Separete the other digits
        if (counter % 2 != 0)
        {
            //Multiply by two
            other_digit = get_last_digit * 2;

            //If the multiplication gets 2 digits than sum the digits
            other_sum += (other_digit % 100 == 0) ? other_digit :
                         other_digit % 10 + other_digit / 10;
        }
        else
        {
            //Sum of the digits not multp
            checksum += get_last_digit;
        }
        //Get's the start number
        if (card_number / 100 == 0 && start_number == 0)
        {
            start_number = card_number;
        }

        //Eliminate the last digit and increment the count
        card_number = card_number / 10;
        counter++;
    }
    //Get checksum last digit
    checksum = (checksum + other_sum) % 10;

    //conditions of every card
    visa_digits = counter == 13 || counter == 16;

    amex_start = start_number == 34 || start_number == 37;

    mastercard_start = start_number == 51 || start_number == 52 || start_number == 53 ||
                       start_number == 54 || start_number == 55;

    if (checksum == 0 && counter == 15 && amex_start)
    {
        printf("AMEX\n");
    }
    else if (checksum == 0 && visa_digits && start_number / 10 == 4 )
    {
        printf("VISA\n");
    }
    else if (counter == 16 && mastercard_start && checksum == 0 )
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}