#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

// Global variables
char *hash;
char *pass;
char salt[2];
char alphabet[52] =
{
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'G', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};
int pass_length = 5;
int alphabet_size = sizeof(alphabet) / sizeof(alphabet[0]);

// Function declaration
void generate_pass(int current_alpha, int length);
bool check_hash(void);

int main(int argc, string argv[])
{
    // Check if have argument hash
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    // Set hash value
    hash = argv[1];

    // Set salt value
    memcpy(salt, hash, 2);
    // Set start number of alphabet size
    int numb = 1;

    for (int i = 0; i < pass_length; i++)
    {
        numb *= alphabet_size;
        for (int current_alpha = 0; current_alpha < numb; current_alpha++)
        {
            generate_pass(current_alpha, i + 1);
            // If found match hashes, print pass and exit programm
            if (check_hash())
            {
                printf("%s\n", pass);
                return 0;
            }
        }
    }

    printf("Password not found in current alphabet.\n");
    return 1;
}

void generate_pass(int current_alpha, int length)
{
    // Memory allocation for pass variable
    pass = malloc(length);

    while (length--)
    {
        pass[length] = alphabet[current_alpha % alphabet_size];
        current_alpha /= alphabet_size;
    }
}

bool check_hash(void)
{
    return (strcmp(hash, crypt(pass, salt)) == 0);
}