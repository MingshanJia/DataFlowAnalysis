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

#define N 1000010
int n,a[N];
void input() {
    int p,q,r,s;
    RI(n,p,q,r,s);
    REP(i,n) a[i]=(1LL*i*p+q)%r+s;
}

LL sa[N];
void solve() {
    REP(i,n) sa[i+1]=sa[i]+a[i];
    LL ans=0;
    auto chk=[&]( int a, int b ) {
        if ( a>b || b>=n ) return;
        LL c1=sa[a];
        LL c2=sa[b+1]-sa[a];
        LL c3=sa[n]-sa[b+1];
        ans=max(ans,sa[n]-max(c1,max(c2,c3)));
    };
    REP(i,n) {
        int l=i,r=n-1;
        while ( l!=r ) {
            int m=(l+r)/2;
            // [i,m]
            LL c1=sa[m+1]-sa[i];
            // [m+1,n-1]
            LL c2=sa[n]-sa[m+1];
            if ( c1>c2 ) r=m;
            else l=m+1;
        }
        REP1(j,-2,+2) chk(i,l+j);
    }
    double r=1.0*ans/sa[n];
    printf("%.12f\n",r);
}

int main( int argc, char *argv[] ) {
    int n_case;
    RI(n_case);
    //fprintf(stderr,"n_case = %d\n",n_case);
    REP1(i,1,n_case) {
        input();
        if ( argc==2 && atoi(argv[1])!=i ) continue;
        if ( argc==3 && (atoi(argv[1])<i || atoi(argv[2])>i) ) continue;
        if ( argc!=1 ) {
            fprintf(stderr,"Running #%d...\n",i);
            fflush(stderr);
        }
        printf("Case #%d: ",i);
        solve();
        fflush(stdout);
    }
    return 0;
}

