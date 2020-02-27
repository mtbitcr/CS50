#include <stdio.h>
#include <cs50.c>
#include <string.h>
#include <ctype.h>
#define _XOPEN_SOURCE
#include <stdlib.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < 11; i++)
        {
            string password = argv[1][i];
        }
        for (int j = 11; j < 13; j++)
        {
            string salt = argv[1][j];
        }
        char *passwordCiph = crypt(password, salt);
        printf("%s\n", passwordCiph);
        return 0;
    }
}
