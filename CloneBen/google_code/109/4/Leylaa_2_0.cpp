// In the name of Allah

#include <vector>
#include <map>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <complex>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <iomanip>
#include <set>
#include <stack>
#include <stdio.h>

using namespace std;

#define dbg(x) cerr << #x << " = " << (x) << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define rep(i,n) for (int i = 0; i < (n); i ++)
#define repd(i,n) for (int i = (n); i >= 0; i --)
#define PI 3.14159265358979323846
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int max_l = 500+10;
ll dp [max_l][2];
const int mod = 1000*1000*1000+7;

int main ()
{
    int T;
    cin >> T;
    rep (tt, T)
    {
    	int C, V, L;
        cin >> C >> V >> L;

        memset (dp, 0, sizeof dp);
        dp [0][0] = C;
        dp [0][1] = V;
        rep (l, L-1)
        {
            dp [l+1][0] += C * dp [l][1];
            dp [l+1][0] %= mod;
            dp [l+1][1] += V * (dp [l][0] + dp [l][1]);
            dp [l+1][1] %= mod;
        }
    	cout << "Case #" << tt+1 << ": " << dp [L-1][1] << endl;
    }

	return 0;
}