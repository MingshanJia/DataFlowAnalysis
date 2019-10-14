#include <cstdio>
#include <cstdlib>
#include <string>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <cctype>
using namespace std;
#define maxn 500100
#define mod 1000000007
int nsc, sc;
long long a[maxn];
long long mas[maxn];
long long n,m, x, y, z;
long long cnt[maxn];
void init(){
	int i;
	scanf("%lld%lld%lld%lld%lld", &n, &m, &x, &y, &z);
	for(i=0;i<m;i++)
		scanf("%lld", &a[i]);
	for(i=0;i<n;i++){
		mas[i]=a[i%m];
		a[i%m]=(x*a[i%m]+y*(i+1))%z;
	}
}
void solve(){
	int i,j;
	long long res=0;
	for(i=n;i>0;i--)
		mas[i]=mas[i-1];
	cnt[0]=1;
	mas[0]=-1;
	for(i=1;i<=n;i++){
		cnt[i]=0;
		for(j=i-1;j>=0;j--)
			if (mas[i]>mas[j]){
				cnt[i]=(cnt[i]+cnt[j])%mod;
			}
		res=(res+cnt[i])%mod;
	}
	printf("Case #%d: %lld\n", sc, res);
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&nsc);
	for(sc=1; sc<=nsc; sc++){
		init();
		solve();
	}
	return 0;
}