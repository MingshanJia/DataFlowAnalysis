#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

int main(void)
{
  //ifstream ifs("matches.in");
  //ofstream ofs("A.out");

  int t;
  cin >> t;

  for (int p = 0; p < t; p++)
  {
    long long l;
    cin >> l;

    long long num = 0;
    long long lev;

    for (int i = 0; i < l; i++)
    {
      long long n, e;
      cin >> n >> e;

      num -= n * e;
      if (num < 0)
        num = 0;

      num += n;

      lev = e;
    }

    long long ans;
    ans = max(num, lev + 1);

    cout << "Case #" << p + 1 << ": " << ans << endl;
  }

  return 0;
}