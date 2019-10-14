#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forit(i, v) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair
template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = (int)1E9 + 7;
const ld EPS = 1E-9;
const ld PI = 3.1415926535897932384626433832795;

struct rec{
    int l, r, s, d;
    rec(){}
};

bool operator < (const rec& a, const rec& b){
    return a.d < b.d;
}

int main() {
    #ifdef myproject
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    #endif

    int tests;
    cin >> tests;
    forn(testsit, tests){
        printf("Case #%d: ", testsit+1);

        int n;
        cin >> n;

        vector<rec> q;
        forn(i, n){
            int di, ni, wi, ei, si, ddi, dpi, dsi;
            cin >> di >> ni >> wi >> ei >> si >> ddi >> dpi >> dsi;

//            cerr << di << " " << ni << " " << wi << " " << ei << " " << si << " " << ddi << " " << dpi << " " << dsi << endl;

            forn(step, ni){
                rec cur;
                cur.l = wi, cur.r = ei, cur.s = si, cur.d = di;
                q.pb(cur);
                di += ddi, wi += dpi, ei += dpi, si += dsi;
            }
        }

        sort(all(q));

        int ans = 0;

        map<int, int> w;
        forn(i, sz(q)){

            int j = i;
            while(j < sz(q) && q[i].d == q[j].d){
                int minv = INF;

                fore(k, q[j].l, q[j].r){
                    minv = min(w[k], minv);
                }

                if(minv < q[j].s)
                    ans++;    

                j++;
            }

            fore(r, i, j){
                fore(k, q[r].l, q[r].r)
                    w[k] = max(w[k], q[r].s);
            }

            i = j - 1;
        }

        cout << ans;

        puts("");
        //cerr << "testsit=" << testsit+1 << " " << clock() << endl;
    }
    return 0;
}


