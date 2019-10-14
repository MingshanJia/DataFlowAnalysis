#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <deque>
#include <map>
#include <algorithm>
#define forn(i,n) for(int i=0;i<n;i++)
#define clr(a,b) memset(a,b,sizeof(a))
#define ll long long
#define Min(a,b) if(a>b)a=b
#define MP(x,y) make_pair(x,y)
#define sqr(x) ((x)*(x))
using namespace std;

int n,g[100][100];
int vis[100];

int main() {
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    freopen("/home/zyc/Downloads/in","r",stdin);
    freopen("/home/zyc/Downloads/out","w",stdout);
    int T,cas=0;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        bool flag=true;
        for(int i=1;i<=n*n;i++)
            for(int j=1;j<=n*n;j++){
                scanf("%d",&g[i][j]);
                if(g[i][j]>n*n || g[i][j]<1)
                    flag=false;
            }
        if(flag){
        for(int i=1;i<=n*n;i++){
            clr(vis,0);
            for(int j=1;j<=n*n;j++)
                vis[g[i][j]]++;
            for(int j=1;j<=n*n;j++)
                if(vis[j]!=1)
                    flag=false;
        }
        for(int j=1;j<=n*n;j++){
            clr(vis,0);
            for(int i=1;i<=n*n;i++)
                vis[g[i][j]]++;
            for(int i=1;i<=n*n;i++)
                if(vis[i]!=1)
                    flag=false;
        }
        for(int i=1;i<=n*n;i+=n){
            for(int j=1;j<=n*n;j+=n){
                clr(vis,0);
                for(int k=i;k<i+n;k++)
                    for(int l=j;l<j+n;l++)
                        vis[g[k][l]]++;
                for(int k=1;k<=n*n;k++)
                    if(vis[k]!=1)
                        flag=false;
            }
        }
        }
        printf("Case #%d: ",++cas);
        if(flag) puts("Yes");
        else puts("No");
    }

    return 0;
}
