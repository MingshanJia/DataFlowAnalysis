#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
using namespace std;

map<string,int> mp;
vector<int> e[1000];
int cnt,vis[1000];
int ans;

int get(char a[]){
    if(mp.find(a) != mp.end())
        return mp.find(a)->second;
    else{
        cnt++;
        e[cnt].clear();
        mp.insert(make_pair(a,cnt));
        return cnt;
    }
}

void dfs(int u){
    for(int i=0;i<e[u].size();i++){
        int v = e[u][i];
        if(vis[v]==-1){
            vis[v] = vis[u]^1;
            dfs(v);
        }else{
            if(vis[v] == vis[u])
                ans = 0;
        }
    }
}
int main(){
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    freopen("/home/zyc/Downloads/in","r",stdin);
    freopen("/home/zyc/Downloads/out","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        cnt = 0;
        ans = 1;
        mp.clear();
        int m;
        scanf("%d",&m);
        getchar();
        while(m--){
            char a[100],b[100];
            scanf("%s%s",a,b);
            int u,v;
            u = get(a);
            v = get(b);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        clr(vis,-1);
        for(int i=1;i<=cnt;i++){
            if(vis[i] == -1){
                vis[i] = 0;
                dfs(i);
            }
        }
        printf("Case #%d: ",++cas);
        if(ans) puts("Yes");
        else puts("No");
    }
    return 0;

}
