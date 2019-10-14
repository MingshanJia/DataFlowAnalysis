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

// Global Macro

#define FOR(V,I,L) for(int V=(I);V<(L);(V)++)     // for loop macro start from I until < L
#define FORe(V,I,L) FOR(V,I,L+1)
#define FORd(V,I,L) for(int V=(I);V>=(L);(V)--)
#define REP(V,L) FOR(V,0,L)                           // for loop start from 0
#define REPe(V,L) FORe(V,0,L)
#define REPd(V,I) FORd(V,I,0)
#define IT(adt) adt::iterator        // Create Iterator
#define FOR_EACH(I,C) for(I=(C).begin(); I!=(C).end(); ++I)    // for loop for iterator

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int    ui;
typedef long double     ld;

char g[22][22][22];
int N, M, K;

int num_room;
bool visit[22][22][22];

int room[22][22][22];

int MM[21000]; // matched people with y[i];
int V[21000]; // visit check
int c;

void dfs_same_room(int k, int n, int m) {
	if((0<=k && k<K) && (0<=n&&n<=N) && (0<=m && m<M) && g[k][n][m] == '.' && !visit[k][n][m]) {
		room[k][n][m] = num_room;
		visit[k][n][m] = true;

		dfs_same_room(k, n-1, m);
		dfs_same_room(k, n+1, m);
		dfs_same_room(k, n, m+1);
		dfs_same_room(k, n, m-1);
	}
	else return;
}

vector<int> adj[21000];

bool dfs(int v) {
  if(V[v]==c) return false;
  V[v]=c;

  for(int i=0;i < adj[v].size();i++) {
    int t = adj[v][i];
    if(MM[t]==-1 || (v!=MM[t] && dfs(MM[t])) ) { MM[t]=v; return true; }
  }
  return false;
}


int main(void) {
	//freopen("input.txt", "r", stdin);
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	int T; scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		scanf("%d %d %d", &N, &M, &K);

		for(int k=0;k<K;k++) for(int i=0;i<N;i++) {
			scanf("%s", g[k][i]);
		}
		memset(visit, false, sizeof(visit));
		memset(room, -1, sizeof(room));

		vector<int> second_floor_room_indexes;
		num_room = 0;
		for(int k=0;k<K;k++) for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(g[k][i][j]=='.' && !visit[k][i][j]) {
			dfs_same_room(k, i, j);
			if(k==1) second_floor_room_indexes.push_back(num_room);
			num_room++;
		}

		vector<int> left_idxes;

		for(int i=0;i<num_room;i++) adj[i].clear();

		for(int k=0;k<K;k++) for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(g[k][i][j] == '.') {
			if(k%2==0) left_idxes.push_back(room[k][i][j]);

			if(k!=0 && g[k-1][i][j]=='.') {
				int sidx = room[k][i][j];
				int eidx = room[k-1][i][j];
				
				adj[sidx].push_back(eidx);
			}

			if(k!=K-1 && g[k+1][i][j]=='.') {
				int sidx = room[k][i][j];
				int eidx = room[k+1][i][j];
				
				adj[sidx].push_back(eidx);
			}
		}

		for(int i=0;i<num_room;i++) {
			sort(adj[i].begin(), adj[i].end());
			adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
		}

		// do bipartite 
		memset(V, -1, sizeof(V));
		memset(MM, -1, sizeof(MM));

		sort(left_idxes.begin(), left_idxes.end());
		left_idxes.erase(unique(left_idxes.begin(), left_idxes.end()), left_idxes.end());


		int num_matching = 0;
		for(c=0;c<int(left_idxes.size());c++) if(dfs(left_idxes[c])) num_matching++;

		int res = num_room - num_matching ;
		printf("Case #%d: %d\n", tc, res);
		fprintf(stderr, "Case #%d: %d\n", tc, res);
		fflush(stdout);
		fflush(stderr);
	}

	return 0;
}
