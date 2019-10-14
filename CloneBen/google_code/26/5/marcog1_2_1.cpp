#include <algorithm>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int i=(a); i<(b); ++(i))
#define REP(i, n) FOR(i, 0, (n))
#define FOREACH(i,x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define PB push_back
#define MP make_pair
#define INF (INT_MAX/2)
#define LINF (LONG_LONG_MAX/2)
#define EPS (1e-10)

void solve(int cse) {
  int R, C;
  cin >> C >> R;
  bool grid[R+2][C+2];
  REP(i, R+2)
    fill(grid[i], grid[i]+C+2, false);
  REP(i, R) {
    string row;
    cin >> row;
    REP(j, C)
      grid[i+1][j+1] = row[j] != 'G' && row[j] != 'S';
  }

  int h[R+1][C+1], l[R+1][C+1], r[R+1][C+1];
  REP(i, R+1) {
    fill(h[i], h[i]+C+1, 0);
    fill(l[i], l[i]+C+1, 0);
    fill(r[i], r[i]+C+1, 0);
  }

  int ans = 0;
  FOR(i, 1, R+1) {
    FOR(j, 1, C+1)
      h[i][j] = grid[i][j] ? 0 : h[i-1][j]+1;
    int p = 0;
    FOR(j, 1, C+1) {
      if (grid[i][j]) p = j;
      l[i][j] = j - p;
      if (!grid[i][j] && h[i-1][j])
        l[i][j] = min(l[i][j], l[i-1][j]);
    }
    p = C+1;
    for (int j = C; j >= 1; j--) {
      if (grid[i][j]) p = j;
      r[i][j] = p - j;
      if (!grid[i][j] && h[i-1][j])
        r[i][j] = min(r[i][j], r[i-1][j]);
      ans = max(ans, h[i][j] * (l[i][j] + r[i][j] - 1));
    }
  }

  cout << "Case #" << cse << ": " << ans << endl;
}

int main() {
  int N;
  cin >> N;
  REP(i, N)
    solve(i+1);
}
