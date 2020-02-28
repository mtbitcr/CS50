#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

// Global variables
string crypto_key;
int length_key = 0;
int alpha_text_count = 0;
int k = 0;
// Function declaration
bool is_aplha_string(string str);
void set_k_value(void);
int get_encrypt_char(char decrypt_char);

int main(int argc, string argv[])
{
    // Check if have argument key and is it only aplha chars
    if (argc != 2 || !is_aplha_string(argv[1]))
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    crypto_key = argv[1];
    length_key = strlen(crypto_key);
    // Get text to encrypt
    printf("plaintext: ");
    string text = get_string();
    int lenght_text = strlen(text);
    printf("ciphertext: ");
    // Loop for encrypt one char in text
    for (int i = 0; i < lenght_text; i++)
    {
        printf("%c", get_encrypt_char(text[i]));
    }
    printf("\n");
    return 0;
}

// Function check is string have only aplha chars
bool is_aplha_string(string str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(str[i]))
        {
            return false;
        }
    }
    return true;
}

// Function set k value by current alpha char in text
void set_k_value(void)
{
    int i = alpha_text_count % length_key;
    int ascii_start_number = isupper(crypto_key[i]) ? 65 : 97;
    k = (crypto_key[i] % ascii_start_number) % 26;
    alpha_text_count++;
}

// Function encrypt char via number ASCII code
int get_encrypt_char(char decrypt_char)
{
    if (isalpha(decrypt_char))
    {
        set_k_value();
        int ascii_start_number = isupper(decrypt_char) ? 65 : 97;
        return (((decrypt_char % ascii_start_number) + k) % 26) + ascii_start_number;
    }
    else
    {
        return decrypt_char;
    }
}