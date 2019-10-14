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

double x[3];

int main()
{
	// freopen("C.in","r",stdin);
	// freopen("C.out","w",stdout);
	int t;
	sd(t);
	for(int tt=1;tt<=t;tt++)
	{
		int n,y,z;
		scanf("%lf",&x[0]);
		sd(y);sd(z);
		scanf("%lf",&x[1]);
		sd(y);sd(z);
		scanf("%lf",&x[2]);
		sd(y);sd(z);
		sort(x,x+3);
		double r=(x[2]-x[0])/6;
		printf("Case #%d: %.9lf\n",tt,r);
	}
}