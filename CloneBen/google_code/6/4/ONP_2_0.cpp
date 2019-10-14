#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <ctime>

using namespace std;
long long mod = 1000000007;
int n, m;
long long jie[1100000], antjie[1100000];
long long quick(long long a, long long b)
{
	long long ret = 1;
	for (; b; b >>= 1LL) {
		if (b & 1)
			ret = (ret * a) % mod;
		a = (a * a) % mod;
	}
	return ret; 
}
long long C(int a, int b)
{	
//	cerr << a << ' ' << b << ' ' << jie[a] << ' ' << antjie[b]<< ' ' << antjie[a - b] << ' '<< jie[a] * antjie[b] * antjie[a - b] % mod << endl;
	return jie[a] * antjie[b] % mod * antjie[a - b] % mod;
}
int main()
{
	jie[0] = 1;
	for (int i = 1; i <= 666666; i++)
		jie[i] = (jie[i - 1] * i) % mod;
	for (int i = 0; i <= 666666; i++)
		antjie[i] = quick(jie[i], mod - 2);
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int ca = 0;
	int T;
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &m);
		long long sum = 0;
		for (int err = 0; err <= m; err++) {
			// 2n - err
			int sign = 1;
			if (err % 2)
				sign = -1;
			sum += sign * (C(m, err) * quick(2, err) % mod * jie[2 * n - err] % mod);
			sum = (sum + mod) % mod;
			//cout << sum << endl;
		}
		printf("Case #%d: ", ++ca);
		cout << sum << endl;
	}
}

