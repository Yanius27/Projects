#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float count_index(int arr[]);

int main(void)
{
    //input text
    string text = get_string("Text: ");
    printf("\n");

    //calling function number 1
    int letters = count_letters(text);

    //calling function number 2
    int words = count_words(text);

    //calling function number 3
    int sentences = count_sentences(text);

    int arr[] = { letters, words, sentences };

    //calling the index function
    float n = count_index(arr);
    //output recommended student grade
    if (n < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (n > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int)roundf(n));
    }

}
//called function number 1
int count_letters(string text)
{
    int x = 0;
    for (int i = 0, a = strlen(text); i < a; i++)
    {
        if (isalpha(text[i]))
        {
            x += 1;
        }
        else
        {
            x += 0;
        }
    }
    return x;
}
//called function number 2
int count_words(string text)
{
    int y = 0;
    for (int i = 0, b = strlen(text); i < b; i++)
    {
        if (text[i] == 32)
        {
            y += 1;
        }
        else
        {
            y += 0;
        }
    }
    return y + 1;
}
//called function number 3
int count_sentences(string text)
{
    int z = 0;
    for (int i = 0, c = strlen(text); i < c; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            z += 1;
        }
        else
        {
            z += 0;
        }
    }
    return z;
}

//index function
float count_index(int arr[])
{
    float L = arr[0] / (float)arr[1] * 100;
    float S = arr[2] / (float)arr[1] * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}