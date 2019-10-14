#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int N=105;
const int M=100005;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};

int n,m,e,s,t,S,T;
int a[N][N],px[N],py[N],cp;
int b[N][N],gain[M],f[M];
bool vk[M];
bool vis[N][N];

int dfs(int x,int y){
	if(vis[x][y] || b[x][y]<0) return 0;
	vis[x][y]=1;
	//printf("%d %d\n",x,y);
	int ans=b[x][y];
	rep(i,0,3){
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<1 || xx>n || yy<1 || yy>m) continue;
		ans+=dfs(xx,yy);
	}
	return ans;
}

void solve(){
	int mn=-100000;
	scanf("%d%d%d%d%d%d%d",&n,&m,&e,&s,&t,&S,&T);
	rep(i,1,n) rep(j,1,m) scanf("%d",a[i]+j);
	cp=0;
	rep(i,1,n) rep(j,1,m) if(a[i][j]>mn && a[i][j]<0) {
		px[cp]=i;
		py[cp]=j;
		cp++;
	}
	
	int top=(1<<cp)-1;
	for(int i=0;i<=top;++i){
		rep(j,1,n) rep(k,1,m) b[j][k]=a[j][k];
		for(int j=0;j<cp;j++) if(i&(1<<j)){	
			b[px[j]][py[j]]=0;
		}
		rep(j,1,n) rep(k,1,m) vis[j][k]=0;
		gain[i]=dfs(s,t);
		//printf("%d\n",gain[i]);
		//exit(0);
		f[i]=-1;
		if(vis[S][T]) vk[i]=1;
		else vk[i]=0;
		//printf("%d\n",vk[i]);
	}
	f[0]=e+gain[0];
	int ans=-1;
	for(int i=0;i<=top;++i){
		for(int j=0;j<cp;j++) if((i&(1<<j))==0){
			int s=i|(1<<j);
			if(f[i]>=-a[px[j]][py[j]]){
				f[s]=max(f[s],f[i]+a[px[j]][py[j]]+(gain[s]-gain[i]));
				if(f[s]<0){
					puts("!!!");
					exit(0);
				}
			}
		}
		if(vk[i]) ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	//exit(0);
}

int main(){
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	
	int c;
	scanf("%d",&c);
	rep(i,1,c){
		printf("Case #%d: ", i);
		solve();
	}
}
