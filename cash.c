#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cs50.h>
int greedy_cashier(float);

int main(void) 
{
    printf(
        "Coins used: %i\n",
        greedy_cashier(
            get_float("Change owed: ")
        )
    );

    return 0;
}

// TODO: Improve this algorithm
int greedy_cashier(float change_owed)
{
    // Rounding
    int money = round(change_owed * 100);

    if (money < 1) 
    {
        printf("Hey! you owe me money\n");
        greedy_cashier(get_float("Change owed: "));
        exit(0);
    }

    // Quarters
    int quarters = money / 25;
    money = money % 25;

    // dimes
    int dimes = money / 10;
    money = money % 10;

    // nickels
    int nickels = money / 5;
    money  = money % 5;

    // pennies
    int pennies = money;

    // Coins used
    return quarters + dimes + nickels + pennies;

}