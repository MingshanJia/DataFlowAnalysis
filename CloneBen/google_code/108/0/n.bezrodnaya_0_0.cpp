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
    assert(freopen("A-small-attempt0.in", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#endif

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int F, S;
        cin >> F >> S;
        vector <pair <int, int> > v(F);
        for (int i = 0; i < F; i++) {
            cin >> v[i].X >> v[i].Y;
            v[i].X--;
            v[i].Y--;
        }

        int ans = 0;
        for (int r = 0; r < S; r++) {
            vector <bool> used(S, false);
            for (int i = 0; i < F; i++) {
                if (v[i].X == r) {
                    used[v[i].Y] = true;
                } else if (v[i].Y == r) {
                    used[v[i].X] = true;
                }
            }
            int c = 0;
            for (int i = 0; i < S; i++)
                c += used[i];
            ans = max(ans, c);
        }
        printf("Case #%d: %d\n", t, ans);
    }

#ifdef _LOCAL
    cerr << "\nTIME ELAPSED: " << 1. * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
    return 0;
}
