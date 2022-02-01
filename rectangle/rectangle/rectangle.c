#include <cs50.h>
#include <stdio.h>
#include <math.h>

string valid_rectangle(int length1, int width1, int length2, int width2);

int main(void)
{
    //ask user for input
    int length1 = get_int("Please, enter length1: ");
    printf("\n");
    int width1 = get_int("Width1: ");
    printf("\n");
    int length2 = get_int("Length2: ");
    printf("\n");
    int width2 = get_int("Width2: ");
    printf("\n");
    //declaring string variables
    string solution;
    //calling the secondary function
    solution = valid_rectangle(length1, width1, length2, width2);

    //output the result
    printf("The solution is %s!\n", solution);
}

string valid_rectangle(length1, width1, length2, width2)
{
    //declaring variables for boolean expressions
    string x = "true";
    string y = "false";
    //exclude negative numbers
    if (length1 <= 0 || length2 <= 0 || width1 <= 0 || width2 <= 0)
    {
        return y;
    }
    //excluse incorrect numbers
    else if (length1 != length2 || width1 != width2 || length1 == width1)
    {
        return y;
    }
    //defolt return
    else
    {
        return x;
    }
}