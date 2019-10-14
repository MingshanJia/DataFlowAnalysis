//
//  main.cpp
//  GG_onsite
//
//  Created by 祝风翔 on 15/8/14.
//  Copyright (c) 2015年 祝风翔. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#include <time.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;



vector<int>E[1000 + 5];
int idx = 0;
map<string,int>M;
int get_idx(const string &name) {
    if(M.find(name) == M.end()) {
        M[name] = idx++;
    }
    return M[name];
}
int used[1000 + 5];

bool dfs(int root,int s) {
    if(used[root] != -1) {
        return used[root] == s;
    }
    used[root] = s;
    for(int i = 0;i < E[root].size();i++) {
        if(dfs(E[root][i],s ^ 1) == false)
            return false;
    }
    return true;
}
int main(){
    freopen("A-small-1-attempt1.in","r",stdin);
    freopen("A-small-1-attempt1.out","w",stdout);
    int T,cas = 0;
    scanf("%d",&T);
    while(T--) {
        M.clear();
        int m;
        idx = 0;
        scanf("%d",&m);
        for(int i = 0;i < 3 * m;i++) E[i].clear();
        for(int i = 0;i < m;i++) {
            string a,b;
            cin>>a>>b;
            int aa = get_idx(a);
            int bb = get_idx(b);
            E[aa].push_back(bb);
            E[bb].push_back(aa);
        }
        memset(used,-1,sizeof(used));
        int f = 0;
        for(int i = 0;i < idx;i++) {
            if(used[i] == -1) {
                if(!dfs(i,0)) {
                    f = 1;
                    break;
                }
            }
        }
        if(f ==0)
            printf("Case #%d: Yes\n",++cas);
        else printf("Case #%d: No\n",++cas);
    }
    return 0;
}