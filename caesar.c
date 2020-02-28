#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
int k;

// Function declaration
int get_encrypt_char(char decrypt_char);

int main(int argc, string argv[])
{
    // Check if have argument - k
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    // Convert k argument to int
    k = atoi(argv[1]);
    printf("plaintext: ");
    // Get text to enctypt
    string text = get_string();
    int lenght = strlen(text);
    printf("ciphertext: ");
    for (int i = 0; i < lenght; i++)
    {
        printf("%c", get_encrypt_char(text[i]));
    }
    printf("\n");
    return 0;
}

// Function encrypt char via number ASCII code
int get_encrypt_char(char decrypt_char)
{
    if (isalpha(decrypt_char))
    {
        int ascii_start_number = isupper(decrypt_char) ? 65 : 97;
        return (((decrypt_char % ascii_start_number) + k) % 26) + ascii_start_number;
    }
    else
    {
        return decrypt_char;
    }
}