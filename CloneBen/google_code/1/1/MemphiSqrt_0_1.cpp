#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int N=200005;

int n,a[N],b[N];

void solve(){
	scanf("%d",&n);
	memset(b,0,sizeof(b));
	rep(i,1,n) scanf("%d",a+i);
	long long ans=0;
	rep(i,1,n){
		rep(j,i+1,n){
			long long x=(long long)a[i]*a[j];
			if(a[i]==0 || a[j]==0){
				if(a[i]==0 && a[j]==0)
					ans+=i-1;
				else ans+=b[0];
				continue;
			}
			if(x<=200000) ans+=b[x];
			if(a[i]==1 || a[j]==1) continue;
			if(a[i]%a[j]==0){
				int y=a[i]/a[j];
				ans+=b[y];
			}
			if(a[j]%a[i]==0 && a[i]!=a[j]){
				int z=a[j]/a[i];
				ans+=b[z];
			}
		}
		b[a[i]]++;
	}
	printf("%lld\n",ans);
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
