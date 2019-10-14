#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, pair<int, int> > pllii;
int t;
ll grid[200][200];
ll dis[200][200];
int seen[200][200], upto;
int obstaclenumber[200][200], obstaclecost[30];
int done[1 << 17];
vector<int> obstacles;
ll am, ans, e;
int n, m;
int sr, sc, er, ec;
void dfs(int a, int b, int c)
{
	if (a == 0 || b == 0 || a == n+1 || b == m+1) return;
	if (seen[a][b] == upto) return;
	seen[a][b] = upto;
	if (grid[a][b] == -100000) return;
	if (grid[a][b] < 0 && !(c & (1 << obstaclenumber[a][b])))
	{
		obstacles.push_back(obstaclenumber[a][b]);
		return;
	}

	am += grid[a][b];
	dfs(a-1, b, c);
	dfs(a+1, b, c);
	dfs(a, b-1, c);
	dfs(a, b+1, c);
}
void dothing(int b)
{
	if (done[b]) return;
	done[b] = 1;
	am = e;
	obstacles.clear();
	upto++;
	dfs(sr, sc, b);
	ll saveam = am;
	vector<int> save = obstacles;
	if (seen[er][ec] == upto) ans = max(ans, saveam);
	//printf("%d %lld\n", b, am);
	for (auto a : save)
	{
		if (saveam >= obstaclecost[a])
		{
			dothing(b | (1 << a));
		}
	}

}
int main()
{
	scanf("%d", &t);
	for (int CASE = 1; CASE <= t; CASE++)
	{
		scanf("%d%d%lld%d%d%d%d", &n, &m, &e, &sr, &sc, &er, &ec);
		for (int i = 0; i < n+10; i++)
		{
			fill_n(grid[i], m+10, -100000);
		}
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%lld", &grid[i][j]);
				if (grid[i][j] > -100000 && grid[i][j] < 0)
				{
					obstaclecost[count] = -grid[i][j];
					obstaclenumber[i][j] = count;
					count++;
				}
			}
		}
		ans = -1;
		fill_n(done, (1 << 17), 0);
		dothing(0);
		printf("Case #%d: ", CASE);
		printf("%lld\n", ans);
	}
}