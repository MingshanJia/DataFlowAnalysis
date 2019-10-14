// by shik {{{
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(c) begin(c),end(c)
#define REP(i,n) for ( int i=0; i<(int)(n); i++ )
#define REP1(i,a,b) for ( int i=(int)(a); i<=(int)(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}

void WI( int x ) {
    printf("%d\n",x);
}

template<typename... Args>
void WI(int head, Args... tail) {
    printf("%d ",head);
    WI(tail...);
}
/// }}}

#define N 110
#define H 210
#define P 1010

int p,q,n,h[N],g[N];
void input() {
    RI(p,q,n);
    REP(i,n) RI(h[i],g[i]);
}

int dp[N][H][P];
int go( int x, int y, int z ) {
    if ( x==n ) return 0;
    if ( y<1 ) return go(x+1,h[x+1],z);
    int &ret=dp[x][y][z];
    if ( ret!=-1 ) return ret;
    ret=0;
    ret=max(ret,go(x,y-q,z+1));
    if ( z>0 ) ret=max(ret,go(x,y-p,z-1)+(y-p<1?g[x]:0));
    return ret;
}
void solve() {
    memset(dp,-1,sizeof(dp));
    int ans=go(0,h[0],1);
    printf("%d\n",ans);
}

int main( int argc, char *argv[] ) {
    int n_case;
    RI(n_case);
    //fprintf(stderr,"n_case = %d\n",n_case);
    REP1(i,1,n_case) {
        input();
        if ( argc==2 && atoi(argv[1])!=i ) continue;
        if ( argc==3 && (atoi(argv[1])<i || atoi(argv[2])>i) ) continue;
        if ( 1 || argc!=1 ) {
            fprintf(stderr,"Running #%d...\n",i);
            fflush(stderr);
        }
        printf("Case #%d: ",i);
        solve();
        fflush(stdout);
    }
    return 0;
}

