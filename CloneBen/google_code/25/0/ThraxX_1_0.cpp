#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
using namespace std;

int T,V,E,a,b,n,r;
bool isGood;
int deg[1001];
bool visited[1001];
bool adj[1001][1001];
void dfs(int j){
    if(!visited[j]){
        visited[j] = true;
        if(deg[j]&1)isGood = false;
        for(int i = 0 ; i <V;++i)
            if(adj[i][j])
                dfs(i);
    }
}
int main(){
    fstream get;
    get.open("test.txt");
    get>>T;
    for(int i = 0;i<T;++i){
        get>>V;
        get>>E;
        for(int j = 0 ; j<E;++j){
            get>>a>>b;
            adj[a][b] = adj[b][a] = true;
            deg[a]++;
            deg[b]++;
        }
        r = 0; n = 0;
        for(int j = 0 ; j<V;++j)
            if(deg[j]&1)r++;
        for(int j = 0 ; j<V;++j)
            
            if(!visited[j]){
                isGood = true;
                dfs(j);
            if(isGood&&deg[j]!=0)n++;
            }
        
        printf("Case #%d: %d\n",i+1,r/2+((r==0&&n==1)?0:n));
        memset(deg,0,sizeof(deg));
        memset(adj,0,sizeof(adj));
        memset(visited,0,sizeof(visited));
    }
    get.close();
    return 0;
}
