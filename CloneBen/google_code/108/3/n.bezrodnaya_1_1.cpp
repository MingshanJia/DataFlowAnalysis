#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cassert>
#include <climits>
#include <ctime>
using namespace std;

typedef long long     ll;
typedef double        dbl;

#define X             first
#define Y             second
#define mp            make_pair
#define pb            push_back
#define sz(x)         static_cast<int>((x).size())
#define all(x)        x.begin(),x.end()

#ifdef _LOCAL
#    define E(x)          cerr<<#x<<" = "<<(x)<<endl
#    define Es()          cerr<<"------------"<<endl
#    define D(x)          cout<<#x<<" = "<<(x)<<endl
#    define Ds()          cout<<"------------"<<endl
#    define eprintf(...)  printf(__VA_ARGS__);
#else
#    define E(x)             static_cast<void>(0)
#    define Es(x)            static_cast<void>(0)
#    define D(x)             static_cast<void>(0)
#    define Ds(x)            static_cast<void>(0)
#    define eprintf(...)     static_cast<void>(0)
#endif

int main() {
#ifdef _LOCAL
    assert(freopen("B-large.in", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#endif

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        vector <double> p(2*n);
        for (int i = 0; i < 2*n; i++)
            cin >> p[i];

        sort(all(p));
        double ans = 1;
        for (int i = 0; i < n; i++)
            ans *= (1.0 - p[i] * p[2*n - 1 - i]);

        printf("Case #%d: %.10lf\n", t, ans);
    }

#ifdef _LOCAL
    cerr << "\nTIME ELAPSED: " << 1. * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
    return 0;
}
