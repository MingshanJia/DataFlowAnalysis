#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define mp make_pair

typedef pair <int, int> pii;
typedef vector <int> vi;
typedef long long int64;
typedef set < int > si;

const int inf = (1 << 30) - 1;
const int64 p = 1000000007;

vector <int64> a, b;
int64 t[2000];

int main ()
{
  freopen ("in", "r", stdin);
  freopen ("out", "w", stdout);
  int nn;
  cin >> nn;
  for (int ii = 1; ii <= nn; ii ++)
    {
      a.clear ();
      b.clear ();
      int n, m;
      int64 x, y, z;
      cin >> n >> m >> x >> y >> z;
      b.resize (m);
      for (int i = 0; i < m; i ++)
        cin >> b[i];
      for (int i = 0; i < n; i ++)
        {
          a.pb (b[i % m]);
          b[i%m] = (x * b[i%m] + y * (i + 1)) % z;
        }
      cerr << endl;
      memset (t,  0, sizeof (t));
      t[0] = 1;
      for (int i = 1; i <= n; i ++)
        {
          t[i] = 1;
          for (int j = 0; j < i-1; j ++)
            if (a[i-1] > a[j])
              t[i] = (t[i] + t[j+1]) % p;
        }
      int64 ans = 0;
      for (int i = 1; i <= n; i ++)
        ans = (ans + t[i]) % p;
      cout << "Case #" << ii << ": " << ans << endl;

    }
}
