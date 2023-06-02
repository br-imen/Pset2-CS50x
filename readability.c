#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentence(string text);
float count_index(double x, double y, double z);

int main(void)
{
    string text = get_string("text: ");
    int x = count_letters(text);
    int y = count_words(text);
    int z = count_sentence(text);
    int r = round(count_index(x, y, z));
    //printf ( "%i letters\n%i words\n%i sentences\n%i r \n", x,y,z,r);
// print grade
    if (r >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (r  < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", r);
    }


}

//count letters
int count_letters(string text)
{
    int l = 0 ;
    for (int i = 0, s = strlen(text) ; i < s ; i++)
    {
        if (isalpha(text[i]))
        {
            l++;
        }
    }
    return l;
}

//count words
int count_words(string text)
{
    int l = 1 ;
    for (int i = 0, s = strlen(text) ; i < s ; i++)
    {
        if (isspace(text[i]))
        {
            l++;
        }
    }
    return l;
}

//count sentence
int count_sentence(string text)
{
    char sentence[3] = {'.', '!', '?'};
    int s = strlen(text);
    int l = 0;
    for (int i = 0 ; i < s ; i++)
    {
        for (int j = 0 ; j < 3 ; j++)
        {

            if (sentence[j] == text[i])
            {
                l++;
            }

        }
    }
    return l;
}

//count the index
float count_index(double x, double y, double z)
{
    float L =  x / y * 100;
    float S = z / y * 100;
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    return index;
}

