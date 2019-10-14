#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define upperlimit 1000100
#define INF 1000000100
#define INFL 1000000000000000100
#define eps 1e-8
#define endl '\n'
#define sd(n) scanf("%d",&n)
#define slld(n) scanf("%lld",&n)
#define pd(n) printf("%d",n)
#define plld(n) printf("%lld",n)
#define pds(n) printf("%d ",n)
#define pllds(n) printf("%lld ",n)
#define pdn(n) printf("%d\n",n)
#define plldn(n) printf("%lld\n",n)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define F first
#define S second
#define clr(a) memset(a,0,sizeof(a))

using namespace std;

ll gcd(ll n1,ll n2){
	if(!n1)return n2;
	if(!n2)return n1;
	if(n1%n2==0)return n2;
	return gcd(n2,n1%n2);
}
ll powmod(ll base,ll exponent)
{
	base%=mod;
	ll ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base)%mod;
		base=(base*base)%mod;
		exponent/=2;
	}
	ans%=mod;
	return ans;
}
char arr[51][51];
int main()
{
	 freopen("C-small-attempt1.in","r",stdin);
	 freopen("C_small_out.txt","w",stdout);

	int t,i,j,n,d,k;
	sd(t);
	for(int tt=1;tt<=t;tt++){
		sd(d);
		sd(n);
		printf("Case #%d:\n",tt);
		for(i=1;i<=20;i++)for(j=1;j<=d;j++)arr[i][j]='O';
		for(i=1;i<=20/5;i++)for(j=1;j<=d/5;j++){
			arr[3+(i-1)*5][3+(j-1)*5]='I';
		}
		for(i=1;i<=20/5;i++)for(j=1;j<=(d/5);j++){
			if(n){
				arr[2+(i-1)*5][2+(j-1)*5]='/';
				n--;
			}
			if(n){
				arr[2+(i-1)*5][3+(j-1)*5]='/';
				n--;
			}
			if(n){
				arr[2+(i-1)*5][4+(j-1)*5]='/';
				n--;
			}
			if(n){
				arr[3+(i-1)*5][2+(j-1)*5]='/';
				n--;
			}
			if(n){
				arr[3+(i-1)*5][4+(j-1)*5]='/';
				n--;
			}
			if(n){
				arr[4+(i-1)*5][2+(j-1)*5]='/';
				n--;
			}
			if(n){
				arr[4+(i-1)*5][3+(j-1)*5]='/';
				n--;
			}
			if(n){
				arr[4+(i-1)*5][4+(j-1)*5]='/';
				n--;
			}
		}
		for(i=1;i<=20;i++){
			for(j=1;j<=d;j++)cout<<arr[i][j];
			cout<<endl;
		}
	}
	return 0;
}
