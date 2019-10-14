#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define upperlimit 1000100
#define INF 1000000100
#define INFL 1000000000000000100
#define eps 1e-9
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
ll arr[52][52];
ll dist[52][52];
int n;
double solve(int i,int j,double x){
    double ret=0;
    for(int k=1;k<=n;k++)ret=max(ret,min(dist[i][k]+x,dist[j][k]+arr[i][j]-x));
    return ret;
}
int main()
{
	 freopen("D-small-attempt1.in","r",stdin);
	 freopen("D_small_out.txt","w",stdout);

	int t,i,j,k;
	sd(t);
	for(int tt=1;tt<=t;tt++){
		sd(n);
		for(i=1;i<=n;i++)arr[i][i]=0;
		for(i=2;i<=n;i++){
			for(j=1;j<i;j++){
				slld(arr[i][j]);
				arr[j][i]=arr[i][j];
			}
		}
		printf("Case #%d: ",tt);
		for(i=1;i<=n;i++)for(j=1;j<=n;j++){
			if(arr[i][j]==-1)arr[i][j]=INFL;
			dist[i][j]=arr[i][j];
		}
		for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		double answer=INFL;
		for(i=1;i<=n;i++){
			double temp=0;
			for(j=1;j<=n;j++)temp=max(temp,1.0*dist[i][j]);
			answer=min(answer,temp);
		}
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(arr[i][j]!=INFL && i!=j){
			double l=0,r=arr[i][j],l1,r1;
			while(r-l>eps){
                l1=(2*l+r)/3;
                r1=(l+2*r)/3;
                if(solve(i,j,l1)>solve(i,j,r1))l=l1;
                else r=r1;
			}
			double x=(l+r)/2;
//			cout<<i<<" "<<j<<" "<<x<<" "<<solve(i,j,x)<<endl;
			answer=min(answer,solve(i,j,x));
		}
		printf("%.10f\n",answer);
	}
	return 0;
}
