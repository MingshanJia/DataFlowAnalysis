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

int main() {
    static int T,N,i,j,k;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    get(T);
    rep(k,1,T+1) {
        get(N);
        string t;
        getline(cin,t);
        vector<pair<string,int> > names(N);
        rep(i,0,N){
            getline(cin,names[i].first);
            names[i].second=i;
        }
        sort(names.begin(), names.end() );
        vector<int> v(N);
//        cerr<<"Begin: N="<<N<<'\n';
        rep(i,0,N){
            v[names[i].second]=i;
//            cerr<<' '<<names[i].first<<'\n';
        }
        
        int ans=0;
        for(j=0;j<N;j++){
            rep(i,1,N){
                if(v[i]<v[i-1]){
//                    cerr<<v[i];
                    auto it=upper_bound(v.begin(),v.begin()+i,v[i]);
                    v.insert(it,v[i]);
                    v.erase(v.begin()+i+1);
                    ans++;
                }
            }
        }
        
        cout<<"Case #"<<k<<": ";
        
        cout<<ans<<'\n';
    }
    return 0;
}

