#include <bits/stdc++.h>
using namespace std;

int onRow[200200], rows[444][444], onCol[200200];

pair <double,double> solve(int B, int level, int x)
{
  if (level == 1) return make_pair(250.0, 750.0 * B - 250);

  double res = 0;
  if (onRow[x] <= level - 1)
    res += solve(B, level - 1, x).second / 3;
  if (onCol[x] > 1)
    res += solve(B, level - 1, rows[onRow[x] - 1][onCol[x] - 1]).second / 3;
  if (onCol[x] < onRow[x])
    res += solve(B, level - 1, rows[onRow[x] - 1][onCol[x]]).second / 3;

  if (res <= 250.0) return make_pair(res, 0.0);
  return make_pair(250.0, res - 250.0);
}

int main()
{
  for (int row = 1, total = 0; row <= 400; row++)
    for (int i = 1; i <= row; i++)
    {
      onRow[++total] = row;
      onCol[total] = i;
      rows[row][i] = total;
    }

  int test;
  cin >> test;
  for (int iTest = 1; iTest <= test; iTest++)
  {
    cerr << iTest << endl;
    int B, L, N;
    cin >> B >> L >> N;
    cout << "Case #" << iTest << ": ";
    printf("%.9lf\n", solve(B, L, N).first);
  }
}
