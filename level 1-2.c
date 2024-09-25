#include <stdio.h>

int main()
{
    int aisle, price, num, total_price;
    char type;

    printf("Please enter the type,asile,price,and number in order:");
    scanf("%c%d%d%d", &type, &aisle, &price, &num);
    
    printf("%d:", aisle);
    for ( int i = 0; i < num; i++)
    {
        printf("%c", type);
    }
    printf(" %d\n", price);

    printf("Total price:");
    scanf("%d", &total_price);

    for ( int coin; total_price > 0; )
    {
        printf("Please insert coins here:");
        scanf("%d", &coin);
        total_price -= coin;
    }
    printf("Here is the change:%d", -total_price);

    return 0;
}
