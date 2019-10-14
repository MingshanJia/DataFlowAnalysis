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
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define length(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)

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
const double eps = 1e-9;

inline int comp(const double &a, const double &b) {
  if (fabs(a - b) < eps)
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

char mat[55][55];
bool valid[55][55][55][55];

//#define SMALL
#define LARGE

int main() {
  freopen("a.txt", "rt", stdin);
#ifdef SMALL
  freopen("C-small-attempt0.in", "rt", stdin);
  freopen("C-small.out", "wt", stdout);
#endif
#ifdef LARGE
  freopen("C-large.in", "rt", stdin);
  freopen("C-large.out", "wt", stdout);
#endif

  cin >> N;
  for (int nn = 1; nn <= N; ++nn) {
    cout << "Case #" << nn << ": ";
    cin >> C>> R ;
    memset(valid, 0, sizeof valid);
    int maxArea = 0;
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        cin >> mat[i][j];
        if (mat[i][j] == 'G' || mat[i][j] == 'S') {
          valid[i][j][1][1] = 1;
          maxArea = 1;
        }
      }
    }

    for (int r = 1; r <= R; ++r) {
      for (int c = 1; c <= C; ++c) {
        if (r == 1 && c == 1)
          continue;
        for (int i = r - 1; i < R; ++i) {
          for (int j = c - 1; j < C; ++j) {
            if (c > 1 && valid[i][j][r][c - 1] && valid[i][j - 1][r][c - 1]) {
              valid[i][j][r][c] = 1;
              maxArea = max(maxArea, r * c);
            }
            if (r > 1 && valid[i][j][r - 1][c] && valid[i - 1][j][r - 1][c]) {
              valid[i][j][r][c] = 1;
              maxArea = max(maxArea, r * c);
            }
          }
        }
//        cerr << r << " " << c << endl;
//        for (int i = 0; i < R; ++i) {
//          for (int j = 0; j < C; ++j) {
//            cerr << valid[i][j][r][c];
//          }
//          cerr << endl;
//        }
//        cerr << endl;
      }
    }
    cout << maxArea << endl;
#ifdef SMALL
    cerr << nn << " of " << N << " is done." << endl;
#endif
#ifdef LARGE
    cerr << nn << " of " << N << " is done." << endl;
#endif
  }
  return 0;
}
