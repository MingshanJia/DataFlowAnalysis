#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[7010];
ll am[200030];
ll query(ll a)
{
	if (a < 0 || a > 200020) return 0;
	return am[a];
}
int t, n;
int main()
{
	scanf("%d", &t);
	for (int CASE = 1; CASE <= t; CASE++)
	{
		scanf("%d", &n);
		fill_n(am, 200030, 0);
		ll ans = 0;
		for (int i = 0; i < n; i++) scanf("%lld", &a[i]), am[a[i]] = 0, assert(a[i] <= 200020);
		for (ll i = 0; i < n; i++)
		{
			for (ll j = i+1; j < n; j++)
			{
				if (a[i] + a[j] == 0)
				{
					ans += i;
					continue;
				}
				ll itj = a[i]*a[j];
				ans += query(itj);
				ll idj = 0;
				if (a[j]) idj = a[i]/a[j];
				if (idj*a[j] == a[i] && idj != itj) ans += query(idj);
				else idj = -1;
				ll jdi = 0;
				if (a[i]) jdi = a[j]/a[i];
				if (jdi*a[i] == a[j] && jdi != itj && jdi != idj) ans += query(jdi);
			}
			am[a[i]]++;
		}
		printf("Case #%d: ", CASE);
		printf("%lld\n", ans);
	}
}