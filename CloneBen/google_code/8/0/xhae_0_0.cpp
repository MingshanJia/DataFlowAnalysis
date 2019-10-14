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

string field[300];
int vfield[300][300];
int n;
bool isVisited[300][300];

int cnt(int y, int x)
{
	int ret = 0;
	for(int dy = -1; dy <= 1; dy++)
		for(int dx = -1; dx <= 1; dx++)
		{
			if(dy == 0 and dx == 0) continue;
			int ny = y + dy, nx = x + dx;
			if(ny >= 0 and ny < n and nx >= 0 and nx < n and field[ny][nx] == '*') ret++;
		}

	return ret;
}

int main(void)
{
	int T;
	cin >> T;
	for(int kase = 1; kase <= T; kase++)
	{
		cin >> n;
		for(int i = 0; i < n; i++) cin >> field[i];
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) vfield[i][j] = cnt(i, j);
		memset(isVisited, 0, sizeof(isVisited));
		int ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(field[i][j] == '.' and vfield[i][j] == 0 and !isVisited[i][j])
				{
					ans++;
					isVisited[i][j] = true;
					queue<pair<int, int>> q;
					q.push(make_pair(i, j));
					while(!q.empty())
					{
						int y = q.front().first, x = q.front().second;
						q.pop();
						for(int dy = -1; dy <= 1; dy++)
							for(int dx = -1; dx <= 1; dx++)
							{
								int ny = y + dy, nx = x + dx;
								if(ny >= 0 && ny < n && nx >= 0 && nx < n && !isVisited[ny][nx] && field[ny][nx] == '.')
								{
									isVisited[ny][nx] = true;
									if(vfield[ny][nx] == 0)
										q.push(make_pair(ny, nx));
								}
							}
					}
				}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(!isVisited[i][j] and field[i][j] == '.')
					ans++;
		printf("Case #%d: %d\n", kase, ans);
	}

	return 0;
}
