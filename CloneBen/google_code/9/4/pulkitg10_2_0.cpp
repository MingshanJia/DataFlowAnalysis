#include<bits/stdc++.h>
using namespace std;
 
#define LL long long int
#define ULL unsigned LL
#define PII pair<int,int>
#define PB push_back
#define MP make_pair
#define INF 1000000000
#define MOD 1000000007
 
map<int, vector<int> > v;
int a[2000000];
int n, K;
int dp[200][200];
int getans(int cs, int ce) {
    if (ce - cs + 1 < 3)
        return ce - cs + 1;
    int &ret = dp[cs][ce];
    if (ret == -1) {
        int j1 = 0, j2 = 0;
        int ele1 = a[cs] + K;
        int ele2 = a[cs] + 2 * K;
        ret = 1 + getans(cs + 1, ce);
        if (v.count(ele1) != 0 && v.count(ele2) != 0) {
            for (j1 = 0; j1 < (int)v[ele1].size(); j1++) {
                for (j2 = 0; j2 < (int)v[ele2].size(); j2++) {
                    int loc1 = v[ele1][j1];
                    int loc2 = v[ele2][j2];
                    if (loc1 > cs && loc2 > loc1 && ce >= loc2) {
                        if (getans(cs + 1, loc1 - 1) == 0 && getans(loc1 + 1, loc2 - 1) == 0) 
                            ret = min(ret, getans(loc2 + 1, ce));
                    }
                }
            }
        }
    }
    return ret;
}
int main() {
    int t, i, cs = 0;
    cin >> t;
    while (t--) {
        cin >> n >> K;
        v.clear();
        memset(dp, -1, sizeof(dp));
        for (i = 1; i <= n; i++) { 
            cin >> a[i];
            v[a[i]].PB(i);
        }
        printf("Case #%d: %d\n", ++cs, getans(1, n));
    }
    return 0;
}

