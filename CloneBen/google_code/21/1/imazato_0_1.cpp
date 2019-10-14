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

int solve(void)
{
    int M, C, W;
    cin >> M >> C >> W;
    vector<int> A(C);
    vector<int> B(C);
    REP(i, C) {
        cin >> A[i] >> B[i];
        --A[i];
    }
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    int w = W-1;
    int size = A.size();
    REP(i, size) {
        int uleft = A[i];
        int dleft = M-(A[i]+B[i]);
        if (w < B[i]) {
            w = uleft+w;
        } else if (w < B[i]+uleft) {
            w = w-B[i];
        } else {
            assert(w < M);
            w = w;
        }
    }

    return w+1;
}

int main(void)
{
    int T;
    cin >> T;
    REP(_t, T) {
        //cerr << _t+1 << "/" << T << endl;
        cout << "Case #" << _t+1 << ": " << solve() << endl;
    }

    return 0;
}

