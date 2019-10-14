#pragma warning(disable:4996)

#include <iostream>
#include <list>
#include <queue>

#define N (20 + 5)
#define K (50 + 5)
#define M (10000 + 10)

using namespace std;

class Node{
public:
	int sum, hei;
	list<int> lnk;

	Node();
};

int tc;

int n, m, k, nn, result;

int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int cap[M][M];
int flw[M][M];

int node[K][N][N];

char flr[K][N][N];

Node pt[M];

FILE *f = fopen("output.txt", "w");

Node::Node(){
	sum = hei = 0;
}

void input(){
	int i, j;
	scanf("%d %d %d", &n, &m, &k);
	for(i = 0; i < k; i++){
		for(j = 0; j < n; j++){
			scanf("%s", &flr[i][j]);
			flr[k][i][m] = '\0';
		}
	}
}

void process(){
	int i, j, l, o, x, y, cnt = 0, now, p;
	list<int> qlst;
	list<int> ::iterator it, jt;
	queue<pair<int, int> > que;
	nn = 2;
	pt[0] = Node();
	pt[1] = Node();
	for(i = 0; i < k; i++){
		for(j = 0; j < n; j++){
			for(l = 0; l < m; l++){
				node[i][j][l] = 0;
			}
		}
		for(j = 0; j < n; j++){
			for(l = 0; l < m; l++){
				if(flr[i][j][l] == '.' && node[i][j][l] == 0){
					node[i][j][l] = nn;
					pt[nn] = Node();;
					que.push(pair<int, int>(j, l));
					if((i & 1) == 0){
						cap[0][nn] = 1;
						pt[0].lnk.push_back(nn);
						pt[nn].lnk.push_back(0);
					}
					else{
						cap[nn][1] = 1;
						pt[1].lnk.push_back(nn);
						pt[nn].lnk.push_back(1);
					}
					for(; !que.empty(); que.pop()){
						if(0 < i && flr[i - 1][que.front().first][que.front().second] == '.'){
							if((i & 1) == 0){
								cap[nn][node[i - 1][que.front().first][que.front().second]] = 1;
							}
							else{
								cap[node[i - 1][que.front().first][que.front().second]][nn] = 1;
							}
							pt[node[i - 1][que.front().first][que.front().second]].lnk.push_back(nn);
							pt[nn].lnk.push_back(node[i - 1][que.front().first][que.front().second]);
							cnt++;
						}
						for(o = 0; o < 4; o++){
							x = que.front().first + dir[o][0];
							y = que.front().second + dir[o][1];
							if(0 <= x && x < n && 0 <= y && y < m && flr[i][x][y] == '.' && node[i][x][y] == 0){
								node[i][x][y] = nn;
								que.push(pair<int, int>(x, y));
							}
						}
					}
					nn++;
				}
			}
		}
	}
	pt[0].hei = nn;
	for(it = pt[0].lnk.begin(); it != pt[0].lnk.end(); it++){
		p = cap[0][*it];
		flw[0][*it] += p;
		flw[*it][0] -= p;
		pt[*it].sum += p;
	}
	for(i = 2; i < nn; i++){
		qlst.push_back(i);
	}
	for(jt = qlst.begin(); jt != qlst.end(); jt++){
		now = *jt;
		i = pt[now].hei;
		for(; pt[now].sum; ){
			for(it = pt[now].lnk.begin(); pt[now].sum && it != pt[now].lnk.end(); it++){
				if(0 < cap[now][*it] - flw[now][*it] && pt[*it].hei < pt[now].hei){
					p = min(pt[now].sum, cap[now][*it] - flw[now][*it]);
					flw[now][*it] += p;
					flw[*it][now] -= p;
					pt[now].sum -= p;
					pt[*it].sum += p;
				}
			}
			if(pt[now].sum){
				p = 2147483647;
				for(it = pt[now].lnk.begin(); it != pt[now].lnk.end(); it++){
					if(0 < cap[now][*it] - flw[now][*it]){
						p = min(p, pt[*it].hei);
					}
				}
				pt[now].hei = p + 1;
			}
		}
		if(i != pt[now].hei){
			qlst.erase(jt);
			qlst.push_front(now);
			jt = qlst.begin();
			continue;
		}
	}
	for(i = 0; i < nn; i++){
		for(j = 0; j < nn; j++){
			cap[i][j] = flw[i][j] = 0;
		}
	}
	result = (nn - 2) - pt[1].sum;
}

void output(){
	printf("Case #%d: %d\n", tc, result);
	fprintf(f, "Case #%d: %d\n", tc, result);
}

int main(){
	int t;
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	for(tc = 1; tc <= t; tc++){
		input();
		process();
		output();
	}
	fcloseall();
	return 0;
}