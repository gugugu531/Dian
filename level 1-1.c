#include <stdio.h>

int main()
{
    int aisle, price, num;
    char type;

    printf("Please enter the type,asile,price,and number in order:");
    scanf("%c%d%d%d", &type, &aisle, &price, &num);
    
    printf("%d:", aisle);
    for ( int i = 0; i < num; i++)
    {
        printf("%c", type);
    }
    printf(" %d", price);

    return 0;
}
