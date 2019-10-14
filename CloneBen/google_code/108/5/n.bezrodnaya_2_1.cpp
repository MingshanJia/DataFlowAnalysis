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

int calc(vector <string> s) {
    int n = sz(s);
    int m = sz(s[0]);
   
    int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] != 'I')
                continue;
            for (int k = 0; k < 8; k++) {
                int x = i + 2 * dx[k];
                int y = j + 2 * dy[k];
                if (0 <= x && x < n && 0 <= y && y < m) {
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    if (s[xx][yy] == '/' && s[x][y] == 'O')
                        ans++;
                }
            }
        }
    }
    return ans;
}


vector <string> build(int n) {
    vector <string> s;
    for (int i = 0; i < 3; i++) {
        s.pb(string(15, 'O'));
        s.pb(string(15, '/'));
        s.pb(string(15, 'I'));
        s.pb(string(15, '/'));
    }
    s.pb(string(15, 'O'));
    s.pb(string(15, '/'));
    s.pb(string(15, 'I'));
    
    int q = min(13 * 7, (287 - n) / 3);
    int r = (287 - n) - 3*q;

    for (int i = 1; i < 15; i += 2) {
        for (int j = 1; j < 14; j++) {
            if (q > 0) {
                s[i][j] = 'O';
                q--;
            }
        }
    }
    for (int i = 1; i < 15; i += 2) {
        for (int j = 0; j < 15; j += 14) {
            if (r > 0) {
                s[i][j] = 'O';
                r--;
            }
        }
    }


    return s;
}

int main() {
#ifdef _LOCAL
    assert(freopen("C-large.in", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#endif

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
       
        int d, n;
        cin >> d >> n;
        
        vector <string> s = build(n);

        printf("Case #%d:\n", t);
        for (int i = 0; i < 15; i++) {
            printf("%s", s[i].c_str());
            puts("");
        }
    }

#ifdef _LOCAL
    cerr << "\nTIME ELAPSED: " << 1. * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
    return 0;
}
