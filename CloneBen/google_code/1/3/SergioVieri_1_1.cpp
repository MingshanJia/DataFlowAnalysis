#include <bits/stdc++.h>
using namespace std;

#define y1 asdf

int n, q;
int x1, x2, a1, b1, c1, m1, y1, y2, a2, b2, c2, m2, z1, z2, a3, b3, c3, m3;
int L[400005], R[400005], K[400005], X[400005], Y[400005], Z[400005];
int ans[400005];

vector<pair<int,int>> evt;
deque<pair<int,int>> SK;

long long calc(long long tot, long long num, long long last, long long cur, long long k) {
	// printf("calc %lld %lld %lld %lld %lld\n", tot, num, last, cur, k);
	return cur + (tot - k + num - 1) / num;
}

int main() {
	int t, no = 0; scanf("%d", &t);
	while (t--) {
		evt.clear();
		SK.clear();
		memset(ans, 0, sizeof(ans));
		scanf("%d%d", &n, &q);
		scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &x1, &x2, &a1, &b1, &c1, &m1, &y1, &y2, &a2, &b2, &c2, &m2, &z1, &z2, &a3, &b3, &c3, &m3);

		X[0] = x1;
		X[1] = x2;
		Y[0] = y1;
		Y[1] = y2;
		Z[0] = z1;
		Z[1] = z2;

		for (int i = 2; i < 400005; ++i) {
			X[i] = ((long long)a1 * X[i - 1] + (long long)b1 * X[i - 2] + c1) % m1;
			Y[i] = ((long long)a2 * Y[i - 1] + (long long)b2 * Y[i - 2] + c2) % m2;
			Z[i] = ((long long)a3 * Z[i - 1] + (long long)b3 * Z[i - 2] + c3) % m3;
		}

		for (int i = 0; i < 400005; ++i) {
			L[i] = min(X[i], Y[i]) + 1;
			R[i] = max(X[i], Y[i]) + 1;
			K[i] = Z[i];
		}


		// for (int i = 0; i < n; ++i) {
		// 	printf("%d ", L[i]);
		// }
		// printf("\n");
		// for (int i = 0; i < n; ++i) {
		// 	printf("%d ", R[i]);
		// }
		// printf("\n");
		// for (int i = 0; i < q; ++i) {
		// 	printf("%d ", K[i]);
		// }
		// printf("\n");

		for (int i = 0; i < q; ++i) SK.emplace_back(K[i], i);

		for (int i = 0; i < n; ++i) {
			evt.emplace_back(R[i], 1);
			evt.emplace_back(L[i] - 1, 0);
		}
		sort(evt.begin(), evt.end());
		reverse(evt.begin(), evt.end());
		sort(SK.begin(), SK.end());

		long long tot = 0;
		int num = 0;
		int last = 1e9 + 7;

		for (int i = 0; i < evt.size(); ++i) {
			auto cur = evt[i];
			tot += (long long)(last - cur.first) * num;
			// printf("now %d, um %d\n", cur.first, num);
			// jawab semua yg <= tot
			while (!SK.empty() && SK[0].first < tot) {
				// hitung query-th number
				ans[SK[0].second] = calc(tot, num, last, cur.first, SK[0].first);
				SK.pop_front();
			}
			if (SK.empty()) break;
			if (cur.second) num++;
			else --num;
			last = cur.first;
		}
		long long ans2 = 0;
		for (int i = 0; i < q; ++i) ans2 += (long long)(i + 1) * ans[i];
		// for (int i = 0; i < q; ++i) printf(">%lld\n", ans[i]);
		printf("Case #%d: %lld\n", ++no, ans2);
	}
	return 0;
}