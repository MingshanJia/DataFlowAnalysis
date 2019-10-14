#include <cstdio>

int stuff[12];

int main(int argc, char** argv)
{
    int N;
    scanf("%d", &N);
    
    for(int c = 1; c <= N; ++c)
    {
        int M;
        scanf("%d", &M);
        
        for(int i = 0; i < 12; ++i)
            scanf("%d", stuff + i);
        
        int buy_month = -1;
        int sell_month = -1;
        int profit = 0;
        
        for(int i = 0; i < 12; ++i)
            for(int j = i + 1; j < 12; ++j)
            {
                if(stuff[i] > M)
                    continue;
                
                int prof_per_unit = stuff[j] - stuff[i];
                int units = M/stuff[i];
                int prof = prof_per_unit*units;
                
//                 printf("%d %d %d %d %d\n", i, j, prof_per_unit, units, prof);
                if(prof > profit)
                {
                    profit = prof;
                    buy_month = i;
                    sell_month = j;
                }
                else if(prof == profit && stuff[buy_month] > stuff[i])
                {
                    profit = prof;
                    buy_month = i;
                    sell_month = j;
                }
            }
            
        printf("Case #%d: ", c);
        
        if(profit == 0)
            printf("IMPOSSIBLE\n");
        else
            printf("%d %d %d\n", buy_month + 1, sell_month + 1, profit);
    }
    
    return 0;
}