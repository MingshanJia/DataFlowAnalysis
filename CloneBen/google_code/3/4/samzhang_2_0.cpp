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

ld pts[3][3];
void solve(){
    REP(i,0,3)REP(j,0,3)cin>>pts[i][j];
    cout<<setprecision(15)<<(max({pts[0][0],pts[1][0],pts[2][0]})-min({pts[0][0],pts[1][0],pts[2][0]}))/6<<endl;
    
    
    
    
    
    
    
    
    
}
int main(){
    fr("/Users/zhangqingchuan/Desktop/C-small-attempt0.in");
    fw("/Users/zhangqingchuan/Desktop/C-small-attempt0.out");
    int t;in(t);
    REP(i,1,t+1){
        printf("Case #%lld: ",i);
        solve();
    }
    return 0;
}
