#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <set>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<int> pnt;
typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

static int solve(int k, const vector<pnt> &pnts)
{
    int n = pnts.size();
    int span[1 << n];
    vector<int> options;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            options.push_back(abs(pnts[i].real() - pnts[j].real()));
            options.push_back(abs(pnts[i].imag() - pnts[j].imag()));
        }

    for (int i = 1; i < (1 << n); i++)
    {
        int minx = INT_MAX, miny = INT_MAX;
        int maxx = INT_MIN, maxy = INT_MIN;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
            {
                minx = min(minx, pnts[j].real());
                maxx = max(maxx, pnts[j].real());
                miny = min(miny, pnts[j].imag());
                maxy = max(maxy, pnts[j].imag());
            }
        span[i] = max(maxy - miny, maxx - minx);
    }
    span[0] = INT_MAX;

    sort(RA(options));
    int l = -1;
    int r = options.size() - 1;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        int sz = options[m];

        int req[1 << n];
        req[0] = 0;
        for (int i = 1; i < (1 << n); i++)
        {
            if (span[i] <= sz)
                req[i] = 1;
            else
            {
                req[i] = INT_MAX;
                for (int sub = i; sub != 0; sub = (sub - 1) & i)
                    if (span[sub] <= sz)
                        req[i] = min(req[i], 1 + req[i ^ sub]);
            }
        }

        if (req[(1 << n) - 1] <= k)
            r = m;
        else
            l = m;
    }
    return options[r];
}

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int n, k;
        cin >> n >> k;
        vector<pnt> pnts(n);
        for (int i = 0; i < n; i++)
            cin >> pnts[i].real() >> pnts[i].imag();
        printf("Case #%d: %d\n", cas + 1, solve(k, pnts));
    }
    return 0;
}
