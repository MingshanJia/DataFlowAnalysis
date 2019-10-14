#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 10004
typedef pair<int,int> pii;

int T,K,N,P,M,ans;
int X[MAXN],V[MAXN],D[101][MAXN];
bool visit[MAXN];
vector <int> con[MAXN],cond[MAXN];
priority_queue < pii > que;

void proc(int t)
{
	int i,j,k,d,n;
	for (i=1;i<=N;i++) D[t][i] = 1e9, visit[i] = 0;
	D[t][X[t]] = 0;
	while (!que.empty()) que.pop();
	que.push(pii(0,X[t]));
	while (!que.empty()){
		n = que.top().second;
		if (D[t][n] != -que.top().first || visit[n]){ que.pop(); continue; }
		que.pop();
		visit[n] = 1;
		for (i=0;i<con[n].size();i++){
			k = con[n][i]; d = cond[n][i];
			if (D[t][k] > D[t][n]+d && !visit[k])
				D[t][k] = D[t][n]+d, que.push(pii(-D[t][k],k));
		}
	}
}

int main()
{
	int i,j,k,d;
	freopen("input.txt","r",stdin), freopen("output.txt","w",stdout);
	for (scanf("%d",&T);T--;){
		scanf("%d%d%d",&N,&P,&M);
		for (i=1;i<=N;i++) con[i].clear(), cond[i].clear();
		for (i=1;i<=P;i++){
			scanf("%d%d",X+i,V+i);
		}
		while (M--){
			scanf("%d",&d);
			for (scanf("%d%d",&k,&i);--k;){
				scanf("%d",&j);
				con[i].push_back(j);
				cond[i].push_back(d);
				con[j].push_back(i);
				cond[j].push_back(d);
				i = j;
			}
		}
		for (i=1;i<=P;i++) proc(i);
		ans = 1e9;
		for (i=1;i<=N;i++){
			k = 0;
			for (j=1;j<=P;j++){
				if (D[j][i] == 1e9) break;
				if (k < D[j][i]*V[j]) k = D[j][i]*V[j];
			}
			if (j <= P) continue;
			if (ans > k) ans = k;
		}
		printf("Case #%d: %d\n",++K,ans==1e9?-1:ans);
	}
}