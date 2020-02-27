#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long number, xadd, x2;
    int addsum, x2prod, sum;
    
    do
    {      
        number = get_long("Number:");
    }
    while (number < 0);  
    
    //находим каждый 2 разряд
    for (xadd = number, addsum = 0; xadd > 0; xadd /= 100)        
        addsum += xadd % 10;
    
    //умножаем на 2 и потом додаём их разряды
    for (x2 = number / 10, x2prod = 0; x2 > 0; x2 /= 100)
    {
        if (2 * (x2 % 10) > 9) 
        {
            x2prod += (2 * (x2 % 10)) / 10;
            x2prod += (2 * (x2 % 10)) % 10;
        }
        else            
            x2prod += 2 * (x2 % 10);            
    }
    
    // додаём суммы 1 и 2
    sum = addsum + x2prod;

    // проверяем
    if (sum % 10 == 0)
    {   
        if ((number >= 340000000000000 && number < 350000000000000) || (number >= 370000000000000 && number < 380000000000000))
            printf("AMEX\n");
        else if (number >= 5100000000000000 && number < 5600000000000000)
            printf("MASTERCARD\n");
        else if ((number >= 4000000000000 && number < 5000000000000) || (number >= 4000000000000000 && number < 5000000000000000))
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else
        printf("INVALID\n");

    return 0;
}
