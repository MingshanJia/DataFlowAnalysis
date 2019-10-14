#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;
vector<int> e[210];
int vis[210];
int dfs(int now,int c){
    int size=e[now].size();
    vis[now]=c;
    for(int i=0;i<size;i++){
        int v=e[now][i];
        if(vis[v]==-1){
            if(!dfs(v,1-c))
                return 0;
        }
        else{
            if(vis[v]==c)
                return 0;
        }
    }
    return 1;
}
int main(){
    freopen("dd.in","r",stdin);
    freopen("out.txt","w+",stdout);
    int ncase,T=0;
    scanf("%d",&ncase);
    while(ncase--){
        int n,num=0;
        scanf("%d",&n);
        map<string,int> mp;
        for(int i=0;i<=n*2;i++)
            e[i].clear();
        for(int i=0;i<n;i++){
            string st1,st2;
            cin>>st1>>st2;
            if(mp[st1]==0)
                mp[st1]=++num;
            if(mp[st2]==0)
                mp[st2]=++num;
            e[mp[st1]].push_back(mp[st2]);
            e[mp[st2]].push_back(mp[st1]);
        }
        memset(vis,-1,sizeof(vis));
            int tru=1;
            for(int i=1;i<=num;i++){
                if(vis[i]==-1){
                    if(!dfs(i,0))
                        tru=0;
                }
            }
        printf("Case #%d: ",++T);
            if(tru)
                printf("Yes\n");
            else
                printf("No\n");
    }
    return 0;
}
