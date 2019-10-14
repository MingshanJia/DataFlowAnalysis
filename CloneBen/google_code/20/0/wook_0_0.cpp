#include <stdio.h>
#include <iostream>
using namespace std;

int occupance(int n, int sz) {
	int r = n / sz;
	if(n % sz != 0) r ++;
	return r;
}

long long solve(long long N, long long W, long long J)
{
	int st = 0;
	long long ans = 0;

	for(int month = 1; month <= N; ++ month)
	{
		int d = occupance(W + st, J);
//		printf("%d\n", d);
		ans += d;

		st = (st + W) % J;
	}
	return ans;
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T;
	cin >> T;

	long long N, W, J;
	for(int t=1; t<=T; ++t) {
		cin >> N >> W >> J;
		cout << "Case #" << t << ": " << solve(N, W, J) << endl;
	}
	return 0;
}