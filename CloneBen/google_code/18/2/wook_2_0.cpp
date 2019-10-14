// GCJ 2012 Korea Semifinal

#define PROB "C"
#define CONSOLE false  

#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <string>

#pragma warning(disable:4996)
using namespace std;

#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define uniquify(v) {sort(all(v));(v).erase(unique(all(v)), (v).end());}

int n, m, f;

char a[51][21][21];

int R[51][21][21];

bool vis[21][21];

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

void bfs(int k, int i, int j, int ROOM)
{
	queue< pair<int, int> > Q;
	Q.push( make_pair(i, j) );

	R[k][i][j] = ROOM;
	while(!Q.empty())
	{
		i = Q.front().first;
		j = Q.front().second;
		Q.pop();


		for(int d = 0; d < 4; ++ d) {
			int ii = i + dx[d], jj = j + dy[d];
			if(ii<0||jj<0||ii>=n||jj>=m) continue;
			if(a[k][ii][jj] == '#') continue;
			if(R[k][ii][jj] != 0) continue;

			R[k][ii][jj] = ROOM;
			Q.push( make_pair(ii, jj) );
		}
	}
}

vector<int> ADJ[1000];

bool seen[1000];

int amatch[1000];
int bmatch[1000];

bool improve(int a)
{
	for(int i = 0; i < ADJ[a].size(); ++ i)
	{
		int b = ADJ[a][i];
		if(seen[b]) continue;
		seen[b] = true;
		if(bmatch[b] == -1 || improve(bmatch[b])) {
			amatch[a] = b;
			bmatch[b] = a;
			return true;
		}
	}
	return false;
}
int solve()
{
	int ROOM = 0;

	memset(R, 0, sizeof(R));
	REP(k, f)
	{
		REP(i, n) REP(j, m) {
			if(R[k][i][j] == 0 && a[k][i][j] == '.') {
				bfs(k, i, j, ++ROOM);
			}
		}
	}
	vector<int> EVEN;

	// build graph
	for(int k = 0; k < f; ++ k)
	{
		for(int ud = -1; ud<=1; ud += 2) {
			REP(i, n) REP(j, m) {
				int ra = R[k][i][j], rb = R[k+ud][i][j];
				if(ra == 0 || rb == 0) continue;
	
				if(k % 2 == 0) {
					ADJ[ra].push_back(rb);
				}
			}
		}
	}
	for(int k=0; k<f; ++k) {
		if(k%2 == 0) {
			REP(i, n) REP(j, m) {
				if(R[k][i][j]>0)
				EVEN.push_back(R[k][i][j]);
			}
		}
	}

	uniquify(EVEN);
	memset(amatch, -1, sizeof(amatch));
	memset(bmatch, -1, sizeof(bmatch));

	int res = 0;
	for(int i = 0; i < EVEN.size(); ++ i)
	{
		int a = EVEN[i];
		if(amatch[a] == -1) {
			memset(seen, 0, sizeof(seen));
			if(improve(a)) ++res;
		}
	}
	return ROOM - res;
}

int main()
{
	freopen(PROB".in", "r", stdin);
	freopen(PROB".out", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int tt = 1; tt <= T; ++ tt)
	{
		scanf("%d %d %d", &n, &m, &f);
		REP(q, 1000) ADJ[q].clear();
		REP(k, f) REP(i, n)
			scanf("%s", a[k][i]);


		fprintf(stderr, "<!> %d\n", tt);
		printf("Case #%d: %d\n", tt, solve()); 

	}

	return 0;
}
