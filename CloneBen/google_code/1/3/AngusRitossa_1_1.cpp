#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
	ll val, lazy;
	int left, right;
};
Node rangetree[20000000];
int upto;
int newnode()
{
	upto++;
	assert(upto < 20000000);
	rangetree[upto].val = rangetree[upto].lazy = rangetree[upto].left = rangetree[upto].right = 0;
	return upto;
}
void push(int curr, ll sz1, ll sz2)
{
	if (!rangetree[curr].left) rangetree[curr].left = newnode();
	if (!rangetree[curr].right) rangetree[curr].right = newnode();
	if (!rangetree[curr].lazy) return;
	rangetree[rangetree[curr].left].val += rangetree[curr].lazy*sz1;
	rangetree[rangetree[curr].right].val += rangetree[curr].lazy*sz2;
	rangetree[rangetree[curr].left].lazy += rangetree[curr].lazy;
	rangetree[rangetree[curr].right].lazy += rangetree[curr].lazy;
	rangetree[curr].lazy = 0;
}
void update(ll s, ll e, int curr = 1, ll cstart = 0, ll cend = 1e9+10)
{
	assert(curr);
	if (s <= cstart && cend <= e)
	{
		rangetree[curr].val += cend-cstart+1;
		rangetree[curr].lazy++;
		return;
	}
	ll mid = (cstart+cend)/2;
	push(curr, mid-cstart+1, cend-mid);
	if (e <= mid) update(s, e, rangetree[curr].left, cstart, mid);
	else if (s > mid) update(s, e, rangetree[curr].right, mid+1, cend);
	else
	{
		update(s, e, rangetree[curr].left, cstart, mid);
		update(s, e, rangetree[curr].right, mid+1, cend);
	}
	rangetree[curr].val = rangetree[rangetree[curr].left].val + rangetree[rangetree[curr].right].val;
}
ll kthlargest(ll k, int curr = 1, ll cstart = 0, ll cend = 1e9+10)
{
	if (cstart == cend) return cstart;
	ll mid = (cstart+cend)/2;
	push(curr, mid-cstart+1, cend-mid);
	if (rangetree[rangetree[curr].right].val >= k) return kthlargest(k, rangetree[curr].right, mid+1, cend);
	else return kthlargest(k - rangetree[rangetree[curr].right].val, rangetree[curr].left, cstart, mid);
}
int t;
ll m1[400010], m2[400010], m3[400010];
void scanin(int n, ll* m)
{
	ll x, y, a, b, c, mod;
	scanf("%lld%lld%lld%lld%lld%lld", &x, &y, &a, &b, &c, &mod);
	m[0] = x;
	m[1] = y;
	for (int i = 2; i < n; i++)
	{
		m[i] = (a*m[i-1] + b*m[i-2] + c) % mod;
	}
}
int main()
{
	scanf("%d", &t);
	for (int CASE = 1; CASE <= t; CASE++)
	{
		upto = 0;
		newnode();
		int n, q;
		scanf("%d%d", &n, &q);
		scanin(n, m1);
		scanin(n, m2);
		scanin(q, m3);
		for (int i = 0; i < n; i++)
		{
			if (m1[i] > m2[i]) swap(m1[i], m2[i]);
			update(m1[i]+1, m2[i]+1);
		}
		ll ans = 0;
		for (ll i = 0; i < q; i++)
		{
			ll k = m3[i]+1;
			if (k <= rangetree[1].val)
			{
				ll queryans = kthlargest(k);
				//printf("%lld : %lld\n", i, queryans);
				ans += queryans*(i+1ll);
			}
		}
		printf("Case #%d: ", CASE);
		printf("%lld\n", ans);
	}
}