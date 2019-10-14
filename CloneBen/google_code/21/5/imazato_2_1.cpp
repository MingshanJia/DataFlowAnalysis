#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <climits> 
#include <cfloat> 
#include <map> 
#include <utility> 
#include <set> 
#include <iostream> 
#include <memory> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <sstream> 
#include <complex> 
#include <stack> 
#include <queue> 
#include <numeric>
#include <cassert>

#define FOR(i, min, max) for (int i = (min); i < (max); ++i) 
#define FORE(i, min, max) for (int i = (min); i <= (max); ++i) 
#define REP(i, n) for (int i = 0; i < (n); ++i) 
#define REPV(vec, i) for (int i = 0; i < (int)(vec.size()); ++i) 
#define FOR_EACH(vec, it) for (typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); ++it)

using namespace std; 
static const double EPS = 1e-12; 
typedef long long ll; 

int countBitLL(ll n) {
    int ret = 0;
    while(n) {
        if (n & 1LL)
            ++ret;
        n >>= 1LL;
    }
    return ret;
}

ll mem[100][2];  // [桁][繰り上がり]

ll recur(ll keta, ll carry, ll N) {
    if ((1LL<<(keta+1LL)) > N) {
        // 最後の桁
        ll bin = ((N>>keta) & 1LL);
        assert(bin == 1LL);
        if (carry)
            return 0;
        else
            return 1;
    }
    ll &ret = mem[keta][carry];
    if (ret >= 0) {
        return ret;
    }
    ll bin = ((N>>keta) & 1LL);
    ret = 0;
    for (ll a = 0; a < 2; a++) {
        for (ll b = 0; b < 2; b++) {
            if (((a+b+carry) & 1LL) == bin) {
                ret = max(ret, recur(keta+1, ((a+b+carry)>>1), N)+a+b);
            }
        }
    }
    return ret;
}

int solve(void)
{
    ll N;
    cin >> N;

    REP(i, 100)
        mem[i][0] = mem[i][1] = -1;
    return recur(0, 0, N);
}

int main(void)
{
    int T;
    cin >> T;

    REP(_t, T) {
        // cerr << _t+1 << "/" << T << endl;
        cout << "Case #" << _t+1 << ": " << solve() << endl;
    }

    return 0;
}

