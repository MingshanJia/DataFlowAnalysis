#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
typedef long long i64;

class dinic
{
	/*
	for every edge (src, dest, cap, flow), it must have pair edge (dest, src, 0, -flow)
	*/

	struct edge
	{
		edge *next, *pair;
		int src, dest, cap, flow;
	};

	int v, e;
	edge *pool, **con; int top;

	int* level;

public:
	dinic(int _v, int _e)
	{
		v = _v; e = _e;
		pool = new edge[e];
		con = new edge*[v];
		for(int i=0;i<v;i++) con[i] = NULL;
		top = 0;
	}

	~dinic()
	{
		delete [] pool;
		delete [] con;
	}

	edge* _add_edge(int src, int dest, int cap)
	{
		edge* ed = &(pool[top++]);
		ed->src = src;
		ed->dest = dest;
		ed->cap = cap;
		ed->flow = 0;

		ed->next = con[src];
		con[src] = ed;

		return ed;
	}

	void add_pair(int src, int dest, int cap1, int cap2)
	{
		edge *e1 = _add_edge(src, dest, cap1);
		edge *e2 = _add_edge(dest, src, cap2);

		e1->pair = e2;
		e2->pair = e1;
	}

	int dfs(int s, int d, int cap, bool *fin)
	{
		if(s==d || cap==0) return cap;
		if(fin[s]) return 0;
		fin[s] = true;
		int w = 0;
		for(edge* ed = con[s]; ed != NULL; ed = ed->next)
			if(level[ed->dest] > level[s]){
				int f = dfs(ed->dest, d, std::min(cap - w, ed->cap - ed->flow), fin);
				if(f > 0){
					ed->flow += f;
					ed->pair->flow -= f;
					w += f;
				}
			}

		return w;
	}

	long long max_flow(int s, int d)
	{
		level = new int[v];
		bool *fin = new bool[v];

		for(int i=0;i<e;i++) pool[i].flow = 0;

		long long ret = 0;

		for(bool update=true; update; ){
			update = false;

			//derminate distance
			std::fill(level, level+v, -1);
			level[s] = 0;
			std::queue<int> q;
			q.push(s);

			int ps;
			while(!q.empty()){
				ps = q.front(); q.pop();
				
				for(edge* ed = con[ps]; ed != NULL; ed = ed->next){
					if(ed->cap > ed->flow && level[ed->dest]==-1){
						level[ed->dest] = level[ps] + 1;
						q.push(ed->dest);
					}
				}
			}

			for(;;){
				std::fill(fin, fin+v, false);
				int gain = dfs(s, d, 0x7FFFFFFF, fin);
				if(gain==0) break;
				ret += gain;
				update = true;
			}
		}

		delete [] level;

		return ret;
	}
};

int W, H, B;
int X0[1010], Y0[1010], X1[1010], Y1[1010];

bool contain(int c, int d, int a, int b)
{
	return a <= c && d <= b;
}

int id[2500][1010];

int main()
{
	int T;
	scanf("%d", &T);

	for(int t = 0; t++ < T; ) {
		scanf("%d%d%d", &W, &H, &B);

		vector<int> Ys;
		for(int i = 0; i < B; i++) {
			scanf("%d%d%d%d", X0+i, Y0+i, X1+i, Y1+i);

			++X1[i];
			++Y1[i];

			Ys.push_back(Y0[i]);
			Ys.push_back(Y1[i]);
		}

		for(int i = 0; i < H; i++) Ys.push_back(i);

		Ys.push_back(0);
		Ys.push_back(H);

		sort(Ys.begin(), Ys.end());
		Ys.erase(unique(Ys.begin(), Ys.end()), Ys.end());

		int idp = 0;

		for(int i = 0; i < Ys.size()-1; i++) {
			for(int j = 0; j < W; j++) id[i][j] = -1;

			vector<int> act;
			for(int j = 0; j < B; j++) {
				if(contain(Ys[i], Ys[i+1], Y0[j], Y1[j])) {
					act.push_back(X0[j]);
					act.push_back(X1[j]);
				}
			}

			act.push_back(0);
			act.push_back(W);
			sort(act.begin(), act.end());

			for(int j = 0; j < act.size(); j+=2) {
				//printf("%d %d ", act[j], act[j+1]);
				if(act[j] < act[j+1]) {
					for(int k = act[j]; k < act[j+1]; k++) {
						id[i][k] = idp++;
						idp++;
					}
				}
			}
			//puts("");
		}

		int s = idp++; int d = idp++;
		dinic dn(idp, min(idp*20, 12000000));

		/*
		for(int i = 0; i < Ys.size() - 1; i++) {
			for(int j = 0; j < W; j++) printf("%2d ", id[i][j]);
			puts("");
		}
		*/

		for(int i = 0; i < W; i++) {
			if(id[0][i] >= 0) dn.add_pair(s, id[0][i], 1, 0);
		}
		for(int i = 0; i < W; i++) {
			if(id[Ys.size()-2][i] >= 0) dn.add_pair(id[Ys.size()-2][i]+1, d, 1, 0);
		}

		for(int i = 0; i < Ys.size()-2; i++) {
			for(int j = 0; j < W; j++) {
				if(id[i][j] >= 0 && id[i+1][j] >= 0) {
					dn.add_pair(id[i][j]+1, id[i+1][j], 1, 0);
					dn.add_pair(id[i+1][j]+1, id[i][j], 1, 0);
				}
			}
		}

		for(int i = 0; i < Ys.size()-1; i++) {
			for(int j = 0; j < W; j++) {
				if(id[i][j] >= 0) dn.add_pair(id[i][j], id[i][j] + 1, Ys[i+1] - Ys[i], 0);
			}

			for(int j = 0; j < W-1; j++) {
				if(id[i][j] >= 0 && id[i][j+1] >= 0) {
					dn.add_pair(id[i][j]+1, id[i][j+1], Ys[i+1] - Ys[i], 0);
					dn.add_pair(id[i][j+1]+1, id[i][j], Ys[i+1] - Ys[i], 0);
				}
			}
		}

		//printf("%d %d\n", s, d);
		printf("Case #%d: %d\n", t, dn.max_flow(s, d));
		fprintf(stderr, "%d\n", t);
	}

	return 0;
}
