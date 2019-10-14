#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <queue>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define MP make_pair
#define ST first
#define ND second
#define PB push_back
#define FOR(i,a,b) for( int i=(a); i<(b); ++i)
#define FORD(i,a,b) for( int i=(a); i>(b); --i)
#define REP(i,n) for(int i=0; i<(n); ++i)
#define ALL(X) (X).begin(),(X).end()
#define SZ(X) (int)(X).size()
#define FORE(it,X) for(__typeof((X).begin()) it=(X).begin(); it!=(X).end();++it)

int n,H;
double R;
int x[256],y[256];
double pi=acos(-1.0);

double angle(double x,double y) //-3.14 부터 3.14까지 리턴
{
    return atan2(y,x); //*180.0/acos(-1.0); //도로 바꾸려면
}

#define sq(x) ((x)*(x))

void g(double& x1,double& y1, double& x2, double& y2)
{
	double x3,y3;
	REP(qq,200) {
		x3=(x1+x2)/2.0;
		y3=(y1+y2)/2.0;

		if (sq(x3)+sq(y3) > sq(R))
			x2=x3,y2=y3;
		else
			x1=x3,y1=y3;
	}
}

double f(int v,double h)
{
	double l=1e100;
	double r=-1e100;

	REP(i,n+2) {
		if (x[v]==x[i]) continue;
		double dx=x[v]-x[i];
		double dy=h-y[i];
		if (x[i]<x[v])
			l=min(l,dy/dx);
		if (x[v]<x[i])
			r=max(r,dy/dx);
	}

	double a1,a2;
	double x1,y1,x2,y2;
	x1=x[v]; y1=h;
	x2=x[v]-2*R; y2=h+(-2*R)*l;
	//cout<<x1<<" "<<y1<<endl;
	//cout<<x2<<" "<<y2<<endl;
	
	g(x1,y1,x2,y2);
	a1=angle(x1,y1);
	double lx,ly,rx,ry;
	lx=x1;
	ly=y1;

	x1=x[v]; y1=h;
	x2=x[v]+2*R; y2=h+(2*R)*r;
	//cout<<x1<<" "<<y1<<endl;
	//cout<<x2<<" "<<y2<<endl;
	g(x1,y1,x2,y2);
	a2=angle(x1,y1);
	rx=x1;
	ry=y1;

	while (a2<a1) a2+=pi*2;
	while (a1<a2) a1+=pi*2;
	if (a1>a2) swap(a2,a1);

	double ret=(a2-a1)/pi*12;
	if (ret < 0 || ret > 12+1e-7)
	{
		cout<<"left : "<<lx<<" "<<ly<<endl;
		cout<<"right : "<<rx<<" "<<ry<<endl;

		cout<<"l : "<<l<<endl;
		cout<<"r : "<<r<<endl;
		cout<<"v : "<<v<<endl;
		cout<<"h : "<<h<<endl;
		cout<<"a1 : "<<a1<<endl;
		cout<<"a2 : "<<a2<<endl;
		assert(0);
	}
//	cout<<"ret : "<<ret<<endl;
	return ret;
}

int main()
{
	int tn;
	cin>>tn;

	/*cout<<angle(1,0)<<endl;
	cout<<angle(1,-1)<<endl;;
	cout<<angle(0,-1)<<endl;
	cout<<angle(-1,-1)<<endl;
	cout<<angle(-1,0)<<endl;
	cout<<angle(-1,1)<<endl;
	cout<<angle(0,1)<<endl;
	cout<<angle(1,1)<<endl;
*/
	while (tn--) {
		cin>>n>>R>>H;

		double tot=0;
		REP(i,n) {
			cin>>x[i]>>y[i];
			tot+=y[i];
		}
		x[n]=-R;
		y[n]=0;
		x[n+1]=R;
		y[n+1]=0;

		double s=0;
		REP(i,n) {
			double l=0,r=y[i];
			REP(qq,200) {
				double m=(l+r)/2.0;
				if (f(i,m)>=H)
					r=m;
				else
					l=m;
			}
			double m=(l+r)/2.0;
			s+=y[i]-m;
		}

		static int qq=0;
		printf("Case #%d: %.8f\n",++qq,s/tot);
	}
	return 0;
}
