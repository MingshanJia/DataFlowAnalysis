#pragma warning(disable:4996)

#include <iostream>
#include <algorithm>
#include <list>
#include <queue>

#define N (10000 + 10)
#define P (100 + 10)

using namespace std;

int tc;
int n, m;

long long res;

long long dist[N] = {0, };

long long frd[P][2] = {0, };
long long map[P][N] = {0, };

bool check[N] = {false, };

list<pair<int, long long> > lnk[N];

void input(){
	int i, j, t, p, q, r, s;
	scanf("%d %d %d", &n, &m, &t);
	for(i = 0; i < m; i++){
		scanf("%d %d", &frd[i][0], &frd[i][1]);
		frd[i][0]--;
	}
	for(i = 0; i < t; i++){
		scanf("%d %d %d", &p, &q, &r);
		for(j = 1; j < q; j++){
			scanf("%d", &s);
			if(r != s){
				lnk[r - 1].push_back(pair<int, long long>(s - 1, p));
				lnk[s - 1].push_back(pair<int, long long>(r - 1, p));
				r = s;
			}
		}
	}
}

void process(){
	int i, j, t;
	list<pair<int, long long> > ::iterator it;
	priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > que;
	memset(map, false, sizeof(map));
	for(i = 0; i < m; i++){
		memset(check, false, sizeof(check));
		for(; !que.empty(); que.pop());

		check[frd[i][0]] = true;
		for(it = lnk[frd[i][0]].begin(); it != lnk[frd[i][0]].end(); it++){
			map[i][it->first] = it->second;
			que.push(pair<long long, int>(it->second, it->first));
		}
		for(j = 1; j < n; j++){
			for(; !que.empty() && check[que.top().second]; que.pop());
			if(que.empty()){
				break;
			}
			t = que.top().second;
			que.pop();
			check[t] = true;
			for(it = lnk[t].begin(); it != lnk[t].end(); it++){
				if(!check[it->first] && (map[i][it->first] == 0 || map[i][t] + it->second < map[i][it->first])){
					map[i][it->first] = map[i][t] + it->second;
					que.push(pair<long long, int>(map[i][it->first], it->first));
				}
			}
		}
	}
	res = -1;
	for(i = 0; i < n; i++){
		lnk[i].clear();
		dist[i] = 0;
		for(j = 0; j < m; j++){
			if(frd[j][0] != i && map[j][i] == 0){
				break;
			}
			dist[i] = max(dist[i], map[j][i] * frd[j][1]);
		}
		if(j == m && (res == -1 || dist[i] < dist[res])){
			res = i;
		}
	}
	if(0 <= res){
		res = dist[res];
	}
}

FILE *f;

void output(){
	printf("Case #%d: %lld\n", tc, res);
	fprintf(f, "Case #%d: %lld\n", tc, res);
}

int main(){
	int t;
	freopen("input.txt", "r", stdin);
	f = fopen("output.txt", "w");
	scanf("%d", &t);
	for(tc = 1; tc <= t; tc++){
		input();
		process();
		output();
	}
	fcloseall();
	return 0;
}
