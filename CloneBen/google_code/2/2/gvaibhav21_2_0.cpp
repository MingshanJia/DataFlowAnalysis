#include<bits/stdc++.h>
#include <unistd.h>
using namespace std;

#define sd(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
#define sl(a) scanf("%lld",&a)
#define clr(a) memset(a,0,sizeof(a))
#define debug(a) printf("check%d\n",a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
#define N 110
#define INF 10000000
int d[N][N];

int main()
{
	// freopen("C.in","r",stdin);
	// freopen("C.out","w",stdout);
	int t;
	sd(t);
	for(int tt=1;tt<=t;tt++)
	{
		int n,m,i,j,k,p;
		sd(n);sd(m);sd(p);
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
				d[i][j]=INF;
			d[i][i]=0;
		}
		for(i=0;i<m;i++)
		{
			int x,y,z;
			sd(x);sd(y);sd(z);
			d[x][y]=d[y][x]=z;
		}
		for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		int s1=0, s2=0;
		for(i=1;i<=n;i++)
			s2 += d[1][i];
		for(i=2;i<=n;i++)
		for(j=1;j<=n;j++)
			s1 += d[i][j];
		double p_1 = p-1, r = -1.0/(n-1);
		p_1 = p_1 + (1.0/(n-1))*(1-pow(r,p-2))/(1-r);
		if(p%2==0)	p_1 = p_1 + pow(1.0/(n-1),p-1);
		else		p_1 = p_1 - pow(1.0/(n-1),p-1);
		p_1 = (p_1*(n-1))/n;
		double p_2 = p - p_1;
		double ans = (p_1*s1)/((n-1)*(n-1)) + (p_2*s2)/(n-1);
		printf("Case #%d: %.9lf\n",tt,ans);
	}
}