#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

const int N = 1010;

int dist[N][N];
bool inq[N][N];
bool grid[N][N];
int x[12345678], y[12345678];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq=1;qq<=tt;qq++) {
    printf("Case #%d: ", qq);
    int w, h, bb;
    scanf("%d %d %d", &w, &h, &bb);
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) grid[i][j] = true;
    for (int i = 0; i < bb; i++) {
      int xa, ya, xb, yb;
      scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
      for (int x = xa; x <= xb; x++)
        for (int y = ya; y <= yb; y++) grid[y][x] = false;
    }
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        dist[i][j] = 123456789;
        inq[i][j] = false;
      }
    int e = 0;
    for (int i = 0; i < h; i++) {
      e++;
      x[e] = i;
      y[e] = 0;
      dist[i][0] = grid[i][0];
      inq[i][0] = true;
    }
    int b = 1;
    while (b <= e) {
      inq[x[b]][y[b]] = false;
      for (int j = 0; j < 8; j++) {
        int xk = x[b] + dx[j];
        int yk = y[b] + dy[j];
        if (xk >= 0 && yk >= 0 && xk < h && yk < w) {
          int dd = dist[x[b]][y[b]] + grid[xk][yk];
          if (dd < dist[xk][yk]) {
            dist[xk][yk] = dd;
            if (!inq[xk][yk]) {
              e++;
              x[e] = xk;
              y[e] = yk;
              inq[xk][yk] = true;
            }
          }
        }
      }
      b++;
    }
    int ans = 123456789;
    for (int i = 0; i < h; i++)
      if (dist[i][w - 1] < ans) ans = dist[i][w - 1];
    printf("%d\n", ans);
  }
  return 0;
}
