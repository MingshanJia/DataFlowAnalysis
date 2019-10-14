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
#define fop   freopen("in.txt","r",stdin);freopen("out2.txt","w",stdout);
#define myprogram By_135678942570
#define clrcpy(x,siz,y)  for(int xx=0;xx<siz;xx++)  x[xx]=y[xx];
#define pb push_back
using namespace std;
int main()
{
    int T,cas=0;
    fop;
    scanf("%d",&T);
    while(T--)
    {
        int n,K;
        scanf("%d%d",&n,&K);
        int num[111]={0};
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        int dp[111][111]={0};
        for(int i=0;i<n-2;i++)
            if(num[i]+K==num[i+1]&&num[i]+K+K==num[i+2])
                dp[i][i+2]=1;
        for(int i=6;i<=n;i+=3)
        {
            for(int j=0;j+i-1<n;j++)
            {
                for(int k=j;k<j+i-1;k++)
                    dp[j][j+i-1]|=(dp[j][k]&&dp[k+1][j+i-1]);
                for(int k=j+1;k<j+i-1;k++)
                if(num[j]+K==num[k]&&num[j]+K+K==num[j+i-1])
                {
                    int s1=(k==j+1||dp[j+1][k-1]);
                    int s2=(k==j+i-2||dp[k+1][j+i-2]);
                    // printf("%d %d %d\n",k,s1,s2);
                    // printf("%d %d\n",j,j+i-1);
                    dp[j][j+i-1]|=(s1&&s2);
                }
            }
        }
        // for(int i=0;i<n;i++)
        //     for(int j=0;j<n;j++)
        //         printf("%d x %d : %d\n",i,j,dp[i][j]);
        // printf("%d\n",dp[0][8]);
        int dp2[111]={0};
        for(int i=0;i<n;i++)
        {
            dp2[i+1]=max(dp2[i+1],dp2[i]);
            for(int j=i;j<n;j++)
                if(dp[i][j])
                {
                    dp2[j+1]=max(dp2[j+1],dp2[i]+(j-i+1));
                }
        }
        printf("Case #%d: %d\n",++cas,n-dp2[n]);
    }
}