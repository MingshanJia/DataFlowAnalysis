// C.wook

#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>

using namespace std;

int N;	//city
int F;	//friends
int M;	//roads
int X[100], V[100];	// initial position, velocity

int RoadDistance[1000];
vector<int> RoadChain[1000];

vector<int> adj[10000];
vector<int> adjw[10000];

const int INF = 987654321;

void gen_gr() {
	for(int i=0; i<N; ++i) adj[i].clear(), adjw[i].clear();

	for(int i=0; i<M; ++i) {
		vector<int> &ref = RoadChain[i];

		for(int j=1; j<(int)ref.size(); ++j) {
			int a = ref[j-1], b = ref[j];
			adj[a].push_back(b);
			adj[b].push_back(a);
			adjw[a].push_back(RoadDistance[i]);
			adjw[b].push_back(RoadDistance[i]);
		}
	}
}

void dijkstra(int S, int dist[10000])
{	
	struct node {
		int v;
		int dist;
		node(int v, int dist) : v(v), dist(dist) {}
		inline bool operator > (const node &rhs) const {
			return dist > rhs.dist;
		}
	};

	std::fill(dist, dist + N, INF);
	dist[S] = 0;

	priority_queue< node, vector<node>, greater<node> > Q;
	Q.push( node(S, 0) );

	int viscnt = 0;
	while(!Q.empty())
	{
		int u = Q.top().v, distu = Q.top().dist; Q.pop();
		if(distu > dist[u]) continue;
		if(++viscnt == N) break;

		for(int q=0; q<adj[u].size(); ++q)
		{
			int v = adj[u][q];
			if(dist[u] + adjw[u][q] < dist[v]) {
				dist[v] = dist[u] + adjw[u][q];
				Q.push( node(v, dist[v]) );
			}
		}
	}

}

int D[100][10000];

int solve()
{
	for(int f = 0; f < F; ++f)
	{
		int S = X[f];
		dijkstra(S, D[f]);
		
		for(int j=0; j<N; ++j) {
			if(D[f][j] < INF)
				D[f][j] *= V[f];
		}
	}

	int ans = INF;
	for(int city = 0; city < N; ++ city) {
		int latest = 0;
		for(int i=0; i<F; ++i) {
			latest = max(latest, D[i][city]);
		}
		ans = min(ans, latest);
	}

	if(ans >= INF) return -1;
	return ans;
}

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t)
	{
		scanf("%d %d %d", &N, &F, &M);
		for(int i=0; i<F; ++i) {
			scanf("%d %d", &X[i], &V[i]);
			X[i] --;
		}
		for(int i=0; i<M; ++i) {
			int amt;
			scanf("%d %d", &RoadDistance[i], &amt);
			RoadChain[i].clear();
			for(int q=0; q<amt; ++q) {
				int t; scanf("%d", &t); t--;
				RoadChain[i].push_back(t);
			}
		}
		gen_gr();
		printf("Case #%d: %d\n", t, solve());
	}
	return 0;
}