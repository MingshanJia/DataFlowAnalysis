#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

typedef long long LL;

map < int, LL > f[100000];
int maxv[100000];

inline LL F(int a, int b)
{
	if (a < b) b = a;
	if (b == 1) return a;
	return f[a][b];
}

LL calc1(int a, int b)
{
	if (a < b) b = a;
	if (b > maxv[a]) return -1;
	return F(a,b);
}

LL calc2(int x, int y)
{
	// find minimum a, such that F(a,y) >= x
	// f(92682,y) >= x
	
	LL a = 1;
	LL b = 92682;
	LL c;
	
	LL mid;
	while (a < b)
	{
		mid = (a+b)/2;		
		c = y;
		if (mid < c) c = mid;
		if (c > maxv[mid] || F(mid,c) >= x)
			b = mid;
		else a = mid+1;		
	}
	return a;
}

LL calc3(int x, int y)
{
	// find minimum a, such that F(y,a) >= x
	// F(y,y) >= x
	
	if (y > 92682)
	{
		if (x <= y) return 1;
		return 2;	
	}
	
	LL a = 1;
	LL b = y;
	LL c;
	
	LL mid;
	while (a < b)
	{
		mid = (a+b)/2;		
		
		c = mid;
		if (c > maxv[y] || F(y,c) >= x)
			b = mid;
		else a = mid+1;		
	}
	return a;
}

int a, b, c;
int tc, ntc;

int main()
{
	int i,j;
	f[1][1] = 1;
	maxv[1] = 1;
	for (i=2;;i++)
	{
		for (j=2; j<=i; j++)
		{
			f[i][j] = F(i-1,j-1) + F(i-1,j) + 1;
			if (f[i][j] >= ((1LL)<<32)) break;
		}
		maxv[i] = j-1;
		if (j == 2) break;		
	}	
	
	scanf("%d",&ntc);
	for (tc=1; tc<=ntc; tc++)
	{
		scanf("%d %d %d",&a,&b,&c);
		LL va, vb, vc;
		va = calc1(b,c);
		vb = calc2(a,c);
		vc = calc3(a,b);
		printf("Case #%d: ",tc);
		printf("%lld %lld %lld\n",va,vb,vc);
	}
}