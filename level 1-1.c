#include <stdio.h>

int main()
{
    int aisle, price, num, total_price;
    int w_aisle, w_num;
    char type;
    char w_type;

    printf("Please enter the type,asile,price,and number in order:");
    scanf("%c%d%d%d", &type, &aisle, &price, &num);
    
    printf("%d:", aisle);
    for ( int i = 0; i < num; i++)
    {
        printf("%c", type);
    }
    printf(" %d\n", price);

    while(getchar()!='\n')
        continue;
    

    for( char cmd = 'y'; num > 0 && cmd == 'y'; )
    {
        printf("The type,aisle,and number of the goods that you wanna buy:");
        scanf("%c%d%d", &type, &w_aisle, &w_num);
        total_price = w_num * price;
        printf("Total price:%d\n", total_price);

        for ( int coin; total_price > 0; )
        {
        printf("Please insert coins here:");
        scanf("%d", &coin);
        total_price -= coin;
        }
        printf("Here is the change:%d\n", -total_price);

        num -= w_num;

        while(getchar()!='\n')
            continue;
        
        printf("Wanna to purchase again?(y/n)");
        scanf("%c", &cmd);

        while(getchar()!='\n')
            continue;
        
        
    }

    return 0;
}