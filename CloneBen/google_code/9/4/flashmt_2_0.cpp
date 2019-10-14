#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int test;
  cin >> test;
  for (int iTest = 1; iTest <= test; iTest++)
  {
    int n, k, x;
    vector <int> a;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> x, a.push_back(x);

    while (1)
    {
      int found = 0;
      for (int i = 0; i < int(a.size()) - 2; i++)
        if (a[i] == a[i + 1] && a[i + 1] == a[i + 2])
        {
          a.erase(a.begin() + i, a.begin() + i + 3);
          found = 1;
          break;
        }

      if (!found) break;
    }

    cout << "Case #" << iTest << ": " << a.size() << endl;
  }
}
