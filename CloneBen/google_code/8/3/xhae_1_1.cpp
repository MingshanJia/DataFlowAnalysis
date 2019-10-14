#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

vector<int> dist[2][100];
vector<vector<pair<int, pair<int, int>>>> edge[100];
int _wait[100];
int n, m;
int si[100];

struct Loc
{
	int x, y, type;
	bool operator < (const Loc &a) const
	{
		if(x != a.x) return x < a.x;
		if(y != a.y) return y < a.y;
		return type < a.type;
	}
};

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++)
	{
		printf("Case #%d:\n", kase);
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d", si + i, _wait + i);
			edge[i].clear();
			edge[i].resize(si[i]);
			for(int j = 0; j < si[i] - 1; j++)
			{
				int len;
				scanf("%d", &len);
				edge[i][j].push_back(make_pair(len, make_pair(i, j + 1)));
				edge[i][j + 1].push_back(make_pair(len, make_pair(i, j)));
			}
		}

		scanf("%d", &m);
		for(int i = 0; i < m; i++)
		{
			int x1, y1, x2, y2, t;
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &t);
			x1--, y1--, x2--, y2--;
			edge[x1][y1].push_back(make_pair(t, make_pair(x2, y2)));
			edge[x2][y2].push_back(make_pair(t, make_pair(x1, y1)));
		}

		int qn;
		scanf("%d", &qn);
		for(int i = 0; i < qn; i++)
		{
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			x1--, y1--, x2--, y2--;
			priority_queue<pair<int, Loc>, vector<pair<int, Loc>>, greater<pair<int, Loc>>> q;
			q.push(make_pair(0, Loc{x1, y1, 0}));
			for(int i = 0; i < n; i++)
			{
				dist[0][i] = vector<int>(si[i], -1);
				dist[1][i] = vector<int>(si[i], -1);
			}
			dist[0][x1][y1] = 0;
			while(!q.empty())
			{
				int cDist = q.top().first;
				Loc curLoc = q.top().second;
				int x = curLoc.x, y = curLoc.y, type = curLoc.type;
				q.pop();
				if(dist[type][x][y] != cDist) continue;

				if(type == 0)
				{
					int nDist = cDist + _wait[x];
					if(dist[1][x][y] == -1 or dist[1][x][y] > nDist)
					{
						dist[1][x][y] = nDist;
						q.push(make_pair(nDist, Loc{x, y, 1}));
					}
					for(const auto &e: edge[x][y])
					{
						int nx = e.second.first, ny = e.second.second;
						int nDist = cDist + e.first;
						int nType = 1;
						if(x != nx) nType = 0;
						if(x == nx) continue;
						if(dist[nType][nx][ny] == -1 or dist[nType][nx][ny] > nDist)
						{
							dist[nType][nx][ny] = nDist;
							q.push(make_pair(nDist, Loc{nx, ny, nType}));
						}
					}
				}
				else
				{
					for(const auto &e: edge[x][y])
					{
						int nx = e.second.first, ny = e.second.second;
						int nDist = cDist + e.first;
						int nType = 1;
						if(x != nx) nType = 0;
						if(dist[nType][nx][ny] == -1 or dist[nType][nx][ny] > nDist)
						{
							dist[nType][nx][ny] = nDist;
							q.push(make_pair(nDist, Loc{nx, ny, nType}));
						}
					}
				}
			}

			int ans = -1;
			if(dist[0][x2][y2] != -1 and (ans == -1 or dist[0][x2][y2] < ans)) ans = dist[0][x2][y2];
			if(dist[1][x2][y2] != -1 and (ans == -1 or dist[1][x2][y2] < ans)) ans = dist[1][x2][y2];
			printf("%d\n", ans);
		}
	}

	return 0;
}
