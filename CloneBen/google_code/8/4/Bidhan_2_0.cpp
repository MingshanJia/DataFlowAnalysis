/*
 * Bidhan Roy
 * University of Dhaka
 */

using namespace std;

#include "ttmath/ttmath.h"
#include <bits/stdc++.h>

using namespace ttmath;

#define fore(x,n) for(auto x : n)
#define sgn(x,y) ((x)+eps<(y)?-1:((x)>eps+(y)?1:0))
#define rep(i,n) for(auto i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define rite(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<27)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9

typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef pair<i64,i64> pll;
typedef vector<pll> vpll;
typedef Int<10> BigInt;

#define mx 2000000

int test, kas=0;

int Length[mx];
vi Divisors[mx];

void precalc(){
    for( int i=1; i <= 1000000; i++ ) {
        for( int j = i+i; j <= 1000000; j += i ) {
            Divisors[j].pb(i);
        }
        int num = i;
        while( num > 0 ) Length[i] ++, num /= 10;
    }
}

bool can[10];

int dp[mx];

int pdp[mx];
int possible( int n ) {
    int &ret = pdp[n];
    if( ret != -1 ) return ret;
    ret = 0;
    while( n > 0 ) {
        if( can[ (n%10) ] == false )
            return ret;
        n /= 10;
    }
    return ret = 1;
}

int call( int n ) {
    int &ret = dp[n];
    if( ret != -1 ) return ret;
    ret = inf;
    if( possible(n) ) ret = Length[n];
    for( auto x : Divisors[n]) {
        int y = n / x;
        //if( !possible(x) ) continue ;
        //if( !possible(y) ) continue ;
        ret = min( ret , call(x) + 1 + call(y) );
    }
    return ret;
}

int main() {
    precalc();
    read("in.txt");
    rite("outSMALL.txt");
    ios_base::sync_with_stdio(0);
    cin>>test;
    while( test-- ){
        cout<<"Case #"<<++kas<<": ";
        rep(i,10) cin >> can[i];
        int n;
        cin >> n;
        mem( dp, -1 );
        mem( pdp, -1 );
        int ans = call(n);
        ans ++;
        if( ans >= inf ) cout << "Impossible" << endl;
        else cout << ans << endl;
    }
    return 0;
}
