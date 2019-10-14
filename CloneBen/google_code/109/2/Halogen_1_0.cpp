#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN=100000005;
int T,D,K,N,ans[MAXN];
int mod(int a,int b)
{
    if (a>=0)return a%b;
    return (b-(-a%b))%b;
}
int main()
{
    freopen("B-small.in","r",stdin);
    freopen("OUT21.txt","w",stdout);
    scanf("%i",&T);
    for (int t=1;t<=T;t++)
    {
        printf("Case #%i: ",t);
        scanf("%i%i%i",&D,&K,&N);
        for (int i=0;i<D;i++)
        {
            if (i%2==0)
            {
                ans[(i+N)%D]=i+1;
            }
            else
            {
                ans[mod(i-N,D)]=i+1;
            }
        }
        for (int i=0;i<D;i++)
        {
            if (ans[i]==K)
            {
                printf("%i %i\n",ans[(i+1)%D],ans[mod(i-1,D)]);
            }
        }
    }
}
