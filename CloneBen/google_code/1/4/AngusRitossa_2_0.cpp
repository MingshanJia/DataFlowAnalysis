#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, pair<int, int> > pllii;
int t;
ll grid[200][200];
ll dis[200][200];
priority_queue<pllii, vector<pllii>, greater<pllii> > pq;
void trything(int a, int b, ll d)
{
	if (grid[a][b] == -100000) return;
	ll newd = d + abs(grid[a][b]);
	if (newd < dis[a][b])
	{
		dis[a][b] = newd;
		pq.push({newd, { a, b }});
	}
}
int main()
{
	scanf("%d", &t);
	for (int CASE = 1; CASE <= t; CASE++)
	{
		while (!pq.empty()) pq.pop();
		int n, m;
		ll e;
		int sr, sc, er, ec;
		scanf("%d%d%lld%d%d%d%d", &n, &m, &e, &sr, &sc, &er, &ec);
		for (int i = 0; i < n+10; i++)
		{
			fill_n(grid[i], m+10, -100000);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%lld", &grid[i][j]);
				grid[i][j] = min(grid[i][j], 0ll);
				dis[i][j] = 1e9;
			}
		}

		
		dis[sr][sc] = 0;
		pq.push({ 0, { sr, sc }});
		while (!pq.empty())
		{
			int i = pq.top().second.first;
			int j = pq.top().second.second;
			ll d = pq.top().first;
			pq.pop();
			if (d > e) continue;
			if (dis[i][j] != d) continue;
			trything(i-1, j, d);
			trything(i+1, j, d);
			trything(i, j-1, d);
			trything(i, j+1, d);
		}
		ll ans = e - dis[er][ec];
		ans = max(ans, -1ll);
		printf("Case #%d: ", CASE);
		printf("%lld\n", ans);
	}
}