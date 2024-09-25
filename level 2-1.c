#include <stdio.h>
#include <string.h>

typedef struct
{
    char type;
    int aisle;
    int num;
    int price;
    int occupy;
}GOODS;

GOODS g[6];
GOODS clear = {'\0',0,0,0,0};
int total_price = 0;

void place_the_goods(GOODS goods[6])
{
    GOODS placement = {.occupy = 1};
    int error = 100;
    printf("Please enter the type,asile,price,and number in order:");

    for ( ; error != 4; )
    {
        error = scanf(" %c %d %d %d", &placement.type, &placement.aisle, &placement.price, &placement.num);
        switch (placement.type)
        {
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G':
        case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N':
        case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T':
        case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z':    
            break;
        default:
            error = 100;
            break;//just enter a number that is not equal to 4.
        }

        switch (placement.aisle)
        {
        case 1: case 2: case 3: case 4: case 5:
            break;
        default:
            error = 100;
            break;
        }
        
        switch (placement.price)
        {
        case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
            break;
        
        default:
            error = 100;
            break;
        }

        switch (placement.num)
        {
        case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20:
        case 21: case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30:
        case 31: case 32: case 33: case 34: case 35: case 36: case 37: case 38: case 39: case 40:
        case 41: case 42: case 43: case 44: case 45: case 46: case 47: case 48: case 49: case 50:
            break;
        
        default:
            error = 100;
            break;
        }
        
        if (goods[placement.aisle].occupy != 0 && (goods[placement.aisle].type != placement.type && goods[placement.aisle].price != placement.price ))
            error = 100;
        else if ((goods[placement.aisle].num +placement.num) > 50)
            error = 100;
        else goods[placement.aisle].num += placement.num;

        if (error != 4)
        {
            printf("Please re-enter these data correctly:");
        }
        
    }
    
    if (goods[placement.aisle].occupy == 0)
    {
    
        switch (placement.aisle)
        {
        case 1:
            goods[1] = placement;
            break;
        case 2:
            goods[2] = placement;
            break;
        case 3:
            goods[3] = placement;
            break;
        case 4:
            goods[4] = placement;
            break;
        case 5:
            goods[5] = placement;
            break;
        default:
            break;
        }
    }

}

void on_the_shelf(GOODS goods[6])
{
    printf("Now on the shelf:\n");
    for ( int i = 1; i < 6; i++)
    {
        printf("%d: ", i);
        if (goods[i].occupy == 1)
        {
            for ( int n = 0 ; n < goods[i].num ; n++)
            {
                printf("%c", goods[i].type);
            }
            printf(" %d\n", goods[i].price);
        }
        else printf("\n");
    }
    
}

void buy_the_goods(GOODS goods[])
{
    GOODS purchase = {.occupy = 1};
    int error = 100;
    printf("Please enter the type,asile,and number in order:");

    for ( ; error != 3; )
    {
        error = scanf(" %c %d %d", &purchase.type, &purchase.aisle, &purchase.num);

        switch (purchase.aisle)
        {
        case 1: case 2: case 3: case 4: case 5:
            break;
        default:
            error = 100;
            break;
        }

        if (goods[purchase.aisle].occupy == 0 || goods[purchase.aisle].type != purchase.type )
            error = 100;
        else if ((goods[purchase.aisle].num - purchase.num) < 0)
            error = 100;
        else {
            goods[purchase.aisle].num -= purchase.num;
            total_price +=  (goods[purchase.aisle].price * purchase.num);
        }

        if (error != 3)
        {
            printf("Please re-enter these data correctly:");
        }
        
    }
    
}

int main(void)
{   
    for ( int i = 1; i < 6; i++)
    {
        g[i] = clear;
    }

    for (int i = 1 ; i != 0; )
    {
        char end[4];
        place_the_goods(g);
        on_the_shelf(g);
        while (getchar() != '\n')
            ;
        printf("Enter END to quit:");
        scanf("%3s", end);
        i = strcmp(end, "END");
    }
    
    printf("Now you can buy some goods.\n");

    for ( ; ; )
    {
        for ( int i = 1; i != 0; )
        {   
            char end[4];
            buy_the_goods(g);
            on_the_shelf(g);
            printf("Enter END to stop to check out:");
            scanf("%3s", end);
            i = strcmp(end, "END");
        }

        for ( ; total_price >= 0; )
        {
            
            int coin;
            printf("Please insert coins here:");
            for ( int error = 0; error != 0 ; )
            {
                scanf("%d", &coin);
                switch (coin)
                {
                case 1: case 2: case 3:
                    error = 1;
                    total_price -= coin;
                    break;
            
                default:
                    printf("Please insert coins of 1,2 or 5:");
                    break;
            }
            
            }
        }

        printf("Here is the change:%d\n", -total_price);
        total_price = 0;

    }
    
    
    return 0;
}