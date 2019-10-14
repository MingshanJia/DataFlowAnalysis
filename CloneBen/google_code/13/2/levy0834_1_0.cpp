#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std;

#pragma comment(linker, "/STACK:36777216")
#define INF 0x7fffffff;
typedef long long LL;

#define g 9.8
#define PI acos(-1.0)

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T,cs,n,i;
	double v,d;
	scanf("%d",&T);
	for(cs=1;cs<=T;cs++)
	{
		scanf("%lf%lf",&v,&d);
		double s=d*g/v/v;
		if(s>1.0)
			s=1.0;
		printf("Case #%d: ",cs);
		double ans=asin(s)/2;
		printf("%.8lf\n",ans*180.0/PI);
	}
}