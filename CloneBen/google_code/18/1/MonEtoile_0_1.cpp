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

#define _INFILE		"A-large.in"
#define _OUTFILE	"A-large.out"

typedef long long ll;

// the maximum number of vertices + 1
#define NN 124
#define MAX 0x7FFFFFFFFFFFFFFFLL
// adjacency matrix (fill this up)
ll cap[NN][NN];
// cost per unit of flow matrix (fill this up)
ll cost[NN][NN];
// flow network and adjacency list
ll fnet[NN][NN];
int adj[NN][NN], deg[NN];
// Dijkstra's successor and depth
ll par[NN];
ll d[NN]; // par[source] = source;
// Labelling function
ll pi[NN];
#define CLR(a, x) memset( a, x, sizeof( a ) )
#define Inf (MAX/2)
// Dijkstra's using non-negative edge weights (cost + potential)
#define Pot(u,v) (d[u] + pi[u] - pi[v])
bool dijkstra( int n, int s, int t ) 
{
	int i;
	for(i = 0; i < n; i++ ) d[i] = Inf, par[i] = -1;
	d[s] = 0;
	par[s] = -n - 1;
	while( 1 ) 
	{
		int i;
		// find u with smallest d[u]
		int u = -1;
		ll bestD = Inf;
		for(i = 0; i < n; i++ ) if( par[i] < 0 && d[i] < bestD ) bestD = d[u = i];
		if( bestD == Inf ) break;
		// relax edge (u,i) or (i,u) for all i;
		par[u] = -par[u] - 1;
		for(i = 0; i < deg[u]; i++ ) 
		{
			// try undoing edge v->u
			int v = adj[u][i];
			if( par[v] >= 0 ) continue;
			if( fnet[v][u] && d[v] > Pot(u,v) - cost[v][u] )
				d[v] = Pot( u, v ) - cost[v][u], par[v] = -u-1;
			// try edge u->v
			if( fnet[u][v] < cap[u][v] && d[v] > Pot(u,v) +	cost[u][v] )
				d[v] = Pot(u,v) + cost[u][v], par[v] = -u - 1;
		}
	}
	for(i = 0; i < n; i++ ) if( pi[i] < Inf ) pi[i] += d[i];
	return par[t] >= 0;
}
#undef Pot
ll dmin(ll a,ll b)
{
	if (a>b) return b; 
	else return a;
}

// 정점의 수, source, sink, sum(cost*flow)
ll mcmf3( int n, int s, int t, ll &fcost )
{
	// build the adjacency list
	CLR( deg, 0 );
	for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
			if( cap[i][j] || cap[j][i] ) adj[i][deg[i]++] = j;
	CLR( fnet, 0 );
	CLR( pi, 0 );
	ll flow = fcost = 0;
	// repeatedly, find a cheapest path from s to t
	while( dijkstra( n, s, t ) ) 
	{
		ll v,u;
		// get the bottleneck capacity
		ll bot = MAX;
		for(v = t, u = par[v]; v != s; u = par[v = u] )
		{
			if (fnet[v][u]) bot = dmin(bot,fnet[v][u]); 
			else bot = dmin(bot,cap[u][v]-fnet[u][v]);
		}
		// update the flow network
		for(v = t, u = par[v]; v != s; u = par[v = u] )
			if( fnet[v][u] ) { fnet[v][u] -= bot; fcost -= bot * cost[v][u]; }
			else { fnet[u][v] += bot; fcost += bot * cost[u][v]; }
		flow += bot;
	}
	return flow;
}

ll solve()
{
	ll n;
	ll a[3], b[3];
	scanf("%lld",&n);
	memset(cap, 0, sizeof(cap));
	memset(cost, 0, sizeof(cost));
	int t = 7;
	int s = 0;
	for(int i=0; i<3; i++)
	{
		scanf("%lld",&a[i]);
		cap[s][i+1] = a[i];
		for(int j=0; j<3; j++)
			cap[i+1][j+4] = Inf;
	}
	
	for(int i=0; i<3; i++)
	{
		scanf("%lld",&b[i]);
		cap[i+4][t] = b[i];
	}

	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
		{
			int temp;
			scanf("%d",&temp);
			cost[i+1][j+4] = 100000 -temp;
		}
		
	ll fcost;
	ll flow = mcmf3( 8, s, t, fcost );
	return 100000LL * n - fcost;
}

int main(void)
{
	int T;
	freopen(_INFILE, "r", stdin);
	freopen(_OUTFILE, "w", stdout);

	scanf("%d",&T);

	for(int i=0; i<T; i++)
	{
		printf("Case #%d: %lld\n", i+1, solve());
	}
	return 0;
}

