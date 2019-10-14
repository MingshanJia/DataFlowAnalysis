#include<stdio.h>
#include<algorithm>
using namespace std;

__int64 a[999],b[999],s;
int h,i,n,t;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&t);
	for(h=0;h<t;h++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%I64d",&a[i]);
		sort(a,a+n);
		for(i=0;i<n;i++)
			scanf("%I64d",&b[i]);
		sort(b,b+n);
		s=0;
		for(i=0;i<n;i++)
			s+=a[i]*b[n-1-i];
		printf("Case #%d: %I64d\n",h+1,s);
	}
	return 0;
}