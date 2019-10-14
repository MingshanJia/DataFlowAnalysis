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
#define inf (1<<30)
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

#define mx 500

int dx[]={-1,+0,+1,+0,-1,-1,+1,+1};
int dy[]={+0,+1,+0,-1,-1,+1,-1,+1};

int test, kas=0;

char grid[mx][mx];
bool vis[mx][mx];

int n;

int score[mx][mx];


void call( int i, int j ){
    if( i < 0 || i >= n ) return ;
    if( j < 0 || j >= n ) return ;
    if( vis[i][j] ) return ;
    vis[i][j] = true;
    if( score[i][j] > 0 ) return ;
    rep(k,8) call( i+dx[k] , j+dy[k] );
}


int main() {
    read("in.txt");
    rite("outBIG.txt");
    ios_base::sync_with_stdio(0);
    cin>>test;
    while( test-- ){
        cout<<"Case #"<<++kas<<": ";
        //int n;
        cin >> n;
        rep(i,n) cin >> grid[i];
        mem( score, 0 );
        rep(i,n) {
            rep(j,n) {
                rep(k,8) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if( ni < 0 || ni >= n ) continue;
                    if( nj < 0 || nj >= n ) continue;
                    score[i][j] += ( grid[ni][nj] == '*' );
                }
            }
        }
        mem( vis , 0 );
        int ans = 0;
        rep(i,n) {
            rep(j,n) {
                if( vis[i][j] == true ) continue;
                if( grid[i][j] == '*' ) continue;
                if( score[i][j] > 0 ) continue;
                call( i, j);
                ans ++;
            }
        }
        rep(i,n) rep(j,n) ans += ( vis[i][j] == false && grid[i][j] != '*' );
        cout << ans << endl;
    }
    return 0;
}
