#include <stdio.h>

int main(void)
{
    int time;
    printf("Minutes: ");
    scanf("%d", &time);
    printf("Bottles: %d\n", time * 12);

    return 0;
}
