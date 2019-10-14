#include<bits/stdc++.h>
using namespace std;

#define LL long long int
#define ULL unsigned LL
#define PII pair<int,int>
#define PB push_back
#define MP make_pair
#define INF 1000000000
#define MOD 1000000007

LL dp[301][301];
int M;
LL getans(int m, int n) {
    LL &ret = dp[m][n];
    if (n == 0) 
        return m == 0;
    if (ret == -1) {
        ret = (getans(m - 1, n - 1) * m) % MOD + (getans(m, n - 1) * (M - m)) % MOD;
        ret %= MOD;
    }
    return ret;
}
int main() {
    LL m, n;
    int t, cs = 0;
    cin >> t;
    while (t--) {
        memset(dp, -1, sizeof(dp));
        cin >> m >> n;
        M = m;
        printf("Case #%d: %Ld\n", ++cs, getans(m, n));
    }
    return 0;
}

