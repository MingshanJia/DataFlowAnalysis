
#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define SIZE(c) (int) (c).size()
#define FORE(i,c) FOR(i,0,SIZE(c)-1)
#define FORDE(i,c) FORD(i,SIZE(c)-1,0)

#define pb push_back
#define mp make_pair
#define st first
#define nd second


using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

typedef vector <int> VI;
typedef vector <bool> VB;
typedef vector <pii> VP;
typedef vector <ll> VL;
typedef vector <pll> VPL;

typedef vector <VI> VVI;
typedef vector <VL> VVL;
typedef vector <VB> VVB;
typedef vector <VP> VVP;

const int MOD = 1000000007;
const int INF = 1000000001;
const ll LINF = 1000000000000000001LL;

/*************************************************************************/

const int T = 24 * 60;

int owner[T];
int dp[T+1][2][T/2+1];

int solve() {
    int n, m;
    cin >> n >> m;
    
    FOR(i,0,T-1) owner[i] = -1;
    
    FOR(i,1,n+m) {
        int l, r;
        cin >> l >> r;
        
        FOR(j,l,r-1) {
            owner[j] = i > n;
        }
    }
    
    int ans = INF;
    
    FOR(wantedLast,0,1) {
        FOR(i,0,T) FOR(last,0,1) FOR(sum,0,T/2) {
            dp[i][last][sum] = (i == 0 && last == wantedLast && sum == 0 ? 0 : INF);
        }
        
        FOR(i,0,T-1) FOR(last,0,1) FOR(sum,0,T/2) if (dp[i][last][sum] < INF) {
            FOR(next,0,1) if (owner[i] != 1 - next) {
                int nextSum = sum + next;
                if (nextSum > T/2) continue;
                
                dp[i+1][next][nextSum] = min(dp[i+1][next][nextSum], dp[i][last][sum] + (last != next));
            }
        }
        
        ans = min(ans, dp[T][wantedLast][T/2]);
    }
    
    return ans;
}

/*************************************************************************/

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;
    
    FOR(i,1,t) {
        cout << "Case #" << i << ": " << solve() << '\n';
    }

    return 0;
}

/*************************************************************************/

