#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int T;
int n, m;
int ans;
bool vis[10][10];

void dfs(int s, int cnt)
{
    if(s == n * m)
    {
        ans = max(ans, cnt);
        return ;
    }
    int x = s / m, y=0;
    if(s) y = s % m;

    dfs(s+1, cnt);

    if(x > 1 && vis[x-2][y] && vis[x-1][y]) return ;
    if(y > 1 && vis[x][y-2] && vis[x][y-1]) return ;

    vis[x][y] = true;
    dfs(s+1, cnt+1);
    vis[x][y] = false;
}

int main()
{
    
    freopen("/Users/daidaidaiyi/Downloads/B-small-attempt0.in","r",stdin);
    freopen("./out.txt","w",stdout);
    
    cin>>T;
    for(int cases=1; cases<=T; cases++)
    {
        cin>>n>>m;
        ans = 0;
        memset(vis, false, sizeof(vis));
        dfs(0, 0);

        printf("Case #%d: %d\n", cases, ans);
    }
}
