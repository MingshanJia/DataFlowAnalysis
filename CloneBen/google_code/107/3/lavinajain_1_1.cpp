// Lavina Jain
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MAX 1000000007
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define cases int t; cin>>t; while(t--)
ll mini(ll a,ll b) { if(a<b) return a; return b; }
ll maxi(ll a,ll b) { if(a>b) return a; return b; }
ll mod(ll a) { return a % MAX ; }
ll power(ll a,ll b) { if(b==0) return 1; else if(b%2==0) return power(a*a,b/2); else return a*power(a*a,b/2); }
ll powermod(ll a,ll b) { if(b==0) return 1; else if(b%2==0) return mod(powermod(mod(a*a),b/2)); else return mod(a)*mod(powermod(mod(a*a),b/2)); }
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

int n;
ll num[1010];
ll l[1010];

int main()
{
    fast_io;
    int T;
    cin>>T;
    for(int q=1;q<=T;q++)
    {
        cout<<"Case #"<<q<<": ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>num[i]>>l[i];
        }
        ll bal=0;
        for(int i=0;i<n;i++)
        {
            bal-=(l[i]*num[i]);
            bal=maxi(bal,0);
            bal+=num[i];
        }
        bal=maxi(bal,l[n-1]+1);
        cout<<bal<<endl;
    }
    return 0;
}
