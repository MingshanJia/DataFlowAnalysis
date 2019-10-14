#include <bits/stdc++.h>
using namespace std;
int t,m;
map<string,int> mp;
int get(string &s){
    //cout<<mp.size()<<endl;
    if(mp.count(s) == 0){
        int id = mp.size();
        mp[s] = id;

    }
    //cout<<s<<" "<<mp[s]<<endl;
    return mp[s];
}
vector<int> G[1000];
int color[1000];
bool bfs(int id){
    queue<int> qu;
    qu.push(id);
    color[id] = 1;
    while(!qu.empty()){
        int x = qu.front();
        qu.pop();
        int c = color[x];
        for(int i=0;i<G[x].size();i++){
            int y = G[x][i];
            if(color[y] == 0){
                qu.push(y);
                color[y] = -c;
            }else if(color[y] == c){
                return false;
            }

        }
    }
    return true;
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        cin>>m;
        for(int i=0;i<1000;i++){
            G[i].clear();
            color[i] = 0;
        }
        string s1,s2;
        int a,b,fa,fb;

        for(int i=0;i<m;i++){
            cin>>s1>>s2;
            a = get(s1);
            b = get(s2);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        int n = mp.size();
        bool ok = true;
        for(int i=0;i<n;i++){
            if(color[i] == 0 ){
                ok &= bfs(i);
            }
        }
        cout<<"Case #"<<cs<<":";

        if(ok){
            cout<<" Yes\n";
        }else{
            cout<<" No\n";
        }
        //cout<<st.size()<<endl;
    }
    return 0;
}
