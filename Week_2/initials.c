#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char name[100];
    printf("Enter a person name: ");
    scanf("%[^\n]", name);

    for(int i = 0, n = strlen(name); i < n; i++)
    {
        if(name[i] != ' ' && (name[i-1] == ' ' || i == 0))
        {
            printf("%c", toupper(name[i]));
        }
    }

    printf("\n");
    return 0;
}
