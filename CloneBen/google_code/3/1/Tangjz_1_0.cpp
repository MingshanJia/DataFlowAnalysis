#include <bits/stdc++.h>
using namespace std;
const int maxn = 5001, maxm = 12500001;
int t, n, a[maxn], szB, szC[maxn], szD[maxn];
pair<int, int> b[maxm], c[maxn][maxn], d[maxn][maxn];
void process(int &len, pair<int, int> seq[]) {
	int tp = 0;
	sort(seq, seq + len);
	for(int i = 0; i < len; ++i)
		if(!tp || seq[tp - 1].first != seq[i].first)
			seq[tp++] = seq[i];
		else
			seq[tp - 1].second += seq[i].second;
	len = tp;
	for(int i = 1; i < len; ++i)
		seq[i].second += seq[i - 1].second;
}
int calc(int len, pair<int, int> seq[], int x) { // < x
	int idx = lower_bound(seq, seq + len, make_pair(x, 0)) - seq;
	return idx ? seq[idx - 1].second : 0;
}
int main() {
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n);
		szB = 0;
		for(int i = 0; i < n; ++i) {
			szC[i] = szD[i] = 0;
			scanf("%d", a + i);
		}
		sort(a, a + n);
		for(int i = 0; i < n; ++i)
			for(int j = i + 1; j < n; ++j) {
				if(a[i] == a[j])
					continue;
				pair<int, int> tp = make_pair(a[j] - a[i], 1);
				b[szB++] = tp;
				c[i][szC[i]++] = tp;
				d[j][szD[j]++] = tp;
			}
		process(szB, b);
		for(int i = 0; i < n; ++i) {
			process(szC[i], c[i]);
			process(szD[i], d[i]);
		}
		long long ans = 0;
		for(int i = 0; i < n; ++i)
			for(int j = i + 1; j < n && a[i] == a[j]; ++j)
				ans += calc(szB, b, a[i] << 1) - ((calc(szC[i], c[i], a[i] << 1) + calc(szD[i], d[i], a[i] << 1)) << 1);
		for(int i = 0, j; i < n; i = j) {
			for(j = i; j < n && a[i] == a[j]; ++j);
			int len = j - i, val = min(3LL * a[i], (long long)1e9 + 1);
			long long ways = len * (len - 1) * (len - 2LL) / 3;
			ans -= i * ways;
			for(int k = j; k < n && a[k] < val; ++k)
				ans -= ways;
		}
		printf("Case #%d: %I64d\n", Case, ans);
	}
	return 0;
}
