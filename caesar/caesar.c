#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void cipher(string, int);

int main(int argc, string argv[])
{
    // lack check
    if (argc <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    // Checking if is only 1 argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;

    }

    // Numeric value check
    for (int i = 0; i < strlen(argv[1]); i ++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }


    // Positive values check
    if (atoi(argv[1]) < 1)
    {
        printf("Key must a be positive number!\n");
        return 1;

    }

    // Converting ascii to int
    int k = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");

    // printing the ciphred message
    printf("ciphertext: ");
    cipher(plaintext, k);

    return 0;


}

void cipher(string plaintext, int k)
{
    // loop through the text
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        //Checking if is uppercase to use right numbers
        if (islower(plaintext[i]))
        {
            printf("%c", (((plaintext[i] + k) - 97) % 26) + 97);
        }
        else if (isupper(plaintext[i]))
        {
            printf("%c", (((plaintext[i] + k) - 65) % 26) + 65);
        }
        // if not, maybe is a regular character
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    // just a new line
    printf("\n");
}