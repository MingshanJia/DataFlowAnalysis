#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

int main(void)
{
  int t, k;
  cin >> t;

  for (int p = 0; p < t; p++)
  {
    cin >> k;

    vector<int> v;

    for (int i = 0; i < k; i++)
    {
      int a;
      cin >> a;

      v.push_back(a);
    }

    sort(v.begin(), v.end());

    int min = 0;
    int m = 0;

    for (int i = 0; i < k; i++)
    {
      if (i % 2 == 0 && i != 0)
        m += 1;

      min += abs(v[i] - m) * abs(v[i] - m);
    }

    cout << "Case #" << p + 1 << ": " << min << endl;
  }

  return 0;
}