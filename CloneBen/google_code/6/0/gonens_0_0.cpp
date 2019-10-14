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
ll dp[51][5100];
int son[5100][2],flag[5100];
int n,m,nn,root;
char str[100];
int New(){
	++nn;
	son[nn][0]=son[nn][1]=flag[nn]=0;
	return nn;
}
void solved(){
	memset(dp,0,sizeof dp);
	memset(son,0,sizeof son);
	memset(flag,0,sizeof flag);
	
	n=read();m=read();
	nn=0;
	root=New();
	while(m--){
		scanf("%s",str);
		int t=root;
		int len=strlen(str);
		rep(i,0,len-1){
			int kk=str[i]=='B';
			if(!son[t][kk])son[t][kk]=New();
			t=son[t][kk];
		}
		flag[t]=1;
	}
	son[0][0]=son[0][1]=flag[0]=0;
	dp[0][1]=1;
	rep(i,0,n-1)
		rep(j,0,nn)
			if(!flag[j] && dp[i][j]>0){
				rep(k,0,1)
					if(!flag[son[j][k]])dp[i+1][son[j][k]]+=dp[i][j];
			}
	ll ans=0;
	rep(j,0,nn)
		if(!flag[j])ans+=dp[n][j];
	cout<<ans<<endl;

}
int main(){
	//freopen("A-small-attempt0.in.txt","r",stdin);
	//freopen("A.out","w",stdout);
	//freopen("A-large-practice.in.txt","r",stdin);
	//freopen("A-large.out","w",stdout);
	int T=read();
	int tot=0;
	while(T--){
		tot++;
		printf("Case #%d: ",tot);
		solved();
	}
	return 0;
}