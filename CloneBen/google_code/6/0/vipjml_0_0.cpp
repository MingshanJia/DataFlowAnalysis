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

int N, P;
void solve(int case_num)
{
	cin >> N >> P;
	unordered_set<string> ss;
	vector<string> tt(P);
	long long ans = (1ll << N);
	for (int i = 0; i < P; i++) {
		cin >> tt[i];
	}
	sort(tt.begin(), tt.end());
	for (int i = 0; i < P; i++) {
		string t = tt[i];
		bool flag = false;
		for (int j = 1; j <= t.size(); j++) {
			if (ss.find(t.substr(0, j) )!= ss.end()) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			ans -= (1ll << (N - t.size()));
		}
		ss.insert(t);
	}
	cout << "Case #" << case_num << ": " << ans << endl;
}
int main()
{
#ifdef LOCAL_TEST_VIPJML
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		solve(i);
	}
}
