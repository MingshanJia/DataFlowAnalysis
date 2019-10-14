#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
pii traps[20];
ll ts[20];
bool vt[110][110];
//ll blank[220];
ll v[110][110];
int n,m;
ll dfs(int a,int b){
	//if(0>a||0>b||a>=n||b>=m)return 0;
	if(vt[a][b]||v[a][b]<0)return 0;
	vt[a][b]=1;
	ll ans=v[a][b];
	ans+=dfs(a+1,b);
	ans+=dfs(a-1,b);
	ans+=dfs(a,b+1);
	ans+=dfs(a,b-1);
	return ans;
}
const int N=(1<<16)+100; 
ll earn[N];
bool able[N];
bool ra[N];
//ll mon[N];
int main(){
	int T;
	scanf("%d",&T);
	for(int iid=1;iid<=T;iid++){
		int e;
		int tc=0;
		pii s;
		pii t;
		memset(v,-1,sizeof v);
		//memset(blank,-1,sizeof blank);
		scanf("%d%d%d %d%d %d%d",&n,&m,&e,&(s.first),&(s.second),&(t.first),&(t.second));
		//s.first--;t.first--;s.second--;t.second--;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ll d;
				scanf("%lld",&d);
				v[i][j]=d;
				if(d<0&&d!=-100000){
					ts[tc]=-d;
					traps[tc++]=make_pair(i,j);
				}
			}
		}
		//printf("%d\n",tc);
		int all=(1<<tc)-1;
		for(int i=0;i<=all;i++){
			ll red=0;
			for(int j=0;j<tc;j++)if((1<<j)&i){
				red+=ts[j];
				v[traps[j].first][traps[j].second]=0;
			}else{
				v[traps[j].first][traps[j].second]=-100000;
			}
			memset(vt,0,sizeof vt);
			earn[i]=dfs(s.first,s.second)+e-red;
			able[i]=vt[t.first][t.second];
			//printf("%d %d\n",i,able[i]);
		}
		memset(ra,0,sizeof ra);
		//memset(mon,0,sizeof mon);
		ra[0]=1;//mon[0]=earn[0];
		ll ans=-1;
		for(int i=0;i<=all;i++)if(ra[i]){
			//mon[i]+=earn[i];
			for(int j=0;j<tc;j++)if(!((1<<j)&i)){
				if(earn[i]>=ts[j]){
					int nxt=i|(1<<j);
					ra[nxt]=1;
					//mon[nxt]=max(mon[nxt],earn[nxt]);
				}
			}
			if(able[i]){
				if(ans==-1)ans=earn[i];
				else if(ans<earn[i])ans=earn[i];
			}
		}
		printf("Case #%d: %lld\n",iid,ans);
	}
} 
