#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 2147483648

using namespace std;

int n,p,m,fr[110][2];
unsigned int d[110][10010],f[10010];
vector<int> g[10010], cost[10010];
priority_queue< pair<int, int> > heap;

void dijk(int x){
	int i;
	for(i=0;i<n;i++){
		d[x][i]=INF; f[i]=0;
	}
	d[x][fr[x][0]]=0;
	while(!heap.empty()) heap.pop();
	pair<int, int> tp;
	heap.push(make_pair(0,fr[x][0]));
	int xx,yy,zz;
	while(!heap.empty()){
		tp=heap.top();
		heap.pop();
		if(f[tp.second]==1) continue;
		xx=tp.second;
		f[xx]=1;
		for(i=0;i<g[xx].size();i++){
			yy=g[xx][i]; zz=cost[xx][i];
			if(zz>=INF || (d[x][xx]==INF && zz>0)) continue;
			if(d[x][xx]+zz<d[x][yy]){
				d[x][yy]=d[x][xx]+zz;
				heap.push(make_pair(-d[x][yy],yy));
			}
		}
	}
}

void process(){
	int i,j;
	for(i=0;i<p;i++){
		dijk(i);
	}
	unsigned int ans=INF,maxdis,x;
	for(i=0;i<n;i++){
		maxdis=0;
		for(j=0;j<p;j++){
			if(d[j][i]==INF){
				x=INF;
			}
			else if((long long)fr[j][1]*(long long)d[j][i]>=INF){
				x=INF;
			}
			else x=fr[j][1]*d[j][i];
			if(x>maxdis) maxdis=x;
		}
		if(maxdis<ans) ans=maxdis;
	}
	if(ans==INF) printf("-1\n");
	else printf("%d\n",(int)ans);
}

void initiate(){
	int i;
	for(i=0;i<n;i++){
		g[i].clear();
		cost[i].clear();
	}
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,i,j,k,di,li,ci[200];
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d%d%d",&n,&p,&m);
		for(j=0;j<p;j++){
			scanf("%d%d",&fr[j][0],&fr[j][1]);
			fr[j][0]--;
		}
		for(k=0;k<m;k++){
			scanf("%d%d",&di,&li);
			for(j=0;j<li;j++){
				scanf("%d",&ci[j]);
				ci[j]--;
			}
			for(j=0;j<li-1;j++){
				g[ci[j]].push_back(ci[j+1]);
				g[ci[j+1]].push_back(ci[j]);
				cost[ci[j]].push_back(di);
				cost[ci[j+1]].push_back(di);
			}
		}
		printf("Case #%d: ",i);
		process();
		initiate();
	}
	return 0;
}