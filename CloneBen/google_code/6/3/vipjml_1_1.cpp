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


void solve(int case_num)
{
	int N;
	string S;
	cin >> N >> S;
	int t = (N + 1) / 2;
	vector<int> sum(N + 1, 0);
	for (int i = 0; i < N; i++) sum[i + 1] = (S[i] - '0') + sum[i];
	int ans = 0;
	for (int i = t; i<=N; i++) {
		ans = max(ans, sum[i] - sum[i - t]);
	}
	cout << "Case #" << case_num << ": " << ans << endl;
}
int main()
{
#ifdef LOCAL_TEST_VIPJML
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		solve(i);
	}
}
