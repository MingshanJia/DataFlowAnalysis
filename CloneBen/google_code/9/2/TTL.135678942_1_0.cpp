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
int val[1000011];
double get[404][404*404];
int to[404*404][3];
int mp[404][404];
int main()
{
    fop;
    int cnt=0;
    for(int i=1;i<=400;i++)
        val[i*(i+1)/2]=2,val[i*(i-1)/2+1]=2;
    for(int i=1;i<=402;i++)
        for(int j=1;j<=i;j++)
            mp[i][j]=++cnt;
    for(int i=1;i<=400;i++)
        for(int j=1;j<=i;j++)
            to[mp[i][j]][0]=mp[i][j],to[mp[i][j]][1]=mp[i+1][j],to[mp[i][j]][2]=mp[i+1][j+1];
    val[1]=1;
    int T,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        clr(get);
        int b,l,n;
        scanf("%d%d%d",&b,&l,&n);
        get[1][1]=b*750;
        for(int i=1;i<=l;i++)
        {
            for(int j=1;j<=i*(i+1)/2;j++)
            {
                if(get[i][j]<=250.000)
                    continue;
                double rest=get[i][j]-250;
                get[i][j]=250;
                // printf("%d %d %f\n",i,j,rest);
                for(int k=0;k<3;k++)
                    get[i+1][to[j][k]]+=rest/3;
            }
        }
        printf("Case #%d: %.10f\n",++cas,get[l][n]);
    }
}