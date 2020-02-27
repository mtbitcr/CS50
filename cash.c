#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    int cent;

    do
    {
        float dollar = get_float("Change owed: ");
        cent = round(dollar * 100);
    }
    while (cent <= 0);

    //coin1=25 coin2=10 coin3=5 coin4=1

    int coin1 = cent / 25;
    int coin2 = (cent % 25) / 10;
    int coin3 = ((cent % 25) % 10) / 5;
    int coin4 = ((cent % 25) % 10) % 5;

    printf("%i\n", coin1 + coin2 + coin3 + coin4);
}
