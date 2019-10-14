#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXLL 999999999999999999ll
using namespace std;

vector< pair<int, long long> > edg[10000];
priority_queue< pair<long long, int> > qq;

int X[100], L;

long long D;
long long lte[10000];
long long dis[10000];
bool fd[10000];
long long V[100];
int main(){
	freopen("C-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	int N, M, P;
	scanf("%d",&T);
	int i, j, k;
	while(T-->0){
		for(i=0;i<10000;i++) edg[i].clear();
		scanf("%d %d %d",&N,&P,&M);
		for(i=0;i<P;i++){
			scanf("%d %lld", &X[i], &V[i]);
			X[i] --;
		}
		for(i=0;i<N;i++){ 
			lte[i] = 0;
		}
		for(i=0;i<M;i++){
			scanf("%lld %d", &D, &L);
			int now, bef;
			bef =  -1;
			for(j=0;j<L;j++){
				scanf("%d", &now);
				if (bef != -1){
					edg[now-1].push_back(make_pair(bef-1, D));
					edg[bef-1].push_back(make_pair(now-1, D));
				}
				bef = now;
			}
		}
		for(i=0;i<P;i++){
			//X[i]에서 시작 거리*V[i] 시간
			for(j=0;j<N;j++){ dis[j] = MAXLL;fd[j] = false;}
			dis[X[i]] = 0;
			qq.push(make_pair(0ll, X[i]));
			while(!qq.empty()){
				if (qq.size() > 5){
					j=j;
				}
				pair<long long, int> p;
				p = qq.top();
				qq.pop();
				int x, y;
				long long d, dd;
				x = p.second;
				d = -p.first;
				if (!fd[x]) {
					fd[x] = true;
					for(k=0;k<edg[x].size();k++){
						y = edg[x][k].first;
						dd = d + edg[x][k].second;
	
						if (dd < dis[y]) {
							dis[y] = dd;
							qq.push(make_pair(-dd, y));
						}
					}
				}
			}
			for(j=0;j<N;j++){
				if (dis[j] == MAXLL) {
					lte[j] = MAXLL;
				} else {
					dis[j] *= V[i];
					if (lte[j] < dis[j]) lte[j] = dis[j];
				}
			}
		}
		long long sol = MAXLL;
		for(i=0;i<N;i++){
			if(sol > lte[i]) sol = lte[i];
		}

		static int cs = 1;	
		printf("Case #%d: %lld\n", cs++, ((sol==MAXLL)?(-1ll):(sol)));
	}
	return 0;
}