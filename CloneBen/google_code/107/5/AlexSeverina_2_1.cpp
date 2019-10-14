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
    int l;
    cin >> l;
    cout << "Case #" << p + 1 << ": ";

    string a;
    cin >> a;

    string b;
    cin >> b;

    string c;
    cin >> c;

    int diff12 = -1, diff13 = -1, diff23 = -1;

    int fl12 = 1, fl23 = 1, fl13 = 1, i = 0;
    while (fl12 || fl13 || fl23)
    {
      if (a[i] != b[i] && diff12 == -1)
        diff12 = i, fl12 = 0;
      if (a[i] != c[i] && diff13 == -1)
        diff13 = i, fl13 = 0;
      if (c[i] != b[i] && diff23 == -1)
        diff23 = i, fl23 = 0;

      i++;
    }

    if (a[diff12] != a[diff13])
      cout << "YES ";
    else if (b[diff12] != c[diff13])
      cout << "YES ";
    else
      cout << "NO ";

    if (b[diff12] != b[diff23])
      cout << "YES ";
    else if (a[diff12] != c[diff23])
      cout << "YES ";
    else
      cout << "NO ";

    if (c[diff23] != c[diff13])
      cout << "YES" << endl;
    else if (b[diff23] != a[diff13])
      cout << "YES " << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}