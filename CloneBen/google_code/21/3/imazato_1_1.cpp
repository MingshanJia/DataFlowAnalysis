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

ll getNextTime(const vector<ll> &T, const vector<ll> &C, ll curTime, int bestI) {
    ll t1 = (bestI == -1) ? -1LL : max(-1LL, curTime-C[bestI]);
    ll t2 = -1LL;
    int size = T.size();
    REP(i, size) if (T[i] < curTime && T[i] > t2) {
        t2 = T[i];
    }
    return max(t1, t2);
}

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
    ll t = K-1;
    //for (ll t = K-1; t >= 0; --t) {
    while(t != -1) {
        ll bestS = 0;
        ll bestI = -1;
        REP(i, N) if (C[i] && t <= T[i] && S[i] > bestS) {
            bestS = S[i];
            bestI = i;
        }
        ll nextT = getNextTime(T, C, t, bestI);
        assert(nextT < t);
        if (bestI != -1) {
            ret += bestS*(t-nextT);
            C[bestI] -= (t-nextT);
            assert(C[bestI] >= 0);
        }
        t = nextT;
    }
    return ret;
}

int main(void)
{
    int T;
    cin >> T;
    REP(_t, T) {
        cout << "Case #" << _t+1 << ": " << solve() << endl;
    }

    return 0;
}

