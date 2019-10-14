#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;

long long c[222][222], f[222][222];

int main()
{
  for (int i = 0; i <= 200; i++)
    for (int j = 0; j <= i; j++)
      c[i][j] = j ? (c[i - 1][j] + c[i - 1][j - 1]) % BASE : 1;

  ios::sync_with_stdio(0);
  int test;
  cin >> test;
  for (int iTest = 1; iTest <= test; iTest++)
  {
    int m, n;
    cin >> m >> n;
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        for (int k = 1; j + k <= n; k++)
        {
          f[i + 1][j + k] += f[i][j] * c[n - j][k];
          f[i + 1][j + k] %= BASE;
        }
    cout << "Case #" << iTest << ": " << f[m][n] << endl;
  }
}
