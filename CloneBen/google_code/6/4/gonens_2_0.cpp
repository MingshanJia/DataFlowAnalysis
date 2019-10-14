#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<locale>  
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const double pi=acos(-1);
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define Rep(i,u) for(int i=head[u];i;i=Next[i])
#define clr(a) memset(a,0,sizeof a)
#define pb push_back
#define mp make_pair
ld eps=1e-9;
ll pp=1000000007;
ll mo(ll a,ll pp){if(a>=0 && a<pp)return a;a%=pp;if(a<0)a+=pp;return a;}
ll powmod(ll a,ll b,ll pp){ll ans=1;for(;b;b>>=1,a=mo(a*a,pp))if(b&1)ans=mo(ans*a,pp);return ans;}
ll read(){
	ll ans=0;
	char last=' ',ch=getchar();
	while(ch<'0' || ch>'9')last=ch,ch=getchar();
	while(ch>='0' && ch<='9')ans=ans*10+ch-'0',ch=getchar();
	if(last=='-')ans=-ans;
	return ans;
}
//head
#define N 210000
ll b[N],b2[N],inv[N];
ll C(int n,int m){
	if(m>n)return 0;
	if(m==0 || m==n)return 1;
	return b[n]*inv[n-m]%pp*inv[m]%pp;
}
void solved(){
	int n=read(),m=read();
	ll ans=0;
	rep(i,0,m){
		ll kk=1;
		if(i&1)kk=-1;
		ll tmp=C(m,i)*b2[i]%pp*b[2*n-i]%pp;
		ans=((ans+tmp*kk)%pp+pp)%pp;
	}
	cout<<ans<<endl;
}
int main(){
	//freopen("3.in","r",stdin);
	//freopen("C-small-attempt1.in.txt","r",stdin);
	//freopen("C1.out","w",stdout);
	b[0]=1;
	b2[0]=1;
	rep(i,1,200000)b[i]=b[i-1]*i%pp,b2[i]=b2[i-1]*2%pp;
	rep(i,0,200000)inv[i]=powmod(b[i],pp-2,pp);
	int T=read();
	int tot=0;
	while(T--){
		tot++;
		printf("Case #%d: ",tot);
		solved();
	}
	return 0;
}