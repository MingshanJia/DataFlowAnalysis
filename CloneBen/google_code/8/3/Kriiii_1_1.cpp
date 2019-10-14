#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct vertex{
	vertex(){x = i = t = 0;}
	vertex(int x_, int i_, int t_){ x = x_; i = i_; t = t_;}
	int x,i,t;
	bool operator <(const vertex a) const{
		if (x != a.x) return x < a.x;
		if (i != a.i) return i < a.i;
		return t < a.t;
	}
};

struct edge{
	edge(vertex v_, int c_){v = v_; c = c_;}
	vertex v;
	int c;
};
map<vertex, vector<edge> > G;

struct phase{
	phase(vertex v_, int c_){v = v_; c = c_;}
	vertex v;
	int c;

	bool operator <(const phase t)const{return c > t.c;}
};

int N,W[101];

void go(vertex s, vertex e)
{
	map<vertex, int> dist;
	priority_queue<phase> Q;

	Q.push(phase(s,0)); while (!Q.empty()){
		vertex v = Q.top().v; int c = Q.top().c; Q.pop();

		if (dist.count(v)) continue;
		dist[v] = c;

		for (auto u : G[v]){
			if (!dist.count(u.v)){
				Q.push(phase(u.v,c+u.c));
			}
		}
	}

	int ans = -1;
	if (dist.count(e)) ans = dist[e];
	e.t = 1;
	if (dist.count(e)){
		int v = dist[e];
		if (ans == -1 || ans > v) ans = v;
	}
	printf ("%d\n",ans);
}

int main()
{
	freopen ("1.in","r",stdin);
	freopen ("1.out","w",stdout);

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d:\n",Case);

		G.clear();
		scanf ("%d",&N);
		for (int i=1;i<=N;i++){
			int o; scanf ("%d %d",&o,&W[i]);
			for (int j=1;j<=o;j++){
				vertex x(i,j,0), y(i,j,1);
				G[x].push_back(edge(y,W[i]));
			}
			for (int j=1;j<o;j++){
				int l; scanf ("%d",&l);
				vertex x(i,j,1), y(i,j+1,1);
				G[x].push_back(edge(y,l));
				G[y].push_back(edge(x,l));
			}
		}

		scanf ("%d",&N); while (N--){
			int a,b,c,d,l; scanf ("%d %d %d %d %d",&a,&b,&c,&d,&l);
			vertex x(a,b,0), y(c,d,0);
			G[x].push_back(edge(y,l));
			G[y].push_back(edge(x,l));
			x = vertex(a,b,1);
			G[x].push_back(edge(y,l));
			x = vertex(a,b,0);
			y = vertex(c,d,1);
			G[y].push_back(edge(x,l));
		}

		scanf ("%d",&N); while (N--){
			int a,b,c,d; scanf ("%d %d %d %d",&a,&b,&c,&d);
			go(vertex(a,b,0),vertex(c,d,0));
		}
	}

	return 0;
}