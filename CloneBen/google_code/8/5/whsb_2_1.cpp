#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define inf 100000000
typedef unsigned long long ULL;
typedef long long LL;

int buttonOK[16];
int X;
int f[1023000];
int g[1023000];
int VecG[1023000];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int casT;
    cin>>casT;
    for(int cas=1;cas<=casT;cas++)
    {
        int ans = inf;
        for(int i=0;i<10;i++) scanf("%d",&buttonOK[i]);
        scanf("%d",&X);
        for(int i=0;i<=X;i++) g[i]=f[i]=inf;
        int p=0;
        for(int i=0;i<=X;i++)
        {
            if(i<10&&buttonOK[i]) g[i]=1;
            else
            {
                int pre = i/10;
                int md = i%10;
                if(g[pre]<inf&&buttonOK[md]) g[i]=g[pre]+1;
            }
            if(g[i]<inf) VecG[p++]=i;
        }
        if(g[X]<inf) ans = g[X]+1;
        else
        {
            for(int i=0;i<=X;i++)
            {
                f[i]=min(f[i],g[i]);
                ///if(i==X) cout<<f[i]<<" "<<g[i]<<endl;

                for(int j=0;j<p;j++)
                {
                    int mul = VecG[j];
                    if(mul<=1) continue;
                    LL nxt = (LL)i*(LL)mul;
                    if(nxt>X) break;
                    f[nxt] = min(f[nxt],f[i]+1+g[mul]);
                    ///if(nxt==X) cout<<i<<":"<<f[i]<<" , "<<mul<<":"<<g[mul]<<endl;
                }
            }
            ans = f[X]+1;
        }
        if(ans<inf) printf("Case #%d: %d\n",cas,ans);
        else printf("Case #%d: Impossible\n",cas);
    }
    return 0;
}
