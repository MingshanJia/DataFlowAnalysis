#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int> 
#define pdd pair<double,double> 
#define LL long long

#define PI 2*acos(0.0)
#define EPS 1e-9
#define INF 1000000000

using namespace std;

int dr[] = { 0, 1, 1, 1, 0,-1,-1,-1};
int dc[] = { 1, 1, 0,-1,-1,-1, 0, 1};

int T, N;
char grid[350][350];
bool clicked[350][350];

void ff(int r, int c)
{
	for(int i = 0; i < 8; i++)
	{
		int sr = r + dr[i], sc = c + dc[i];
		if(sr >= 0 && sc >= 0 && sr < N && sc < N && grid[sr][sc] != '*' && !clicked[sr][sc])
		{
			clicked[sr][sc] = true;
			if(grid[sr][sc] == '0') ff(sr, sc);
		}
	}
}

int main()
{
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d", &N);
		for(int r = 0; r < N; r++) scanf("%s", grid[r]);

		for(int r = 0; r < N; r++)
			for(int c = 0; c < N; c++) if(grid[r][c] == '.')
			{
				int near = 0;
				for(int i = 0; i < 8; i++)
				{
					int sr = r + dr[i], sc = c + dc[i];
					if(sr >= 0 && sc >= 0 && sr < N && sc < N && grid[sr][sc] == '*') near++;
				}

				grid[r][c] = near + '0';
			}

		memset(clicked, false, sizeof(clicked));

		int cluster = 0;
		for(int r = 0; r < N; r++)
			for(int c = 0; c < N; c++) 
				if(grid[r][c] == '0' && !clicked[r][c]) 
				{
					clicked[r][c] = true;
					cluster++;
					ff(r, c);
				}

		for(int r = 0; r < N; r++)
			for(int c = 0; c < N; c++)
				if(grid[r][c] != '*' && !clicked[r][c]) cluster++;

		printf("Case #%d: %d\n", t, cluster);
	}

	return 0;
}

