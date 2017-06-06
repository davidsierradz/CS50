#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_alphabet(char string[])
{
    for(int i = 0, n = strlen(string); i < n; i++)
    {
        if((string[i] < 65 || string[i] > 90)
                && (string[i] < 97 || string[i] > 122))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    if(argc != 2 || !is_alphabet(argv[1]))
    {
        printf("Usage: ./vigenere k (k must be only alphabet chars)\n");
        return 1;
    }

    int key_size = strlen(argv[1]);
    int l = 0;
    int k[1000];
    for(int j = 0, n = strlen(argv[1]); j < n; j++)
    {
        if(argv[1][j] > 64 && argv[1][j] < 91)
        {
            k[j] = argv[1][j] - 65;
        }
        else
        {
            k[j] = argv[1][j] - 97;
        }
    }
    char cyphered_message[1000];
    char message[1000];

    printf("plaintext: ");
    scanf("%[^\n]", message);

    for(int i = 0, n = strlen(message); i < n; i++)
    {
        if(l >= key_size)
        {
            l = 0;
        }
        if(message[i] > 64 && message[i] < 91)
        {
            cyphered_message[i] = ((message[i] - 65 + k[l]) % 26) + 65;
            l++;
            printf("%c", cyphered_message[i]);
        }
        else if(message[i] > 96 && message[i] < 123)
        {
            cyphered_message[i] = ((message[i] - 97 + k[l]) % 26) + 97;
            l++;
            printf("%c", cyphered_message[i]);
        }
        else
        {
            printf("%c", message[i]);
        }
    }

    printf("\n");
    return 0;
}
