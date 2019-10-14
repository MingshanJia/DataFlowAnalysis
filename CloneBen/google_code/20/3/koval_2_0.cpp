#include <stdio.h>
#include <vector>


int t,T;

int n,m,p;

#define P 105
#define N 10005

int x[P],v[P];

long long ans[N];
long long D[N];

std::vector<std::pair<int,int> > ege[N];


void call(int city,int latency,long long ans){
	if (D[city] > ans){
		D[city] = ans;
		for (int i=0;i<ege[city].size();++i){
			int dest = ege[city][i].first;
			int dist = ege[city][i].second;
			call(dest,latency,ans + (long long)latency*dist);
		}
	}
}

int main(){
	freopen("c-small.in","rt",stdin);
	freopen("c-small.out","wt",stdout);
	scanf("%d",&T);
	for (t=1;t<=T;++t){
		scanf("%d %d %d",&n,&p,&m);
		int i;

		
		for (int i=1;i<=n;++i){
			ege[i].clear();
			ans[i] = 0;
		}

		for (int i=1;i<=p;++i){
			scanf("%d %d",&x[i],&v[i]);
		}
		for (int i=1;i<=m;++i){
			int l,dist;
			scanf("%d",&dist);
			scanf("%d",&l);
			int previous,now;
			for (int j=0;j<l;++j){
				scanf("%d",&now);
				if (j){
					ege[now].push_back(std::make_pair(previous, dist) );
					ege[previous].push_back(std::make_pair(now, dist) );
				}
				previous = now;
			}
		}

		for (int i=1;i<=p;++i){
			for (int j=1;j<=n;++j){
				D[j] = 10000000000LL;
			}
			call(x[i],v[i],0);
			for (int j=1;j<=n;++j){
				ans[j] = std::max(ans[j],D[j]);
			}
		}
		long long answer = 10000000000LL;
		for (int i=1;i<=n;++i){
			if (answer > ans[i])
				answer = ans[i];
		}
		if (answer == 10000000000LL){
			answer = -1;
		}
		printf("Case #%d: %lld\n",t,answer);
	}
	return 0;
}