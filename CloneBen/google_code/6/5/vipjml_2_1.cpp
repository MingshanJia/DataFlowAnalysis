#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

long long mod = 1000000007;

long long ppp(long long n, long long t) {
	if (t == 1) return n;
	long long a = ppp(n, t / 2);
	a = (a*a) % mod;
	if (t % 2 == 1) a = (a*n) % mod;
	return a;
}
long long inv(long long n) {
	return ppp(n, mod - 2);
}
void solve(int case_num)
{
	int N, M;
	cin >> N >> M;
	long long t = 1;
	long long q = 1;
	for (long long i = 1; i <= 2 * N; i++) {
		q = (q*i) % mod;
	}
	long long p = 1;
	long long ans = p * q*t;
	for (int i = 1; i <= M; i++) {
		t = -t;
		q = q * inv(2 * N + 1 -  i) % mod;
		p = p * (M + 1 - i) % mod;
		p = p * inv(i) % mod;
		long long a = (p*q*t) % mod;
		a = a * ppp(2, i) % mod;
		ans = (ans + a) % mod;
	}
	if (ans < 0) ans = mod + ans;
	cout << "Case #" << case_num << ": " << ans << endl;
}
int main()
{
#ifdef LOCAL_TEST_VIPJML
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		solve(i);
	}
}
