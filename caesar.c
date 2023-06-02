#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int only_digit(string argv);
char rotate(char x, int key);

//************************************************Main***********************************************************************************
int main(int argc, string argv[])

{
// argc one argument
    if (argc != 2)
    {
        printf("Usage: ./ceaser key\n");
        return 1;
    }

// argv only digit
    else if (only_digit(argv[1]) == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

// string key to int
    int key = atoi(argv[1]);

// get string plaintext
    string plain_text = get_string("Plaintext: ");

//taking every char from plain_text and print it rotated.
    int S = strlen(plain_text);

    printf("Ciphertext: ");
    for (int j = 0 ; j < S ; j++)
    {
        char x = plain_text[j];
        char r = rotate(x, key);
        printf("%c", r);
    }

    printf("\n");

    return 0;
}
//**********************************************************************************************************************************

// def fonction "only_digit" : to check argv is digit
int only_digit(string argv)
{

    for (int i = 0; i < strlen(argv); i++)
    {
        char A = argv[i];
        if (isdigit(A) == 0)
        {
            return 1;
        }
    }
    return 0;

}


//def fonction rotate
char rotate(char x, int key)

{

// condition x is alphabetic
    if (isalpha(x))

    {
// adding the key to (int) x and if the result (R) surpass ASCII upper/lowercase (Z), we substract 26 from result (R) until we got R =< ASCII(Z/z)
// Goal: initialize count again if we surpass ASCII (z/Z) from A/a.
        int R = (int) x + key;

        if (isupper(x))
        {
            while (R > 90)     // R > ASCII 'Z'
            {
                R = R - 26;
            }
            return x = (char) R;
        }
        else
        {
            while (R > 122)  // R > ASCII 'z'
            {
                R = R - 26;
            }
            return x = (char) R;
        }
    }

// char x not alphebetic we return the same char x without change.
    else
    {
        return x;
    }
}