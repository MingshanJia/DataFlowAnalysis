#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define maxn 105
vector <int> edge[maxn];
map <string,int> mp;
int vis[maxn];
bool bfs(int s)
{
    queue <int> q;
    q.push(s);
    vis[s]=0;
    int now;
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        for(int i=0;i<edge[now].size();i++)
        {
            int v = edge[now][i];
            if(v == now) continue;
            if(vis[v]==-1)
            {
                vis[v]= (vis[now]==0?1:0);
                q.push(v);
            }
            else if(vis[v]==vis[now])
                return false;
        }
    }
    return true;
}
int main()
{
    string s1,s2;
    int T,n,cas=0;
    cin>>T;
    while(T--)
    {
        mp.clear();
        cin>>n;
        int cnt=1;
        for(int i=1;i<=100;i++) edge[i].clear();
        for(int  i=1;i<=n;i++)
        {
            cin>>s1>>s2;
            if(mp.find(s1)==mp.end())
                mp[s1]=cnt++;
            if(mp.find(s2)==mp.end())
                mp[s2]=cnt++;
            edge[mp[s1]].push_back(mp[s2]);
            edge[mp[s2]].push_back(mp[s1]);
        }
        printf("Case #%d: ",++cas);
        memset(vis,-1,sizeof(vis));
        bool flag=true;
        for(int i=1;i<=cnt-1;i++)
        {
            if(vis[i]==-1)
            {
                if(bfs(i)) continue;
                else {flag=false;break;}
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
