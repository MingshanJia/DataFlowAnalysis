#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define N 200010

int fac[N], inv[N];
const int mod = 1e9 + 7;

int C(int n, int m)
{
	if (m == 0) return 1;
	if (n < m) return 0;
	return 1LL * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("C.out", "w", stdout);
	
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i < N; ++i)
	{
		fac[i] = 1LL * fac[i - 1] * i % mod;
  		inv[i] = 1LL * inv[mod % i] * (mod - mod / i) % mod; 
	}
	for (int i = 2; i < N; ++i) inv[i] = 1LL * inv[i - 1] * inv[i] % mod;
	
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas)
	{
		int n, m, ans = 0, op = 1, bin = 1;
		scanf("%d %d", &n, &m);
		for (int i = 0; i <= m; ++i)
 	 	{
 	 		int t = 1LL * C(m, i) * fac[2 * n - i] % mod * bin % mod;
 	 		ans += 1LL * op * t;
 	 		if (ans >= mod) ans -= mod;
 	 		if (ans < 0) ans += mod; 
 	 		bin = 1LL * bin * 2 % mod;
 	 		op = -op;

 	 	}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
