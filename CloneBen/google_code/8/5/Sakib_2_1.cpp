#include <bits/stdc++.h>
#define inf 1000000000
#define ll long long
#define Max 1000000

using namespace std;

int d[10];

int pos(int x)
{
    int k=0;
    while(x)
    {
        if(d[x%10]==0) return 0;
        x/=10;
        k++;
    }

    return k;
}

vector <int> divi[Max+5];
int dp[Max+5];

int f(int x)
{
    if(dp[x]!=-1) return dp[x];

    int i,j,k,r=inf,p,q;

    k=pos(x);

    if(k) r=k;

    for(i=0;i<divi[x].size();i++)
    {
        j=divi[x][i];
        k=x/j;


        p=f(j);
        q=f(k);

        if(p==inf || q==inf) continue;

        r=min(r,p+q+1);
    }

    return dp[x]=r;
}


int main()
{
    int i,j,k,T,cas,ret=0;

    freopen("C-large(1).in","r",stdin);
    freopen("c-Large.txt","w",stdout);

    for(i=2;i*i<=Max;i++)
    {
        for(j=i;j*i<=Max;j++)
        {
            divi[i*j].push_back(i);
        }
    }

    scanf("%d",&T);

    for(cas=1;cas<=T;cas++)
    {
        memset(dp,-1,sizeof(dp));

        for(i=0;i<10;i++) scanf("%d",&d[i]);

        scanf("%d",&k);

        ret=f(k);

        if(ret==inf) printf("Case #%d: Impossible\n",cas);

        else printf("Case #%d: %d\n",cas,ret+1);
    }

    return 0;
}
