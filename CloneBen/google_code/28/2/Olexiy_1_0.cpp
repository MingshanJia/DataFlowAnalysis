#pragma warning(disable : 4018)
#include <map>
#include <assert.h>
#include <set>
#include <sstream>
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>

#ifdef __GNUC__
typedef long long lint;
typedef unsigned long long ulint;
#else
typedef __int64 lint;
typedef unsigned __int64 ulint;
#endif

using namespace std;

#define FOR(iter, bound) for(size_t iter=0; iter < (bound); iter++)
#define SFOR(iter, start, bound) for (int iter = (start); iter<(bound); iter++)
#define ALL(C) C.begin(), C.end()
#define VSORT(vec) sort(ALL(vec))
#define MP(a, b) make_pair((a), (b))

typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<int> VI;
typedef vector<lint> VL;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<double> VD;
typedef vector<vector<double> > VVD;
typedef pair<int, int> PII;
typedef vector<PII> VP;
typedef vector<VP> VVP;

VS Parse(string str, string look_for = " ", bool i_push_empty = false)
{
    VS ans;
    if (look_for.length() == 0)
    {
        ans.push_back(str);
        return ans;
    };
    string last = "";
    int pos = 0;
    while (true)
    {
        if (pos == str.length())
        {
            if (last.length() != 0)
                ans.push_back(last);
            return ans;
        };
        if (look_for.find(str[pos]) == string::npos)
            last.append(1, str[pos]);
        else
        {
            if (i_push_empty || last.length() != 0)
                ans.push_back(last);
            last = "";
        };
        pos++;
    };
    return ans;
};


template<class C>
void PRV(vector<C> vec)
{
    cout << "{";
    FOR(i, vec.size()) {cout << vec[i] << ",";};
    cout << "}";
};


lint GetLint(string ss)
{
    lint ans = 0;
    int pos = 0;
    while (pos < ss.length() && !isdigit(ss[pos]))
        pos++;
    while (pos < ss.length() && isdigit(ss[pos]))
        ans *= lint(10), ans += lint(ss[pos++] - '0');
    return ans;
}

int N, K;
VP data;
VVI memo;
VI ones;
VI solve;

int SS(int mask) {
    if (mask == 0)
        return 0;
    int& ans = solve[mask];
    if (ans != -1)
        return ans;
    int x1 = 1000000;
    int x2 = 0;
    int y1 = 10000000;
    int y2 = 0;
    FOR(i, N)
        if ((1 << i) & mask) {
            int x = data[i].first;
            int y = data[i].second;
            x1 = min(x, x1);
            x2 = max(x, x2);
            y1 = min(y, y1);
            y2 = max(y, y2);
        }
    return ans = max(y2-  y1, x2 - x1);
}

int GV(int sq, int mask) {
    if (ones[mask] <= sq)
        return 0;
    if (sq == 0)
        return 1000000;
    int& ans = memo[sq][mask];
    if (ans != -1)
        return ans;
    ans = 1000000;
    SFOR(i, 1, mask + 1) if (((mask & i) == i) && (i >= mask - i)) {
        ans = min(ans, max(SS(i), GV(sq - 1, mask - i)));
    }
    return ans;
}

void ff() {
    VSORT(data);
    memo = VVI(K + 1, VI((1 << N), -1));
    ones = VI(1 << N);
    SFOR(i, 1, (1 << N))
        ones[i] = 1 + ones[i & (i - 1)];
    solve = VI(1 << N, -1);
    cout << GV(K, (1 << N) - 1);
}


void main() {
    string sname = "B-small-attempt0";
    FILE* in = freopen(("d:\\down\\" + sname + ".in").c_str(), "r", stdin);
    FILE* out = freopen(("d:\\contests\\usaco\\" + sname + ".out").c_str(), "w+", stdout);

    int T;
    cin >> T;
    FOR(q, T) {
        cin >> N >> K;
        data = VP(N);
        FOR(i, N) {
            int x; int y;
            cin >> x;
            cin >> y;
            data[i] = MP(x, y);
        }

        cout << "Case #" << (q + 1) << ": ";
        ff();
        cout << endl;
    }
    fclose(in);
    fclose(out);
}
