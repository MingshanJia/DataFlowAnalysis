#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxm = 500000 + 10;
const int maxN = 500000 + 10;
const int size = 1000000007;
const int infinite = 1 << 30;

long long a[maxm];
long long F[maxN];
int b[maxN];
int N, m, data, len;
long long X, Y, Z, ans;

void getinf()
{
  cin >> N >> m >> X >> Y >> Z;
  for (int i = 0; i < m; i++) cin >> a[i];
}

void gen()
{
  for (int i = 0; i <= N - 1; i++)
    {
      b[i + 1] = a[i % m];
      //      cout << b[i + 1] << endl;
      a[i % m] = (X * a[i % m] + Y * (i + 1)) % Z;
    }
}

void solve()
{
  memset(F, 0, sizeof(F));
  F[0] = 1;
  b[0] = -infinite;
  ans = 0;
  for (int i = 1; i <= N; i++) 
    {
      F[i] = 1;
      for (int j = 1; j < i; j++)
	  if (b[j] < b[i]) 
	    F[i] = (F[i] + F[j]) % size;
      ans = (ans + F[i]) % size;
    }
}

int main()
{
  scanf("%d", &data);
  for (int tot = 1; tot <= data; tot++)
    {
      getinf();
      gen();
      solve();
      cout << "Case #" << tot << ": " << ans << endl;
    }
}
