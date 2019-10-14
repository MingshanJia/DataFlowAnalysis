/*
 E-Mail : amr.9102@gmail.com
 */

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>

using namespace std;

#include <ext/hash_set>
#include <ext/hash_map>

using namespace __gnu_cxx;

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v) ((int)v.size())
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
/*
 #define dot(a,b) ((conj(a)*(b)).X)
 #define X real()
 #define Y imag()
 #define length(V) (hypot((V).X,(V).Y))
 #define vect(a,b) ((b)-(a))
 #define cross(a,b) ((conj(a)*(b)).imag())
 #define normalize(v) ((v)/length(v))
 #define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
 #define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)
 */
typedef stringstream ss;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const long double eps = 1e-12;

inline int comp(const long double &a, const long double &b) {
  long double tt = a-b;
  if( tt < 0 )
    tt = -tt;
  if (tt < eps)
    return 0;
  return a > b ? 1 : -1;
}

int di[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dj[] = { 0, 0, 1, -1, 1, -1, -1, 1 };
int diK[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int djK[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

int R, C;

inline bool val(const int &i, const int &j) {
  if (i < 0 || j < 0 || i >= R || j >= C)
    return false;
  return true;
}

int N;
int n;

#define SMALL
//#define LARGE

int main() {
  freopen("a.txt", "rt", stdin);
#ifdef SMALL
  freopen("A-small-attempt1.in", "rt", stdin);
  freopen("A-small1.out", "wt", stdout);
#endif
#ifdef LARGE
  freopen("A-large.in", "rt", stdin);
  freopen("A-large.out", "wt", stdout);
#endif

  cin >> N;
  for (int nn = 1; nn <= N; ++nn) {
    cout << "Case #" << nn << ": ";
    cin >> n;
    vector<pair<int,string> > res;
    string s;
    long double t;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      ss s1;
      s1 << s;
      s1 >> t;
      long double lo = 0, hi = 1;
      int cnt = 0;
      while(hi-lo > eps) {
//        cerr << lo << " " << hi << " : ";
        cnt++;
        long double m1 = (hi-lo)/3+lo, m2 = ((2*(hi-lo))/3.0)+lo;
//        cerr << m1 << " " << m2 << endl;
        if( t >= m1 && t <= m2 )
          break;
        if( t < m1 )
          hi = m1;
        else
          lo = m2;
      }
//      if( hi-lo < 1e-11)
//        cnt = 2000;
//      cerr << cnt << endl;
      res.push_back(make_pair(cnt, s));
    }
    sort(all(res));
    cout << endl;
    for (int i = 0; i < res.size(); ++i) {
      cout << res[i].second << endl;
    }
#ifdef SMALL
    cerr << nn << " of " << N << " is done." << endl;
#endif
#ifdef LARGE
    cerr << nn << " of " << N << " is done." << endl;
#endif
  }
  return 0;
}
