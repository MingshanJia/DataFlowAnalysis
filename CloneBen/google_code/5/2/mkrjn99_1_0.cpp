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
        cout<<"Case #"<<k<<": ";
        
        double v,r;
        const double g=9.80,PI=M_PI;
        cin>>v>>r;
        
        double val=r*g/(v*v);
        if(val>1.0)
            val=1.0;
        
        double ans=(180*asin(val))/(2*PI);
        static char t[100];
        sprintf(t,"%.7lf",ans);
        cout<<t<<'\n';
    }
    return 0;
}

