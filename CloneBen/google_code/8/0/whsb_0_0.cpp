#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

char mp[512][512];
bool vst[512][512];
int num[512][512];

int N;

bool inrange(int x,int y)
{
    return x>=0&&y>=0&&x<N&&y<N;
}

void dfs(int x,int y)
{
    ///cout<<x<<" "<<y<<endl;
    if(vst[x][y]) return;
    vst[x][y]=true;
    if(num[x][y]!=0) return ;
    for(int ii=x-1;ii<=x+1;ii++)
    for(int jj=y-1;jj<=y+1;jj++)
    {
        if(inrange(ii,jj)&&mp[ii][jj]=='.') dfs(ii,jj);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int casT;
    cin>>casT;
    for(int cas=1;cas<=casT;cas++)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++) scanf("%s",mp[i]);
        memset(vst,0,sizeof(vst));
        for(int i=0;i<N;i++)for(int j=0;j<N;j++)
        {
            if(mp[i][j]=='*')
            {
                num[i][j]=-1;
            }
            else
            {
                num[i][j]=0;
                for(int ii=i-1;ii<=i+1;ii++)
                for(int jj=j-1;jj<=j+1;jj++)
                {
                    if(inrange(ii,jj)&&mp[ii][jj]=='*') num[i][j]++;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<N;i++)for(int j=0;j<N;j++){
            if(vst[i][j]==false&&num[i][j]==0) {dfs(i,j);ans++;}
            ///else cout<<vst[i][j]<<" "<<i<<" "<<j<<" "<<num[i][j]<<endl;
        }
        ///cout<<ans<<endl;
        for(int i=0;i<N;i++)for(int j=0;j<N;j++) if(vst[i][j]==false&&num[i][j]!=-1) ans++;
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
