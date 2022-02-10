#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//the main function requests command line arguments
int main(int argc, string argv[])
{
    //key verification
    if (argc == 2)
    {
        for (int i = 0, len1 = strlen(argv[1]); i < len1; i++)
        {
            if (isdigit(argv[1][i]) == false)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        //converting characters to numbers
        int key = atoi(argv[1]);

        //request for input of the source text
        string plaintext = get_string("plaintext: ");

        printf("ciphertext: ");
        //reading of source text and output of encoded text
        for (int n = 0, len2 = strlen(plaintext); n < len2; n++)
        {
            //encoding and output of uppercase letters
            if (isupper(plaintext[n]))
            {
                printf("%c", ((((plaintext[n] - 65) + key) % 26) + 65));
            }
            //encoding and output of lowercase letters
            else if (islower(plaintext[n]))
            {
                printf("%c", ((((plaintext[n] - 97) + key) % 26) + 97));
            }
            //output of non-alphabetic characters
            else
            {
                printf("%c", plaintext[n]);
            }
        }
        printf("\n");
        return 0;
    }
    //key verification
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}