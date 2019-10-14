#include <cstdio>
#include <algorithm>

using namespace std;

int reds[1001];
int num_reds;
int blues[1001];
int num_blues;

int main(int argc, char** argv)
{
    int N;
    scanf("%d", &N);
    
    for(int c = 1; c <= N; ++c)
    {
        int S;
        scanf("%d", &S);
        
        num_blues = 0;
        num_reds = 0;
        
        for(int i = 0; i < S; ++i)
        {
            int L;
            char t;
            scanf("%d%c", &L, &t);
            
            if(t == 'R')
                reds[num_reds++] = L;
            else
                blues[num_blues++] = L;
        }
        
        sort(reds, reds + num_reds);
        reverse(reds, reds + num_reds);
        
        sort(blues, blues + num_blues);
        reverse(blues, blues + num_blues);
        
        int total = min(num_reds, num_blues);
        
        int sum = 0;
        
        for(int i = 0; i < total; ++i)
            sum += (reds[i] + blues[i]);
        
        sum -= 2*total;
        
        printf("Case #%d: ", c);
        
        printf("%d\n", sum);
    }
    return 0;
}