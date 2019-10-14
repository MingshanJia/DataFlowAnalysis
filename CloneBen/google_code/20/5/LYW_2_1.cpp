#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#define MAX 400000001
using namespace std;

int main(void) {
	int testnum;
	scanf("%d", &testnum);
	for (int testcase = 1; testcase <= testnum; testcase++) {
		int N, P, M;
		scanf("%d %d %d", &N, &P, &M);
		
		vector <int> start_city, velocity;
		for (int i = 0; i < P; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			start_city.push_back(a - 1);
			velocity.push_back(b);
		}
		
		vector < vector < int > > edge_dest, edge_length;
		edge_dest.resize(N);
		edge_length.resize(N);
		for (int i = 0; i < M; i++) {
			int edge_length_, num_city, a, b;
			scanf("%d %d", &edge_length_, &num_city);
			scanf("%d", &a);
			a--;
			for (int j = 1; j < num_city; j++) {
				scanf("%d", &b);
				b--;
				edge_length[a].push_back(edge_length_);
				edge_dest[a].push_back(b);
				edge_length[b].push_back(edge_length_);
				edge_dest[b].push_back(a);
				a = b;
			}
		}
		
		vector< vector < int > > dist;
		dist.resize(P);
		
		for (int i = 0; i < P; i++) {
			dist[i].resize(N);
			for (int j = 0; j < N; j++)
				dist[i][j] = MAX;
			
			set < pair <int, int> > Queue;
			Queue.insert(make_pair(0, start_city[i]));
			
			while (!Queue.empty()) {
				int d = (*Queue.begin()).first;
				int x = (*Queue.begin()).second;
				Queue.erase(Queue.begin());
				
				if (dist[i][x] < d * velocity[i])
					continue;
				dist[i][x] = d * velocity[i];
				
				int num_edges = edge_length[x].size();
				for (int j = 0; j < num_edges; j++) {
					int dest = edge_dest[x][j];
					int length = edge_length[x][j];
					if (dist[i][dest] == MAX)
						Queue.insert(make_pair(d + length, dest));
				}
			}
		}
		
		int ans = MAX;
		for (int i = 0; i < N; i++) {
			int meeting_time = -1;
			for (int j = 0; j < P; j++) {
				meeting_time = max(meeting_time, dist[j][i]);
			}
			ans = min(ans, meeting_time);
		}
		if (ans == MAX)
			ans = -1;		
		printf("Case #%d: %d\n", testcase, ans);
	}
	return 0;
}