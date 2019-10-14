#include "bits/stdc++.h"
//#include "ext/pb_ds/tree_policy.hpp"
//#include "ext/pb_ds/assoc_container.hpp"
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define mst(x,a) memset(x,a,sizeof(x))
#define all(a) a.begin(),a.end()
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define sqr(x) ((x)*(x))
#define lowbit(x) (x&(-x))
#define lson (ind<<1)
#define rson (ind<<1|1)
#define se second
#define fi first
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define sz(x) ((int)x.size())
#define EX0 exit(0);

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;
const int block_size = 320;
typedef complex<ll> point;
const ll mod = 1e9+7;
const ld eps = 1e-9;
const int inf = mod;
const db PI = atan(1)*4;
template<typename T>
inline int sign(const T&a){if(a<0)return -1;if(a>0)return 1;return 0;}


template<typename T> inline void in(T &x){
    x = 0; T f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}

ll twop(int x){return 1LL<<x;}

template<typename A,typename B > inline void in(A&x,B&y){in(x);in(y);}
template<typename A,typename B,typename C>inline void in(A&x,B&y,C&z){in(x);in(y);in(z);}
template<typename A,typename B,typename C,typename D> inline void in(A&x,B&y,C&z,D&xx){in(x);in(y);in(z);in(xx);}




template <class T>
void upd(T&a,T b) {
    a = max(a,b);
}

ll c(ll n,ll m){
    ll ans = 1;
    REP(i,0,m)ans*=(n-i);
    REP(i,0,m)ans/=(i+1);
    return ans;
}


void bf(){
    int n;in(n);
    vector<ll>a(n);
    
    REP(i,0,n)in(a[i]);
    sort(all(a));
    
    ll ans = 0;
    REP(i,0,n){
        REP(j,i+1,n){
            REP(k,j+1,n){
                REP(t,k+1,n){
                    if(a[i]+a[j]+a[k]>a[t] && min({a[i],a[j],a[k],a[t]})!=max({a[i],a[j],a[k],a[t]}) && !(a[i]==a[j] && a[k]==a[t]) && (a[i]==a[j]||a[j]==a[k]||a[k]==a[t])){
                        ans++;
                    }
//                    dbg(a[i]+a[j]+a[k]>a[t]);
//                    dbg(min({a[i],a[j],a[k],a[t]})!=max({a[i],a[j],a[k],a[t]}));
//                    dbg(!(a[i]==a[j] && a[k]==a[t]));
//                    dbg((a[i]==a[j]||a[j]==a[k]||a[k]==a[t]));
                    
                }
            }
        }
    }
    cout<<ans<<endl;
}

ll affect[5010];
typedef pair<ll, PLL> ele;

ll getOcc(vector<PLL>&prefix,int ind){
    if(ind>sz(prefix))assert(0);
    return prefix[ind].se-prefix[ind-1].se;
}
void solve(){
    mst(affect,0);
    int n;in(n);
    vector<ll>v(n);
    REP(i,0,n)in(v[i]);
    sort(all(v));
    map<ll, int>cnt;
    for(auto i:v)cnt[i]++;
    vector<PLL>prefix;
    prefix.PB(MP(-1,0));
    for(auto i:cnt)prefix.PB(i);
    REP(i,1,sz(prefix))prefix[i].se+=prefix[i-1].se;
    
    
    
    ll ans = 0;
    REP(i,1,sz(prefix)){
        ll cur = prefix[i].se-prefix[i-1].se;
        if(cur>=3){
            ans+=c(cur,3)*(prefix[i-1].se);
            REP(j,i+1,sz(prefix)){
                if(prefix[j].fi<prefix[i].fi*3)ans+=(prefix[j].se-prefix[j-1].se)*(c(cur,3));
            }
        }
    }
    

    priority_queue<ele,vector<ele>,greater<ele>>pq;
    REP(i,1,sz(prefix)-1){
        pq.push(MP(prefix[i+1].fi-prefix[i].fi,MP(i,i+1)));
    }
    ll sum = 0;
    REP(i,1,sz(prefix)){
        while(sz(pq) && pq.top().fi<prefix[i].fi*2){
            auto t = pq.top();pq.pop();
            ll tmp = getOcc(prefix, t.se.fi)*getOcc(prefix, t.se.se);
            affect[t.se.fi]+=tmp;
            affect[t.se.se]+=tmp;
            sum+=tmp;
            if(t.se.se<sz(prefix)-1){
                pq.push(MP(prefix[t.se.se+1].fi-prefix[t.se.fi].fi,MP(t.se.fi,t.se.se+1)));
            }
        }
        ans+=(sum-affect[i])*c(getOcc(prefix, i),2);
    }

    cout<<ans<<endl;






}
int main(){
    fr("/Users/zhangqingchuan/Desktop/B-large.in");
    fw("/Users/zhangqingchuan/Desktop/B-large.out");
    int t;in(t);
    REP(i,1,t+1){
        printf("Case #%lld: ",i);
        solve();
    }
    return 0;
}
