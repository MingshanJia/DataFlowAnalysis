#include <bits/stdc++.h>
using namespace std;

int T, N;
map<int, int> M;
vector<int> V;
vector< pair<int, long long> > meow;

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		V.clear();
		M.clear();
		meow.clear();
		for (int i = 0; i < N; i++) {
			int x;
			scanf("%d", &x);
			V.push_back(x);
			M[x]++;
		}
		sort(V.begin(), V.end());
		for (auto it = M.begin(); it != M.end(); it++) {
			if (it->second >= 2) {
				meow.push_back(make_pair(it->first, (long long)it->second * (it->second - 1) / 2));
			}
		}
		long long cur = 0;
		for (int i = 0; i < meow.size(); i++) {
			cur += meow[i].second;
			meow[i].second = cur;
		}
		long long ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (V[i] == V[j]) continue;
				int pos_l = lower_bound(meow.begin(), meow.end(), make_pair((V[j] - V[i]) / 2 + 1, -1ll)) - meow.begin();
				ans += cur - ((pos_l == 0) ? 0 : meow[pos_l - 1].second);
				if (V[i] * 2 > V[j] - V[i]) {
					ans -= (long long)M[V[i]] * (M[V[i]] - 1) / 2;
					//else ans -= M[V[i]] - 1;
				}
				if (V[j] * 2 > V[j] - V[i]) {
					ans -= (long long)M[V[j]] * (M[V[j]] - 1) / 2;
					//else ans -= M[V[j]] - 1;
				}
				//used.insert(make_pair(V[i], V[j]));
				//printf("%d %d: %lld\n", V[i], V[j], ans);
			}
		}
		for (int i = 0; i < N; i++) {
			for (auto it = M.begin(); it != M.end(); it++) {
				if (it->first == V[i]) continue;
				if ((long long)it->first * 3 <= V[i]) continue;
				ans += (long long)it->second * (long long)(it->second-1) * (long long)(it->second-2) / 6;
			}
		}
		printf("Case #%d: %lld\n", tc, ans);
	}
}
