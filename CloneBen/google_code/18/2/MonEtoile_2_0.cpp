#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<functional>
#include<algorithm>

using namespace std;

#define _INFILE		"C-small-attempt1.in"
#define _OUTFILE	"c-small1.out"

typedef long long ll;

int n, m, k;
char a[60][30][30];
int mask[60][30][30];
set<int> adj[20001];
bool visited[20001];
int cost[20001][2];

void ff(int f, int r, int c, int num)
{
	if (r<0 || r>=n || c<0 || c>=m) return;
	if (a[f][r][c] != '.' || mask[f][r][c] != -1) return;
	mask[f][r][c] = num;
	ff(f, r-1, c, num);
	ff(f, r+1, c, num);
	ff(f, r, c-1, num);
	ff(f, r, c+1, num);
}

int solve()
{
	scanf("%d%d%d",&n,&m,&k);
	int rooms = 0;
	for(int i=0; i<20001; i++) {
		adj[i].clear();
		visited[i] = false;
		cost[i][0] = 0;
		cost[i][1] = 0;
	}

	for(int i=0; i<k; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%s",a[i][j]);
			for(int kk=0; kk<m; kk++) mask[i][j][kk] = -1;
		}
		for(int j=0; j<n; j++)
			for(int kk=0; kk<m; kk++)
			{
				if (a[i][j][kk] == '.' && mask[i][j][kk] == -1)
					ff(i, j, kk, rooms++);
			}
		if (i==0) continue;
		for(int j=0; j<n; j++)
			for(int kk=0; kk<m; kk++)
			{
				if (a[i][j][kk] == '.' && a[i-1][j][kk] == '.')
				{
					int u = mask[i-1][j][kk];
					int v = mask[i][j][kk];
					adj[u].insert(v);
					adj[v].insert(u);
				}
			}
	}

	int result = 0;
	while(true)
	{
		set<int> s;
		for(int i=0; i<rooms; i++)
		{
			if (!visited[i] && adj[i].size() <= 1) {
				s.insert(i);
			}
		}

		while(!s.empty())
		{
			int u = *s.begin();
			if (adj[u].begin() != adj[u].end())
			{
				int v = *(adj[u].begin());
				adj[v].erase(u);
				adj[u].erase(v);
			
				for(auto it=adj[v].begin(); it != adj[v].end(); it++)
				{
					int vv = *it;
					adj[vv].erase(v);
					if (adj[vv].size() <= 1) s.insert(vv);
				}
				adj[v].clear();
				s.erase(v);
				visited[v] = true;
			}
			s.erase(u);
			visited[u] = true;
			result++;
		}

		// erase max degree
		int v = -1;
		int best = 0;
		for(int i=0; i<rooms; i++)
		{
			if (adj[i].size() > best)
			{
				best = adj[i].size();
				v = i;
				break;
			}
		}
		if (v == -1) break;

		for(auto it=adj[v].begin(); it != adj[v].end(); it++)
		{
			int vv = *it;
			adj[vv].erase(v);
		}
		visited[v] = true;
		adj[v].clear();
	}

	return result;
}

int main(void)
{
	int T;
	freopen(_INFILE, "r", stdin);
	freopen(_OUTFILE, "w", stdout);

	scanf("%d",&T);

	for(int i=0; i<T; i++)
	{
		printf("Case #%d: %d\n", i+1, solve());
	}
	return 0;
}

