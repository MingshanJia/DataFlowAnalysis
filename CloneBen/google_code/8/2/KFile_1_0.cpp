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

struct node
{
	int cost, x, y;

	bool operator<(const node &other) const
	{
		if(cost != other.cost) return cost < other.cost;
		if(x != other.x) return x < other.x;
		return y < other.y;
	}

	bool operator>(const node & other) const
	{
		if(cost != other.cost) return cost > other.cost;
		if(x != other.x) return x > other.x;
		return y > other.y;
	}
};

int T, N, M, Q;
int inter[110][1010], rev_inter[110][1010], dis[110][1010];
int S[110], W[110];
vector<node> adjlist[110][1010];
priority_queue<node, vector<node>, greater<node> > PQ;

int dijkstra(int x1, int y1, int x2, int y2)
{
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= S[i]; j++)
			dis[i][j] = -1;

	PQ.push((node) {0, x1, y1});
	while(!PQ.empty())
	{
		node now = PQ.top(); PQ.pop();
		// cout << now.x << " " << now.y << " " << now.cost << endl;

		if(dis[now.x][now.y] != -1) continue;

		dis[now.x][now.y] = now.cost;
		
		// maju ke S[i]
		int innermetro = W[now.x];
		for(int y = now.y + 1; y <= S[now.x]; y++)
		{
			innermetro += inter[now.x][y - 1];
			if(dis[now.x][y] == -1)
				PQ.push((node) {innermetro + now.cost, now.x, y});
		}

		// mundur ke 1
		innermetro = W[now.x];
		for(int y = now.y - 1; y; y--)
		{
			innermetro += rev_inter[now.x][y + 1];
			if(dis[now.x][y] == -1)
				PQ.push((node) {innermetro + now.cost, now.x, y});
		}

		// transit metro
		for(int i = 0; i < adjlist[now.x][now.y].size(); i++)
		{
			node next = adjlist[now.x][now.y][i];
			if(dis[next.x][next.y] == -1)
				PQ.push((node) {next.cost + now.cost, next.x, next.y});
		}
	}

	return dis[x2][y2];
}

int main()
{
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d", &N);
		memset(inter, -1, sizeof(inter));
		memset(rev_inter, -1, sizeof(rev_inter));

		for(int i = 1; i <= N; i++)
		{
			scanf("%d %d", &S[i], &W[i]);
		
			for(int j = 1; j < S[i]; j++) 
			{
				scanf("%d", &inter[i][j]);
				rev_inter[i][j + 1] = inter[i][j];
			}
		}

		scanf("%d", &M);
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= S[i]; j++) adjlist[i][j].clear();

		int m1, s1, m2, s2, waktu;
		while(M--)
		{
			scanf("%d %d %d %d %d", &m1, &s1, &m2, &s2, &waktu);
			adjlist[m1][s1].pb((node) {waktu, m2, s2});
			adjlist[m2][s2].pb((node) {waktu, m1, s1});
		}

		scanf("%d", &Q);
		printf("Case #%d:\n", t);

		int x1, y1, x2, y2;
		while(Q--)
		{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			printf("%d\n", dijkstra(x1, y1, x2, y2));
		}
	}

	return 0;
}