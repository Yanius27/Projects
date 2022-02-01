#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 - %d\n", score1);
        printf("Player 2 - %d\n", score2);
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 1 - %d\n", score1);
        printf("Player 2 - %d\n", score2);
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
}

int compute_score(string word)
{
    //compute score
    int score = 0;
    //arrays for upper and lower letters
    int up_letters[] = { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90 };
    int low_letters[] = { 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122 };
    //counter
    for (int i = 0; i < strlen(word); i++)
    {
        //condition for upper letters
        if (isupper(word[i]))
        {
            for (int n = 0; n < sizeof(up_letters); n++)
            {
                if (word[i] == up_letters[n])
                {
                    score += POINTS[n];
                }
            }

        }
        //condition for lower letters
        else if (islower(word[i]))
        {
            for (int n = 0; n < sizeof(low_letters); n++)
            {
                if (word[i] == low_letters[n])
                {
                    score += POINTS[n];
                }
            }
        }
        //defolt condition for non-letter characters
        else
        {
            i += 1;
        }
    }
    return score;
}