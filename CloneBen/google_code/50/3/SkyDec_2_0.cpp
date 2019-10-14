#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define pb push_back
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
int T,Cas,n;
bool ch(char p){
	return (p<='z'&&p>='a');
}
int go[110000][27];int tot;
int num[110000];int code;
vector<int>dan[23];
int bel[23];
int cho=0;
int bc[310000];
int u1[310000];
int hav[1010000];
int work(int st){
	int ans=0;
	rep(i,1,code){
		int v=(hav[i]&st);
		if(v!=0&&v!=hav[i])ans++;
	}
	return ans;
}
void work(){
	rep(i,1,tot)rep(j,0,25)go[i][j]=0;
	rep(i,1,tot)num[i]=0;
	rep(i,1,code)hav[i]=0;
	code=0;
	tot=1;
	scanf("%d",&n);
	rep(i,1,n)dan[i].clear();
	rep(i,1,n){
		char p=getchar();
		while(!ch(p))p=getchar();
		while(1){
			int now=1;
			while(ch(p)){
				if(!go[now][p-'a'])go[now][p-'a']=++tot;
				now=go[now][p-'a'];
				p=getchar();
			}
			if(num[now])dan[i].pb(num[now]);
			else dan[i].pb(num[now]=++code);
			hav[num[now]]|=(1<<(i-1));
			if(p!=' ')break;
			p=getchar();
		}
	}
	int ans=2333333;
	rep(i,0,(1<<n)-1)
	if((i&1)&&((i&2)==0)){
		ans=min(ans,work(i));
	}
	printf("Case #%d: %d\n",Cas,ans);
}
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&T);
	for(Cas=1;Cas<=T;Cas++){
		work();
	}
	return 0;
}


