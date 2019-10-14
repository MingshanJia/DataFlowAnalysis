#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

#define maxn 1010

int maze[maxn][maxn];

int dp[maxn][maxn];

int S;

int dir[4][2]={-1,0,1,0,0,1,0,-1};

int dfs(int x,int y)
{
    int i,ans=0,value=maze[x][y];
    if(x<0||y<0||x>=S||y>=S)return 0;
    if(dp[x][y]!=-1)return dp[x][y];
    for(i=0;i<4;i++)
    {
        int tempx=x+dir[i][0];
        int tempy=y+dir[i][1];
        if(tempx<0||tempy<0||tempx>=S||tempy>=S)
            continue;
        if(maze[tempx][tempy]==maze[x][y]+1)
        ans=max(ans,dfs(tempx,tempy));
    }
    dp[x][y]=ans+1;
    return dp[x][y];
}

int main()
{
    int T,i,j,casn,temp,ansid,ans;
    scanf("%d",&T);
    for(casn=0;casn<T;casn++)
    {
        scanf("%d",&S);
        for(i=0;i<S;i++)
            for(j=0;j<S;j++)
                scanf("%d",&maze[i][j]);
        memset(dp,-1,sizeof(dp));
        ans=0;
        for(i=0;i<S;i++)
        {
            for(j=0;j<S;j++)
            {
                temp=dfs(i,j);
                if(ans<temp)
                {
                    ans=temp;
                    ansid=maze[i][j];
                }
                else if(ans==temp&&maze[i][j]<ansid)
                {
                    ansid=maze[i][j];
                }
            }
        }
        printf("Case #%d: %d %d\n",casn+1,ansid,ans);
    }
    return 0;
}
