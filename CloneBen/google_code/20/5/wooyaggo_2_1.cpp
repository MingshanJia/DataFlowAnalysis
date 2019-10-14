// C++ Header

// -- Base
#include <iostream>
#include <sstream>
// Data Structure
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <algorithm>

// C Header
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cstddef>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int    ui;
typedef long double     ld;

#include <stdio.h>
#include <algorithm>
#include <limits.h>

#include <vector>
#include <utility>

using namespace std;
int N, P, M;
int hsize;

typedef pair<ll ,ll> pii;
vector<pii> adj[31111];
ll d[22222], h[22222], idx[22222];

void adjust(int v) {
	for(int i=v; i!=1 && d[h[i]] < d[h[i/2]]; i/=2) {
		swap(idx[h[i]], idx[h[i/2]]);
		swap(h[i], h[i/2]);
	}
}

void pop() {
	int v = 1;
	idx[h[1]] = -1;
	h[1] = h[hsize--]; idx[h[1]] = 1;

	int child=2;
	while(1)
	{
		child = 2*v;
		if(child<hsize && d[h[child]] > d[h[child+1]]) child++;
		if(child>hsize) break;

		if(d[h[child]] >= d[h[v]]) break;

		swap(idx[h[v]], idx[h[child]]);
		swap(h[v], h[child]);

		v = child;
	}
}

void dijkstra(int s) {
	for(int i=1;i<=N;i++) d[i] = LLONG_MAX;
	for(int i=1;i<=N;i++) h[i]=idx[i]=i;
	hsize = N;

	d[s]=0;
	swap(idx[s], idx[1]);
	swap(h[s], h[1]);
	while(hsize) {
		int minidx=-1;

		minidx = h[1];
		if(minidx==-1) break;
		if(d[minidx]==LLONG_MAX) break;

		for(int i=0;i<adj[minidx].size();i++) {
			pii t = adj[minidx][i];
			ll e = t.first;
			ll c = t.second;
			if(idx[e]!=-1 && d[e] > d[minidx]+c) {
				d[e] = d[minidx]+c;

				adjust(idx[e]);
			}
		}
		pop();
	}
}


/*
int main(void) {
//freopen("input.txt", "r", stdin);

int C; scanf("%d", &C);

while(C--) {
scanf("%d %d", &N, &M);

for(int i=1;i<=N;i++) adj[i].clear();

for(int i=0;i<M;i++) {
int a,b,c; scanf("%d %d %d", &a, &b, &c);
adj[a+1].push_back( make_pair(b+1, c) );
adj[b+1].push_back( make_pair(a+1, c) );
}

printf("%d\n", dijkstra(1, N));
}

return 0;
}
*/

int X[111], V[111];
int cnt[11111];
ll time[11111];

int main(void) {
	//freopen("input.txt", "r", stdin);
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);

	int T; scanf("%d", &T);

	for(int tc=1; tc<=T; tc++) {
		scanf("%d %d %d", &N, &P, &M);
		for(int i=1;i<=P;i++) {
			scanf("%d %d", &X[i], &V[i]);
		}

		for(int i=0;i<=N;i++) adj[i].clear();

		for(int i=0;i<M;i++) {
			int D, L; scanf("%d %d", &D, &L);

			int p[2];
			scanf("%d",&p[0]);
			for(int i=1;i<L;i++) {
				scanf("%d", &p[i%2]);
				adj[ p[(i+1)%2] ].push_back( make_pair(p[i%2], D) ); 
				adj[ p[(i)%2] ].push_back( make_pair(p[(i+1)%2], D) ); 
			}
		}

		memset(time, -1, sizeof(time));
		memset(cnt, 0, sizeof(cnt));
		for(int i=1;i<=P;i++){
			dijkstra(X[i]);

			for(int j=1;j<=N;j++) if(d[j]!=LLONG_MAX) {
				cnt[j]++;
				time[j] = max(time[j], d[j]*V[i]);
			}
		}

		ll res = LLONG_MAX;

		for(int i=1;i<=N;i++) if(cnt[i] == P) {
			res = min(res, time[i]);
		}

		if(res == LLONG_MAX) res = -1;

		printf("Case #%d: %lld\n", tc, res);
	}

	return 0;
}
