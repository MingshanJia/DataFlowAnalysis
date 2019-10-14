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

int possible[10];
long long tar;
vector<pair<long long, int>> cand;

void backtr(long long v, int cost)
{
	if(v > tar) return;
	if(tar % v == 0) cand.push_back(make_pair(v, cost));
	for(int i = 0; i < 10; i++)
		if(possible[i] == 1) backtr(v * 10 + i, cost + 1);
}

int dist[1000001];

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++)
	{
		for(int i = 0; i < 10; i++) scanf("%d", possible + i);
		scanf("%lld", &tar);

		cand.clear();
		for(int i = 1; i < 10; i++) if(possible[i] == 1) backtr(i, 1);

		memset(dist, -1, sizeof(dist));
		priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> q;
		int ans = -1;
		for(auto &e: cand) 
		{
			q.push(make_pair(e.second + 1, e.first));
			dist[e.first] = e.second + 1;
		}
		while(!q.empty())
		{
			int cDist = q.top().first;
			long long cur = q.top().second;
			q.pop();
			if(dist[cur] != cDist) continue;

			for(const auto &e: cand)
			{
				long long next = cur * e.first;
				if(tar % next != 0) continue;
				if(dist[next] == -1 or dist[next] > cDist + e.second + 1)
				{
					dist[next] = cDist + e.second + 1;
					q.push(make_pair(cDist + e.second + 1, next));
				}
			}
		}
		if(dist[tar] != -1 and (ans == -1 or dist[tar] < ans)) ans = dist[tar];
		if(ans == -1) printf("Case #%d: Impossible\n", kase);
		else printf("Case #%d: %d\n", kase, ans);
	}

	return 0;
}
