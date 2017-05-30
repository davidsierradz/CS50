#include <stdio.h>

int main(void)
{
    float change;
    int cents_change;
    int coins;

    printf("How much change?\n");
    scanf("%f", &change);
    cents_change = (int)(change * 100);
    //printf("%f, %d\n", change, cents_change);
    printf("\n");

    while(cents_change != 0)
    {
        if(cents_change - 25 >= 0)
        {
            coins++;
            cents_change -= 25;
            printf("Used 25 cents, Coins: %d, Change Left: %d\n", coins, cents_change);
        }
        else if(cents_change - 10 >= 0)
        {
            coins++;
            cents_change -= 10;
            printf("Used 10 cents, Coins: %d, Change Left: %d\n", coins, cents_change);
        }
        else if(cents_change - 5 >= 0)
        {
            coins++;
            cents_change -= 5;
            printf("Used 5 cents, Coins: %d, Change Left: %d\n", coins, cents_change);
        }
        else if(cents_change - 1 >= 0)
        {
            coins++;
            cents_change -= 1;
            printf("Used 1 cents, Coins: %d, Change Left: %d\n", coins, cents_change);
        }
    }

    printf("\n");
    printf("Coins: %d\n", coins);
    return 0;
}
