#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
const double zero=1e-8;
const double po=acos(-1.);
int totco, n;
struct point{
	int x, y;
	int nu;
	point( int xx=0, int yy=0 ){
		x=xx; y=yy;
	}
	point operator +( const point &b )const{
		return point( x+b.x, y+b.y );
	}
	point operator -( const point &b )const{
		return point( x-b.x, y-b.y );
	}
	double operator *( const point &b )const{
		return x*b.x+y*b.y;
	}
	double operator /( const point &b )const{
		return x*b.y-y*b.x;
	}
}p[1200], conv[1200], c[1200], d[1200];

double sqr( double x ){
	return x*x;
}
bool cmp( point a, point b ){
	return ( a.y<b.y || a.y==b.y && a.x<b.x );
}
void convex(){
	sort( p, p+n, cmp );
	conv[0]=p[0]; conv[1]=p[1]; totco=2;
	for ( int i=2; i<n; i++ ){
		while ( totco>1 && (conv[totco-1]-conv[totco-2])/(p[i]-conv[totco-2])<0 ) totco--;
		conv[totco++]=p[i];
	}
	int limit=totco;
	for ( int i=n-1; i>=0; i-- ){
		while ( totco>limit && (conv[totco-1]-conv[totco-2])/(p[i]-conv[totco-2])<0 ) totco--;
		if (i!=n-1 && i!=0)
		conv[totco++]=p[i];
	}
}
int N;
int main()
{
	scanf("%d", &N);
	for (int I=1;I<=N;++I)
	{
		scanf("%d", &n);
		for (int i=0;i<n;++i)
		{
			scanf("%d%d", &p[i].x, &p[i].y);
			p[i].nu=i;
		}
		totco=0;
		convex();
		/*if (I==46)
		{
			for (int i=0;i<n;++i)
				printf("%d %d\n", p[i].x, p[i].y);
			printf("%d\n", totco);}*/
		//printf("%d\n", totco);
		int mj = 0;
		conv[totco]=conv[0];
		for (int i=0;i<totco;++i)
			mj = mj + conv[i]/conv[i+1];
		mj = abs(mj);
		point ta=conv[0], tb=conv[0];
		int tai=0, tbi=0;
		for (int i=0;i<totco;++i)
		{
			if (cmp(ta, conv[i]))
			{
				ta=conv[i];
				tai=i;
			}
			if (	cmp(conv[i], tb))
			{
				tb=conv[i];
				tbi = i;
			}
		}
		if (tai>tbi)
		{
			tai^=tbi^=tai^=tbi;
		}
		int tot = 0, totd=0;
		for (int i=tai;i<=tbi;++i)
			c[tot++]=conv[i];
		for (int i=0;i<n;++i)
		{
			bool in = false;
			for (int j=0;j<tot;++j)
				if (c[j].nu==p[i].nu)
					in=true;
			if (!in) d[totd++]=p[i];
		}
		sort(c, c+tot, cmp);
		sort(d, d+totd, cmp);
		int tmj = 0;
		for (int i=0;i<tot-1;++i)
			tmj = tmj + c[i]/c[i+1];
		tmj = tmj + c[tot-1]/d[totd-1];
		tmj = tmj + d[0]/c[0];
		for (int j=totd-1;j>=1;--j)
			tmj = tmj+d[j]/d[j-1];
		printf("Case #%d:", I);
		if (tmj*2>mj)
		{
			//printf("%d %d\n", tot, totd);
			for (int i=0;i<tot;++i)
				printf(" %d", c[i].nu);
			for (int i=totd-1;i>=0;--i)
				printf(" %d", d[i].nu);
			printf("\n");
			continue;
		}
		tot = 0, totd=0;
		for (int i=tbi;i!=tai;i = (i+1)%totco)
			c[tot++]=conv[i];
		c[tot++]=conv[tai];
		for (int i=0;i<n;++i)
		{
			bool in = false;
			for (int j=0;j<tot;++j)
				if (c[j].nu==p[i].nu)
					in=true;
			if (!in) d[totd++]=p[i];
		}
		tmj = abs(tmj);
		sort(c, c+tot, cmp);
		sort(d, d+totd, cmp);
		tmj = 0;
		for (int i=0;i<tot-1;++i)
			tmj = tmj + c[i]/c[i+1];
		tmj = tmj + c[tot-1]/d[totd-1];
		tmj = tmj + d[0]/c[0];
		for (int j=totd-1;j>=1;--j)
			tmj = tmj+d[j]/d[j-1];
		tmj = abs(tmj);
		if (tmj*2>mj)
		{
			//printf("%d %d\n", tot, totd);
			for (int i=0;i<tot;++i)
				printf(" %d", c[i].nu);
			for (int i=totd-1;i>=0;--i)
				printf(" %d", d[i].nu);
			printf("\n");
			continue;
		}
	}
}
