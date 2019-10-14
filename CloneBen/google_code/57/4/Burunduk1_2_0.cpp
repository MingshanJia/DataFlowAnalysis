/**         
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2014.05.31
 */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define zero(a) memset(a, 0, sizeof(a))

const int W = 100;
const int H = 500;
const int VN = 2 * W * H + 2;
const int EN = (5 * W * H + 2 * W) * 2 + 2;

int mark[H][W];

int S, T;
int e, n, m, he[VN], ne[EN], to[EN], c[EN];
int cc, u[VN];

void init()
{
  memset(he, -1, sizeof(he));
  e = 0;
}

void addE( int a, int b )
{
  //fprintf(stderr, "%d --> %d\n", a, b);
  ne[e] = he[a], to[e] = b, c[e] = 1, he[a] = e++;
  ne[e] = he[b], to[e] = a, c[e] = 0, he[b] = e++;
}

int dfs( int v )
{
  int x;
  u[v] = cc;
  for (int i = he[v]; i != -1; i = ne[i])
    if (c[i] > 0 && ((x = to[i]) == T || (u[x] != cc && dfs(x))))
    {
      c[i]--, c[i ^ 1]++;
      return 1;       
    }
  return 0;
}

int MaxFlow()
{
  int res = 0;
  zero(u), cc = 1;
  while (dfs(S))
    res++, cc++;
  return res;
}

void solve()
{
  int w, h, b;
  scanf("%d%d%d", &w, &h, &b);
  zero(mark);
  while (b--)
  {
    int x0, x1, y0, y1;
    scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
    for (int y = y0; y <= y1; y++)
      for (int x = x0; x <= x1; x++)
        mark[y][x] = 1;
  }
  S = 2 * h * w, T = S + 1;
  init();
  forn(y, h)
    forn(x, w)
      if (!mark[y][x])
      {
        const static int dx[] = {1, -1, 0, 0};
        const static int dy[] = {0, 0, 1, -1};

        int v = 2 * (y * w + x);
        if (y == 0)
          addE(S, v);
        if (y == h - 1)
          addE(v + 1, T);
        addE(v, v + 1);
        forn(k, 4)
        {
          int x1 = x + dx[k];
          int y1 = y + dy[k];
          int v1 = 2 * (y1 * w + x1);
          if (0 <= x1 && x1 < w && 0 <= y1 && y1 < h && !mark[y1][x1])
            addE(v + 1, v1);
        }
      }
  fprintf(stderr, "search!\n");
  printf("%d\n", MaxFlow());
}

int main()
{
  int tn;
  scanf("%d", &tn);
  forn(t, tn)
  {
    printf("Case #%d: ", t + 1);
    solve();
  }
  return 0;
}
