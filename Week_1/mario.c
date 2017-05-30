#include <stdio.h>

int main(void)
{
    int scanf_check;
    int height;
    int spaces;
    int blocks = 1;

    do {
        printf("Height: ");
        scanf_check = scanf("%d", &height);
        while ( getchar() != '\n' ); // Clean the stdin buffer.
    } while (height < 0 || height > 23 || scanf_check == 0);

    spaces = height - 1;

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        for(int k = 0; k < blocks; k++)
        {
            printf("#");
        }

        printf("  ");

        for(int k = 0; k < blocks; k++)
        {
            printf("#");
        }

        for(int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        printf("\n");

        spaces--;
        blocks++;
    }

    return 0;
}
