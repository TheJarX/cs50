#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

const char END_OF_WORD = '\0';
const char SPACE = ' ';
const int FIRST_LETTER = 65;
const int LAST_LETTER = 122;

int count_letters(string);
int count_words(string);
int count_sentences(string);
void calc_grade(float, float);

int main(void)
{
    // User's input
    string inp = get_string("Text: \n");

    // how many letters
    int letters = count_letters(inp);
    // how many words
    int words = count_words(inp);
    // how many sentences
    int sentences = count_sentences(inp);

    // average number of letters per 100 words
    float l = ((float)letters / (float)words) * 100;
    // average number of sentences per 100 words
    float s = ((float)sentences / (float)words) * 100;

    // calculate the text grade
    calc_grade(l, s);

    return 0;

}


// Considering letter as each character except by spaces and null char
int count_letters(string s)
{
    // letter counter
    int letters = 0;
    int i = 0;

    // If the current char is null we've got end of the word
    while (s[i] != END_OF_WORD)
    {
        // Current char of s
        char letter = s[i];

        // Between the alphabet including lowercase and uppercase letters
        if ((int) letter >= FIRST_LETTER && (int) letter <= LAST_LETTER)
        {
            letters ++;
        }
        i++;
    }
    return letters;
}


// Cosidering words as a group of letters separated by a space
int count_words(string s)
{
    // words counter
    int words = 0;

    // Getting the string length, comparing each character
    for (int i = 0, len = strlen(s); i <= len; i++)
    {
        char character = s[i];
        // including the null char
        if (character == SPACE || character == END_OF_WORD)
        {
            words++;
        }
    }

    return words;
}

// Considering a sentece as a group of words ending with either . or ! or ?
int count_sentences(string s)
{
    // number of sentences
    int sentences = 0;
    // Array with the 3 symbols with which a sentence ends.
    char symbols[3] = {'.', '!', '?'};

    // Getting the string length, comparing each character
    for (int i = 0, len = strlen(s); i <= len; i++)
    {
        char character = s[i];
        // Comparing with the predefined "end of sentence" charcters
        if (character == symbols[0] ||
            character == symbols[1] ||
            character == symbols[2]
           )
        {
            sentences++;
        }
    }

    return sentences;

}

// Just to calculate the grade of a text
//  'l' is the average number of letters per 100 words in the text,
// and 's' is the average number of sentences per 100 words in the text.
void calc_grade(float l, float s)
{
    // using the formula
    int grade = round((0.0588 * l - 0.296 * s - 15.8));

    // checking conditions required
    if (grade <= 1)
    {
        printf("Before Grade 1\n");
        return;
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
        return;
    }

    printf("Grade %i\n", grade);
    return;
}
