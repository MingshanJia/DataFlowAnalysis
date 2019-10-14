#include<bits/stdc++.h>
#define N 200005
using namespace std;
int fac[N],inv[N],two[N],n,m,ans;
const int P=1e9+7;
int C(int n,int m){return 1ll*fac[n]*inv[m]%P*inv[n-m]%P;}
int Pow(int a,int b){
	int ret=1;
	for (;b;b>>=1,a=1ll*a*a%P)
		if (b&1) ret=1ll*ret*a%P;
	return ret;
}
int main(){
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	n=100000;
	fac[0]=1;for (int i=1;i<=2*n;i++) fac[i]=1ll*fac[i-1]*i%P;
	inv[2*n]=Pow(fac[2*n],P-2);
	for (int i=2*n-1;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%P;
	two[0]=1;for (int i=1;i<=2*n;i++) two[i]=1ll*two[i-1]*2%P;
	int T,Case=0;scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		int ans=0;
		for (int i=0,sign=1;i<=m;sign*=-1,i++){
			int cur=1ll*C(m,i)*two[i]%P*fac[2*n-i]%P;
			cur*=sign;ans+=cur;
			if (ans<0) ans+=P;
			if (ans>=P) ans-=P;
		}
		printf("Case #%d: %d\n",++Case,ans);
	}
}
