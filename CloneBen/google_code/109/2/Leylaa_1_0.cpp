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

int main ()
{
    int T;
    cin >> T;
    rep (tt, T)
    {
    	int d, k, n;
        cin >> d >> k >> n;
        int x, y;
        if ( k&1 )
        {
            x = (k + 2*n - 1) % d;
            y = (k + 2*n + 1) % d;
        }
        else
        {
            x = (k - 2*n - 1 + ll(n)*d) % d;
            y = (k - 2*n + 1 + ll(n)*d) % d;
        }
        if ( x == 0 )
            x = d;
        if ( y == 0 )
            y = d;

    	cout << "Case #" << tt+1 << ": " << y << " " << x << endl;
    }

	return 0;
}