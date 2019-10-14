#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=505,MOD=1e9+7;
int T,C,V,L;
long long dp[MAXN][2];
long long int query(int curr,bool cons)
{
    if (curr==L)return !cons;
    long long int ans=0;
    if (cons)
    {
        ans+=V*query(curr+1,0);
    }
    else
    {
        ans+=C*query(curr+1,1);
        ans+=V*query(curr+1,0);
    }
    ans%=MOD;
    return ans;
}
int main()
{
    freopen("c-small-1.txt","r",stdin);
    freopen("OUT31.txt","w",stdout);
    scanf("%i",&T);
    for (int i=1;i<=T;i++)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%i%i%i",&C,&V,&L);
        printf("Case #%i: %lli\n",i,query(0,0));
    }
}
