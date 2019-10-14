#include <cstdio>
#include <algorithm>

bool map[50][50];
bool clearable[256];

int DP[50][50];
int above[50][50];

using namespace std;


int main(int argc, char** argv)
{
    clearable['G'] = true;
    clearable['S'] = true;
    
    int N;
    scanf("%d", &N);
    for(int c = 1; c <= N; ++c)
    {
        int W, L;
        scanf("%d %d ", &L, &W);
        
        for(int i = 0; i < W; ++i)
        {
            for(int j = 0; j < L; ++j)
            {
                char c;
                scanf("%c", &c);
                map[j][i] = clearable[c];
            }
            
            scanf(" ");
        }
        
        /*
        for(int i = 0; i < W; ++i)
        {
            for(int j = 0; j < L; ++j)
            {
                char c;
                printf("%d", map[j][i]);
            }
            
            printf("\n");
        }
        */  
        for(int i = 0; i < L; ++i)
            above[i][0] = map[i][0];
        
        for(int i = 1; i < W; ++i)
            for(int j = 0; j < L; ++j)
            {
                if(!map[j][i])
                    above[j][i] = 0;
                else
                    above[j][i] = above[j][i - 1] + 1;
            }
        
        int ans = 0;
        
        for(int i = 0; i < W; ++i)
        {
            for(int j = 0; j < L; ++j)
            {
                DP[j][i] = 0;
                
                if(!map[j][i])
                {
//                     printf("DERP X = %d Y = %d\n", j, i);
                    continue;
                }
                int w = 0;
                int h = above[j][i];
                
                for(int k = j; k < L; ++k)
                {
                    ++w;
                    h = min(h, above[k][i]);
                    DP[j][i] = max(DP[j][i], w*h);
                }
//                 printf("%d %d %d\n", j, i, DP[j][i]);
                
                if(ans < DP[j][i])
                {
//                     printf("Max at %d %d %d\n", j, i, DP[j][i]);
                }
                ans = max(ans, DP[j][i]);
//                 printf("%d\n", DP[j][i]);
            }
        }
        
        printf("Case #%d: %d\n", c, ans);
    }
    return 0;
}