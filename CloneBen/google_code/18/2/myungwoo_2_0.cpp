#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int yy[]={-1,0,1,0},xx[]={0,1,0,-1};
int T,TN,N,M,K,P,Q,num[51][21][21],ans;
int head,tail;
int path[10004],pcnt;
char map[51][21][22];
bool w[10004][10004],visit[10004];
vector <int> con[10004];

struct QUE{
	int y,x;
} que[444];

void iq(int y,int x){ QUE q={y,x}; que[tail++] = q; }

void bfs(int k,int y,int x)
{
	QUE q={0,};
	int n,i;
	if (k&1) n = ++P;
	else n = ++Q;
	head = tail = 0;
	num[k][y][x] = n;
	iq(y,x);
	while (head != tail){
		q = que[head++];
		for (i=0;i<4;i++){
			y = q.y+yy[i], x = q.x+xx[i];
			if (y < 1 || x < 1 || y > N || x > M || map[k][y][x] != '.' || num[k][y][x]) continue;
			num[k][y][x] = n;
			iq(y,x);
		}
	}
}

bool dfs(int n,int c)
{
	path[c] = n;
	visit[n] = 1;
	if (n == P+Q+1){
		pcnt = c;
		return 1;
	}
	int i,k;
	for (i=0;i<con[n].size();i++){
		k = con[n][i];
		if (!visit[k] && w[n][k] && dfs(k,c+1)) return 1;
	}
	return 0;
}

int main()
{
	int i,j,k;
	freopen("input.txt","r",stdin), freopen("output.txt","w",stdout);
	for (scanf("%d",&T);T--;){
		scanf("%d%d%d",&N,&M,&K);
		for (k=1;k<=K;k++){
			for (i=1;i<=N;i++){
				scanf("%s",map[k][i]+1);
				for (j=1;j<=M;j++) num[k][i][j] = 0;
			}
		}
		P = Q = 0;
		for (k=1;k<=K;k++){
			for (i=1;i<=N;i++) for (j=1;j<=M;j++) if (map[k][i][j] == '.' && !num[k][i][j]){
				bfs(k,i,j);
			}
		}
		for (i=0;i<=P+Q+1;i++){
			con[i].clear();
			for (j=0;j<=P+Q+1;j++) w[i][j] = 0;
		}
		for (k=1;k<=K;k+=2){
			for (i=1;i<=N;i++) for (j=1;j<=M;j++) if (num[k][i][j]){
				if (k < K && num[k+1][i][j] && !w[num[k][i][j]][P+num[k+1][i][j]]){
					w[num[k][i][j]][P+num[k+1][i][j]] = 1;
					con[num[k][i][j]].push_back(P+num[k+1][i][j]);
					con[P+num[k+1][i][j]].push_back(num[k][i][j]);
				}
				if (k > 1 && num[k-1][i][j] && !w[num[k][i][j]][P+num[k-1][i][j]]){
					w[num[k][i][j]][P+num[k-1][i][j]] = 1;
					con[num[k][i][j]].push_back(P+num[k-1][i][j]);
					con[P+num[k-1][i][j]].push_back(num[k][i][j]);
				}
			}
		}
		for (i=1;i<=P;i++) con[0].push_back(i), con[i].push_back(0), w[0][i] = 1;
		for (i=1;i<=Q;i++) con[P+i].push_back(P+Q+1), con[P+Q+1].push_back(P+i), w[P+i][P+Q+1] = 1;
		ans = P+Q;
		for (i=0;i<=P+Q+1;i++) visit[i] = 0;
		while (dfs(0,1)){
			ans--;
			for (i=1;i<pcnt;i++) w[path[i]][path[i+1]] = 0, w[path[i+1]][path[i]] = 1;
			for (i=0;i<=P+Q+1;i++) visit[i] = 0;
		}
		printf("Case #%d: %d\n",++TN,ans);
	}
}