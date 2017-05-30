#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned long long card_number;
    unsigned long long card_number_reduced;
    unsigned long long flag_number;
    int odd_sum = 0;
    int n = 0;

    printf("Number: ");
    scanf("%llu", &card_number);
    printf("\n");

    card_number_reduced = card_number;

    do
    {
        flag_number = (int) ((unsigned long long) (card_number / pow(10, n)) % 10);
        card_number_reduced = card_number_reduced / 10;
        printf("card_number_reduced: %llu\n", card_number_reduced);
        printf("flag_number: %llu\n", flag_number);
        printf("n: %d\n", n);

        if(n % 2 != 0)
        {
            if(flag_number * 2 >= 10)
            {
                odd_sum += ((flag_number * 2) % 10) + ((flag_number * 2) / 10);
            }
            else
            {
                odd_sum += flag_number * 2;
            }
        }
        else
        {
            odd_sum += flag_number;
        }

        n++;
    } while(card_number_reduced != 0);

    printf("\n");
    printf("n_final: %d\n", n);
    printf("odd_sum: %d\n", odd_sum);
    return 0;
}
