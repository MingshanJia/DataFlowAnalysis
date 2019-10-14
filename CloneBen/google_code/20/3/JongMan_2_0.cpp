#include<limits>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<map>
#include<set>
#include<time.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<utility>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int cities, friends, roads;

vector<pair<int,int> > graph[10000];
vector<int> start, inverseSpeed;

const long long MAX = numeric_limits<int>::max() + 1LL;

vector<long long> dijkstra(int src) {
	vector<long long> dist(cities, MAX);
	dist[src] = 0;
	priority_queue<pair<long long, int> > pq;
	pq.push(make_pair(0, src));
	while(!pq.empty()) {
		long long cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		// 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시한다
		if(dist[here] < cost) continue;
		// 인접한 정점들을 모두 검사한다
		for(int i = 0; i < graph[here].size(); ++i) {
			int there = graph[here][i].first;
			long long nextDist = cost + graph[here][i].second;
			// 더 짧은 경로를 발견하면, dist[] 를 갱신하고 우선 순위 큐에 넣는다
			if(dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}

int main() {
  int cases;
  scanf("%d", &cases);
  for(int cc = 0; cc < cases; ++cc) {
    scanf("%d %d %d", &cities, &friends, &roads);
    for(int i = 0; i < cities; ++i) graph[i].clear();
    start.resize(friends);
    inverseSpeed.resize(friends);
    for(int i = 0; i < friends; ++i)
      scanf("%d %d", &start[i], &inverseSpeed[i]);
    for(int i = 0; i < roads; ++i) {
      int distance, count, last;
      scanf("%d %d %d", &distance, &count, &last);
      last -= 1;
      for(int j = 0; j < count-1; ++j) {
        int next;
        scanf("%d", &next);
        next -= 1;
        graph[last].push_back(make_pair(next, distance));
        graph[next].push_back(make_pair(last, distance));
        last = next;
      }
    }

    vector<long long> maxval(cities, 0);
    for(int i = 0; i < friends; ++i) {
      vector<long long> forFriend = dijkstra(start[i]-1);
      for(int j = 0; j < cities; ++j)
        maxval[j] = max(maxval[j], forFriend[j] * inverseSpeed[i]);
    }

    long long minTime = *min_element(maxval.begin(), maxval.end());
    printf("Case #%d: ", cc+1);
    if(minTime >= MAX)
      printf("-1\n");
    else
      printf("%Ld\n", minTime);
  }
}

