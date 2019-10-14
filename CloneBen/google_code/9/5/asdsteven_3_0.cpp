#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

unsigned long long dp[102][102];
unsigned long long mx = 1000000000000000001ll;
char s[201];

const char *solve() {
	int n;
	unsigned long long k;
	cin >> n >> k;
	int i = 0, j = n;
	unsigned long long l = 0;
	int si = 0;
	if (dp[i][j] < k)
		return "Doesn't Exist!";
	while (j) {
		if (dp[i + 1][j - 1] >= k - l) {
			s[si++] = '(';
			i++, j--;
		}
		else {
			l += dp[i + 1][j - 1];
			s[si++] = ')';
			i--;
		}
	}
	while (si < 2 * n)
		s[si++] = ')';
	s[si] = 0;
	return s;
}

int main() {
	dp[0][0] = 1;
	for (int i = 1; i <= 100; i++)
	for (int j = 0; j < i; j++)
		dp[0][i] = min(mx, dp[0][i] + dp[0][j] * dp[0][i - j - 1]),
		dp[i][0] = 1;
	for (int j = 1; j <= 100; j++)
	for (int i = 1; i + j <= 100; i++)
	dp[i][j] = min(mx, dp[i + 1][j - 1] + dp[i - 1][j]);
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
		printf("Case #%d: %s\n", i, solve());
}