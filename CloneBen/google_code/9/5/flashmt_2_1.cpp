#include <bits/stdc++.h>
using namespace std;

int n, k, a[111], f[111][111], g[111];

int dp(int l, int r)
{
  if (r < l) return 1;

  if (f[l][r] >= 0) return f[l][r];

  for (int i = l + 1; i < r; i++)
    if (a[l] + k == a[i] && a[i] + k == a[r] && dp(l + 1, i - 1) && dp(i + 1, r - 1))
      return f[l][r] = 1;

  for (int i = l + 1; i < r; i++)
    if (dp(l, i) && dp(i + 1, r))
      return f[l][r] = 1;

  return f[l][r] = 0;
}

int main()
{
  ios::sync_with_stdio(0);
  int test;
  cin >> test;
  for (int iTest = 1; iTest <= test; iTest++)
  {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    memset(f, -1, sizeof f);
    g[0] = 0;
    for (int i = 1; i <= n; i++)
    {
      g[i] = i;
      for (int j = 1; j <= i; j++)
      {
        g[i] = min(g[i], g[j - 1] + i - j + 1);
        if (dp(j, i)) g[i] = min(g[i], g[j - 1]);
      }
    }

    cout << "Case #" << iTest << ": " << g[n] << endl;
  }
}
