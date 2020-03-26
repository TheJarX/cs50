#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
void pyramid(int);
void pyramid_floor(int);

int main(void)
{
    // Prompt user for a height
    pyramid(get_int("Height: "));
}

// Function to print the pyramid
void pyramid(int height) 
{
    // Control user input
    if (height <= 0 || height > 8) 
    {
        printf("(!) Hight must be between 1 and 8\n");
        pyramid(get_int("Height: "));
        exit(0);
    }

    int width = 1;
    int space = height - 1;
    for (int i = 0; i < height; i++) 
    {
       
        // Print spaces
        for (int j = 0; j < space; j++) 
        {
            printf(" ");
        }
        space--;

        // Print first pyramid
        pyramid_floor(width);
        // Print separator and the second pyramid
        printf("  ");
        pyramid_floor(width);

        width++;
        printf("\n");
    }

}

void pyramid_floor(int width) 
{
    for (int i = width; i > 0; i--) 
    {
        printf("#");
    }
}