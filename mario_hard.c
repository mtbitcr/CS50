#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    int hashes;
    int spaces;
    int hashes2;
    
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    for (int i = 1; i <= height; i++)
    {
        for (spaces = (height - i); spaces > 0; spaces--)
        {
            printf(" ");
        }
        for (hashes = 2; hashes <= (i + 1); hashes++)
        {
            printf("#");
        }
        printf("  ");
        for (hashes2 = 2; hashes2 <= (i + 1); hashes2++)
        {
            printf("#");
        }
        printf("\n");
    }
}
