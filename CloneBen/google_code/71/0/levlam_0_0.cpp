#include <cassert>
#include <cstdio>
#include <map>
#include <set>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int d[10005], l[10005];
char can[10005][10005];
int n;
int ans;

void run (int x, int y) {
  if (y == n + 1) {
    ans = 1;
    return;
  }
  if (can[x][y] || ans) {
    return;
  }
  can[x][y] = 1;
  int ll = min (d[y] - d[x], l[y]) + d[y];
  for (int j = y + 1; j <= n + 1 && d[j] <= ll; j++)
    run(y, j);
}

int main(void) {
  int tn, nt;
  scanf("%d", &nt);
  for (tn = 1; tn <= nt; tn++) {
    printf ("Case #%d: ", tn);
    fprintf (stderr, "Case #%d: \n", tn);

    memset (can, 0, sizeof (can));

    d[0] = 0;
    l[0] = 0;
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d %d", &d[i], &l[i]);
    }
    scanf("%d", &d[n + 1]);

    ans = 0;
    run (0, 1);
    puts (ans ? "YES" : "NO");
  }

  return 0;
}
