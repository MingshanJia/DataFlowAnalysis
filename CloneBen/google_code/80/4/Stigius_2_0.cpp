#include <stdio.h>
#include <stdarg.h>
#include <cstring>
#include <algorithm>
#include <vector>
#define clr(a) memset(a, 0, sizeof(a))


typedef std::pair<int, int> pii;


#define DEBUG 0

void dbg(const char * fmt, ...)
{
#if DEBUG
	va_list args;
	va_start(args, fmt);
	vfprintf(stdout, fmt, args);
	va_end(args);
	fflush(stdout);
#endif
}

pii v[2000];
int color[2000];
bool use[2000];
int n,m;
std::vector<int> rooms[2000];
int cnt;
std::vector<int> adjlist[2000];
std::vector<bool> mark[2000];

void sort(int x)
{
	for(int i = 0; i < (int) adjlist[x].size(); i++)
		(adjlist[x][i] += (n-x)) %= n;
	std::sort(adjlist[x].begin(), adjlist[x].end());
	for(int i = 0; i < (int) adjlist[x].size(); i++)
		(adjlist[x][i] += (n+x)) %= n;
	dbg("%d: ", x);
	for(int i = 0; i < (int) adjlist[x].size(); i++)
		dbg("%d ", adjlist[x][i]);
	dbg("\n");
}

int next(int v, int p)
{
	for(int i = 0; i < (int) adjlist[v].size(); i++)
	{
		if (adjlist[v][i] == p)
			return i - 1;
	}
	throw 42;
}

void build_room(int start, int nxt)
{
	std::vector<int> ans;
	int cur = start;
	while(1)
	{
		ans.push_back(cur);
		mark[cur][nxt] = true;
		int temp = adjlist[cur][nxt];
		dbg("build: %d %d -> %d\n", cur, nxt, temp);
		nxt = next(temp, cur);
		cur = temp;
		if (cur == start)
			break;
	}
	rooms[cnt++] = ans;
}

void solve(int test_case)
{
	printf("Case #%d: ", test_case);
	cnt = 0;
	dbg("\n");
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &v[i].first);
		v[i].first --;
	}
	for(int i = 0; i < m; i++)
	{	
		scanf("%d", &v[i].second);
		v[i].second --;
	}
	std::sort(v, v + m);
	for(int i = 0; i < n; i++)
	{
		adjlist[i].clear();
		adjlist[i].push_back((i+1) % n);
		adjlist[i].push_back((i+n-1) % n);
	}
	for(int i = 0; i < m; i++)
	{
		adjlist[v[i].first].push_back(v[i].second);
		adjlist[v[i].second].push_back(v[i].first);
	}
	for(int i = 0; i < n; i++)
	{
		sort(i);
		mark[i] = std::vector<bool>(adjlist[i].size(), false);
		mark[i].back() = 1;
	}
	dbg("%d\n", n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < (int) adjlist[i].size(); j++)
		{
			if (!mark[i][j])
			{
				build_room(i, j);
			}
		}
	}
	for(int i = 0; i < cnt; i++)
	{
		dbg("room: ");
		for(int j = 0; j < (int) rooms[i].size(); j++)
			dbg("%d ", rooms[i][j]);
		dbg("\n");
	}
	int ans = n;
	for(int i = 0; i < cnt; i++)
		ans = std::min<int> (ans, rooms[i].size());
	printf("%d\n", ans);
	clr(color);
	color[0] = 1;
	color[1] = 2;
	int moved = cnt;
	while(moved)
	{
		for(int i = 0; i < cnt; i++)
		{
			int colored_count = 0;
			int l = rooms[i].size();
			for(int j = 0; j < l; j++)
				if (color[rooms[i][j]])
					colored_count ++;
			if (colored_count > 2)
				throw 42;
			if (colored_count < 2)
				continue;
			dbg("Process room %d\n", i);
			moved --;
			clr(use);
			int pos = 1;
			for(int j = 0; j < l; j++)
			{
				use[color[rooms[i][j]]] = 1;
			}
			bool f = false;
			for(int j = 0; j < l; j++)
			{

				if (color[rooms[i][j]] == 0)
				{
					if (!f)
						while(pos <= ans && use[pos])
							pos++;
					if (pos > ans)
						f = true;
					if (f)
					{
						pos = 1;
						while(pos == color[rooms[i][(j+l-1)%l]] || pos == color[rooms[i][(j+1)%l]])
							pos++;
						if (pos > ans)
							throw 42;
					}
					use[pos] = 1;
					color[rooms[i][j]] = pos;
				}
			}
			for(int j = 1; j <= ans; j++)
				if (!use[j])
				{
					throw 42;
				}
			rooms[i].clear();
		}
	}
	for(int i = 0; i < n; i++)
		printf("%d ", color[i]);
	printf("\n");

}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		solve(i);

	return 0;
}
