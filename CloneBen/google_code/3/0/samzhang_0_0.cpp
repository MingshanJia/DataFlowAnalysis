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
#define REP(x,l,u) for(int x = l;x<u;x++)
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


int dp[310][310][310];
int mini[310];

int alr[310];

int same[610][610][610];
void solve(){
    typedef pair<int, tuple<int,int,int>> elem;
    mst(alr,0);
    string s;cin>>s;
    mst(same,0);
    s = " "+s;
    REP(i,1,sz(s)){
        REP(j,1,sz(s)){
            REP(len,1,sz(s)){
                if(len>1){
                    same[i][j][len] = same[i][j][len-1] && (s[i+len-1]==s[j+len-1]);
                }else{
                    same[i][j][len] = s[i] == s[j];
                }
            }
        }
    }
    mst(dp,0x3f);
    mst(mini,0x3f);
    
    priority_queue<elem,vector<elem>,greater<elem>>pq;
    pq.push(MP(1,make_tuple(1,0,0)));
    while (sz(pq)) {
        auto cost = pq.top().fi;
        auto co = pq.top().se;pq.pop();
        auto a = get<0>(co),b = get<1>(co),c = get<2>(co);
        if(a == sz(s)-1){
            cout<<cost<<endl;
            return;
        }
        if(cost<dp[a][b][c]){
            dp[a][b][c] = cost;
            mini[a] = min(mini[a],cost);
            if(!alr[a]){
                alr[a] = 1;
                REP(i,1,a+1){
                    REP(j,i,a+1){
                        pq.push(MP(cost+1,make_tuple(a,i,j)));
                    }
                }
            }
            pq.push(MP(cost+1,make_tuple(a+1,b,c)));
            if(same[a+1][b][c-b+1]){
//                if(a == 6 && b == 1 && c == 5){dbg(111);
//                dbg(cost+1);
//                dbg(a+c-b+1);
//                dbg(b);
//                    dbg(c);}
                pq.push(MP(cost+1,make_tuple(a+c-b+1,b,c)));
            }
        }
    }
//    dp[1][0][0] = 1;
//    mini[1] = 1;
//    for(int i = 1;i<sz(s);i++){
//        dp[i][0][0] = min(dp[i][0][0],dp[i-1][0][0]+1);
//        mini[i] = min(mini[i],dp[i][0][0]);
//        for(int j = 1;j<=i;j++){
//            for(int k = j;k<=i;k++){
//                dp[i][j][k] = min(dp[i][j][k],dp[i-1][j][k]+1);
//                dp[i][j][k] = min(dp[i][j][k],mini[i]+1);
//                
//            }
//        }
//    }
    
}
// 1 aaaaaaaaaaa
int main(){
    fr("/Users/zhangqingchuan/Desktop/A-small-attempt0.in");
    fw("/Users/zhangqingchuan/Desktop/A-small-attempt0.out");
    int t;in(t);
    REP(i,1,t+1){
        printf("Case #%d: ",i);
        solve();
//        dbg(dp[3][0][0]);
//        dbg(dp[3][1][3]);
//        dbg(dp[6][1][3]);
//        dbg(dp[6][1][5]);
//        
//        dbg(same[6+1][1][5]);
//        
//        dbg(dp[11][1][5]);
    }
    return 0;
}
