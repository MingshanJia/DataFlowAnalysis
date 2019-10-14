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

ll solve(void)
{
    ll N, K;
    cin >> N >> K;
    vector<ll> C(N), T(N), S(N);
    REP(i, N) {
        cin >> C[i] >> T[i] >> S[i];
        --T[i];
    }
    

    ll ret = 0;
    for (ll t = K-1; t >= 0; --t) {
        ll bestS = 0;
        ll bestI = -1;
        REP(i, N) if (C[i] && t <= T[i] && S[i] > bestS) {
            bestS = S[i];
            bestI = i;
        }
        if (bestI != -1) {
            ret += bestS;
            --C[bestI];
        }
    }
    return ret;
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

