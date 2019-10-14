#include <stdio.h>
#include <iostream>
using namespace std;

long long occupance(long long n, int sz) {
	int r = n / sz;
	if(n % sz != 0) r ++;
	return r;
}

long long solve(long long N, long long W, long long J)
{
	int st = 0;
	long long ans = 0;

	long long repeats = N / J;

	for(int month = 1; month <= J; ++ month)
	{
		long long d = occupance(W + st, J);
		ans += d;

		st = (st + W) % J;
	}

	ans *= repeats;
	for(long long month = repeats * J + 1; month <= N; ++ month)
	{
		long long d = occupance(W + st, J);
		ans += d;

		st = (st + W) % J;
	}
	return ans;
}

int main()
{
	freopen("A.large.in", "r", stdin);
	freopen("A.large.out", "w", stdout);

	int T;
	cin >> T;

	long long N, W, J;
	for(int t=1; t<=T; ++t) {
		cin >> N >> W >> J;
		cout << "Case #" << t << ": " << solve(N, W, J) << endl;
	}
	return 0;
}