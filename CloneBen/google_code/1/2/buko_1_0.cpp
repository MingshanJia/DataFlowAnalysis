#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;
const int N = 800005;

int zz, q, n, a1, a2, a3, b1, b2, b3, c1, c2, c3, m1, m2, m3, x[N], y[N], z[N], i, l[N], r[N], ind, qq;
ii tab[N], bat[N];
LL res, sum, add, diff, last, newLast, d, akt;

int main() {

scanf("%d", &zz);
for (qq=1;qq<=zz;qq++) {
	scanf("%d %d", &n, &q);
	scanf("%d %d %d %d %d %d", &x[1], &x[2], &a1, &b1, &c1, &m1);
	scanf("%d %d %d %d %d %d", &y[1], &y[2], &a2, &b2, &c2, &m2);
	scanf("%d %d %d %d %d %d", &z[1], &z[2], &a3, &b3, &c3, &m3);
	for (i=3;i<=n;i++) {
		x[i] = (a1 * 1LL * x[i-1] + b1 * 1LL * x[i - 2] + c1) % m1;
		y[i] = (a2 * 1LL * y[i-1] + b2 * 1LL * y[i - 2] + c2) % m2;
	}
	for (i=3;i<=q;i++) {
		z[i] = (a3 * 1LL * z[i-1] + b3 * 1LL * z[i - 2] + c3) % m3;
		//cout << z[i] + 1 << endl;
	}
	for (i=1;i<=n;i++) {
		l[i] = min(x[i], y[i]) + 1;
		r[i] = max(x[i], y[i]) + 1;
		//cout << l[i] << " " << r[i] << endl;
	}
	for (i=1;i<=q;i++) {
		z[i]++;
		bat[i - 1] = ii(z[i], i);
		//cout << bat[i-1].first << endl;
	}
	for (i=1;i<=n;i++) {
		tab[i * 2 - 2] = ii(-l[i] + 1, 1);
		tab[i * 2 - 1] = ii(-r[i], -1);
	}
	sort(bat, bat + q);
	sort(tab, tab + 2 * n);
	ind = 0;
	res = 0;
	last = -tab[0].first;
	akt = 1;
	sum = 0;
	for (i=1;i<2*n;i++) {
		newLast = -tab[i].first;
		diff = last - newLast;
		add = diff * 1LL * akt;
		while (ind < q && bat[ind].first <= sum + add) {
			d = (bat[ind].first - sum - 1) / akt;
			res += (last - d) * 1LL * bat[ind].second;
			//printf("%d %d %lld %lld %lld\n", ind, bat[ind].first, res, d, sum);
			ind++;
		}
		last = newLast;
		sum += add;
		akt -= tab[i].second;
		//printf("%lld %lld %lld\n", last, sum, akt);
	}
	printf("Case #%d: %lld\n", qq, res);
}
return 0;
}