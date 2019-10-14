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

const int inf = (1 << 30) - 1;

typedef pair <int, int> pii;
typedef vector <int> vi;
typedef long long int64;
typedef set < int > si;

string s;
vector <int64> a;
int ans;

void check (int64 s)
{
  if ((s % 2 == 0) || (s % 3 == 0) || (s % 5 == 0) || (s % 7 == 0))
    ans ++;
}

void go (int64 s, int64 op, int v)
{
  if (v == a.size ())
    check (s);
   else
    {
      int64 s1 = 0;
      for (int i = v; i < a.size(); i ++)
        {
          s1 = s1 * 10 + a[i];
          go (s + s1 * op, 1, i+1);
          go (s + s1 * op, -1, i+1);
        }
    }
}

int main ()
{
  freopen ("in", "r", stdin);
  freopen ("out", "w", stdout);
  int nn;
  cin >> nn;
  for (int ii = 1; ii <= nn; ii ++)
    {
      cin >> s;
      ans = 0;
      a.clear ();
      for (int i = 0; i < s.length(); i ++)
        a.pb (s[i] - '0');
      go (0, 1, 0);
      printf ("Case #%d: %d\n", ii, ans / 2);
    }
}
