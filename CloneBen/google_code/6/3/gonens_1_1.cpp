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
int s[5100000],n;
char str[5100000];
int get(int l,int r){
	return s[r]-s[l-1];
}
void solved(){
	n=read();
	scanf("%s",str);
	s[0]=0;
	rep(i,1,n)s[i]=s[i-1]+(str[i-1]-'0');
	int Max=0;
	rep(i,1,n){
		int l1=i-1,l2=n-i;
		if((l1&1)==1 && (l2&1)==1){
			int s1=get(i-(l1+1)/2,i-1)+get(i+1,i+l2/2);
			int s2=get(i-l1/2,i-1)+get(i+1,i+(l2+1)/2);
			Max=max(Max,s[i]-s[i-1]+min(s1,s2));
		}
		else{
			int s1=get(i-l1/2,i-1)+get(i+1,i+l2/2);
			Max=max(Max,s[i]-s[i-1]+s1);
		}
	}
	cout<<Max<<endl;
}
int main(){
	//freopen("B-large.in.txt","r",stdin);
	//freopen("B2.out","w",stdout);
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