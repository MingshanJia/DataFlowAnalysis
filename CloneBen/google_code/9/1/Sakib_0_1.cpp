#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#define inf 2000000000
#define ll long long
#define M 1000000007

using namespace std;

ll n,m,dp[105][105];

ll f(ll pos,ll cov)
{
    if(pos==n)
    {
        if(cov==m) return 1;
        return 0;
    }

    if(dp[pos][cov]!=-1) return dp[pos][cov];

    ll i,j,k,r;

    r=cov*f(pos+1,cov);
    if(cov<m) r+=(m-cov)*f(pos+1,cov+1);

    r%=M;

    return dp[pos][cov]=r;


}

int main()
{
    ll i,j,k,T,cas,ret=0;

    freopen("A-large(6).in","r",stdin);
    freopen("a-large.txt","w",stdout);

    cin>>T;

    for(cas=1;cas<=T;cas++)
    {
        cin>>m>>n;
        memset(dp,-1,sizeof(dp));
        printf("Case #%lld: %lld\n",cas,f(0,0));
    }

    return 0;
}
