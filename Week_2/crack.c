#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char vector[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
        'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
        'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'};

    char salt[] = {argv[1][0], argv[1][1], '\0'};
    int c = 0;
    for(int i = 0, n = strlen(vector); i < n; i++)
    {
        char random_password[] = {vector[i]};
        if (strcmp(crypt(random_password, salt), argv[1]) == 0)
        {
            printf("%s\n", random_password);
            return 0;
        }
        for(int j = 0; j < n; j++)
        {
            char random_password[] = {vector[i], vector[j]};
            if (strcmp(crypt(random_password, salt), argv[1]) == 0)
            {
                printf("%s\n", random_password);
                return 0;
            }
            for(int k = 0; k < n; k++)
            {
                char random_password[] = {vector[i], vector[j], vector[k]};
                if (strcmp(crypt(random_password, salt), argv[1]) == 0)
                {
                    printf("%s\n", random_password);
                    return 0;
                }
                for(int l = 0; l < n; l++)
                {
                    c++;
                    char random_password[] = {vector[i], vector[j], vector[k], vector[l]};
                    if (strcmp(crypt(random_password, salt), argv[1]) == 0)
                    {
                        printf("%s\n", random_password);
                        return 0;
                    }
                }
            }
        }
    }
    printf("\n");
    return 1;
}
