#include <cs50.h>
#include <stdio.h>

int times_two(long digit);

int main(void)
{
    //Getting card number
    long num = get_long("Enter your card number: ");

    //Checksum
    long first = 100;
    long second = 10;
    long third = 1000;
    int sum1 = num % 10;
    //i = 20 because beyond 19 digits wont work with long anyway
    for (int i = 1; i < 20; i++)
    {
        if (i % 2 == 0)
        {
            //getting every other digit starting from second last
            long digit = (num % first - num % second) / second;
            //times two
            int product = times_two(digit);
            // separate products into digits and adding them all
            if (product / 10 >= 1)
            {
                int digit2 = (product - product % 10) / 10;
                int digit3 = product % 10;
                sum1 = sum1 + digit2 + digit3;
            }
            else
            {
                sum1 = sum1 + product;
            }
            first = first * 100;
            second = second * 100;
        }
        //getting remaining digits
        else
        {
            long digit5 = (num % third - num % first) / first;
            sum1 = sum1 + digit5;
            third = third * 100;
        }
    }

    //card conditions
    if (sum1 % 10 == 0)
    {
        //AMEX
        if ((num - num % 10000000000000) / 10000000000000 == 34 || (num - num % 10000000000000) / 10000000000000 == 37)
        {
            printf("AMEX\n");
        }
        //MASTERCARD
        else if ((num - num % 100000000000000) / 100000000000000 == 51 || (num - num % 100000000000000) / 100000000000000 == 52
                 || (num - num % 100000000000000) / 100000000000000 == 53 || (num - num % 100000000000000) / 100000000000000 == 54
                 || (num - num % 100000000000000) / 100000000000000 == 55)
        {
            printf("MASTERCARD\n");
        }
        //VISA
        else if ((num - num % 1000000000000) / 1000000000000 == 4 || (num - num % 1000000000000000) / 1000000000000000 == 4)
        {
            printf("VISA\n");
        }
        //OTHER
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

//multiplying by two
int times_two(long digit)
{
    long product = digit * 2;
    return product;
}