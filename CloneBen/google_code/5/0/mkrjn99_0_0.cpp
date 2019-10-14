#include <bits/stdc++.h>
#define gcd         __gcd
#define bitcount    __builtin_popcountll
#define rep(i,j,n)  for(i=j;i<n;i++)
#define tr(it,c)    for(auto it=(c).begin();it!=(c).end();it++)
#define pb          push_back
#define mp          make_pair
#define hell        1000000007
#define uset        unordered_set
#define umap        unordered_map
using namespace std;
typedef pair<int,int> pi;
typedef long long ll;

template <class T> T& get(T &n) {
    cin>>n;
    return n;
}

bool solve(){

    int n=0,m,i;
    cin>>m;
    vector<pi> edges(m);
    string x,y;
    umap<string,int> n2v;
    rep(i,0,m){
        cin>>x>>y;
        int p,q;
        if(n2v.count(x))
            p=n2v[x];
        else
            p=n2v[x]=n++;

        if(n2v.count(y))
            q=n2v[y];
        else
            q=n2v[y]=n++;

        edges[i]=mp(p,q);
    }
    
    vector<vector<int> > adj(n);
    
    rep(i,0,m){
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    
    vector<int> label(n,0);
    
    queue<int> q;
    
    bool f=true;
    
    for(int j=0;j<n;j++){
        if(label[j]==0){
            q.push(j);
            label[j]=1;
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            tr(it,adj[x]){
                if(label[*it]==0){
                    label[*it]=~label[x];
                    q.push(*it);
                }
                else if(label[*it]==label[x]){
                    f=false;
                }
                else{
                    //Do nothing
                }
            }
        }
    }
    
    cerr<<"label: ";
    rep(i,0,n){
        cerr<<label[i]<<' ';
    }
    cerr<<endl;
    
    return f;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int i,T;
    cin>>T;
    rep(i,1,T+1){
        cout<<"Case #"<<i<<": "<<(solve()?"Yes\n":"No\n");
    }
    
    return 0;
}

