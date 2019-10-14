#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[7010];
int t, n;
int main()
{
	scanf("%d", &t);
	for (int CASE = 1; CASE <= t; CASE++)
	{
		scanf("%d", &n);
		ll ans = 0;
		for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				for (int k = j+1; k < n; k++)
				{
					if (a[i] == a[j]*a[k] || a[j] == a[i]*a[k] || a[k] == a[i]*a[j]) ans++;
				}
			}
		}
		printf("Case #%d: ", CASE);
		printf("%lld\n", ans);
	}
}