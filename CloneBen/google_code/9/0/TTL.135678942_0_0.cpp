#include <set>
#include <cmath>
#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <vector>
#include <ctime>
#include <queue>
#include <list>
#include <map>
#define pi acos(-1.0)
#define INF 0x3f3f3f3f
#define clr(x)  memset(x,0,sizeof(x));
#define clrto(x,siz,y)  for(int xx=0;xx<=siz;xx++)  x[xx]=y;
#define clrset(x,siz)  for(int xx=0;xx<=siz;xx++)  x[xx]=xx;
#define clr_1(x) memset(x,-1,sizeof(x));
#define clrmax(x) memset(x,0x3f,sizeof(x));
#define clrvec(x,siz) for(int xx=0;xx<=siz;xx++)  x[xx].clear();
#define fop2   freopen(".in","r",stdin); //freopen(".out","w",stdout);
#define fop   freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
#define myprogram By_135678942570
#define clrcpy(x,siz,y)  for(int xx=0;xx<siz;xx++)  x[xx]=y[xx];
#define pb push_back
using namespace std;
long long dp[111][111];
long long dp1[111][111];
const long long MOD=1000000007;
long long poww(long long a,long long b)
{
    long long s=1;
    while(b)
    {
        if(b&1) s=(s*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return s;
}
int main()
{
    fop;
    int T,cas=0;
    scanf("%d",&T);
    dp[0][0]=1;
    dp1[0][0]=1;
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
        {
            for(int k=0;k+j<=100;k++)
                dp1[i+1][j+k]+=dp1[i][j],dp1[i+1][j+k]%=MOD;
        }
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
        if(dp[i][j]!=0)
        {
            for(int k=1;k+j<=100;k++)
            {
                dp[i+1][j+k]=(dp[i+1][j+k]+dp[i][j]*dp1[j+1][k])%MOD;
            }
        }
    // printf("%lld\n",dp[3][3]);
    while(T--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        printf("Case #%d: %lld\n",++cas,dp[m][n]);
    }
}