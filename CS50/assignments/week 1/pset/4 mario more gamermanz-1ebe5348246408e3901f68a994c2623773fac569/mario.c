#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //getting input for height
    int height;
    do
    {
        height = get_int("Enter height: ");
    }
    while (height > 8 || height < 1);
    //printing pyramind of height

    //for each row
    for (int i = 0; i < height; i++)
    {
        //spaces in each row
        for (int j = height - 1; j > i; j--)
        {
            printf(" ");
        }
        // left side hashes in each row
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        //space
        printf("  ");
        // right side hashes in each row
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}