#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //asking for name and saying hello
    string name = get_string("What is your name? ");
    printf("hello, %s\n", name);
}