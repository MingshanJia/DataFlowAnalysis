#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

const double PI = 3.1415926535897932384626433832795;
int T,Case;
int N; double R,H,X[222],Y[222],A,L;

bool good(int i, double x, double y)
{
	int j; double a=0,b=0,p,q,r,vxa,vya,vxb,vyb;
	for (j=0;j<N;j++) if (j != i){
		p = (y - Y[j]);
		q = (X[j] - x);
		r = x * Y[j] - X[j] * y;
		vya = ((-1) * q * r + sqrt(p * p * (p * p + q * q) * R * R - p * p * r * r)) / (p * p + q * q);
		vxa = -(q * vya + r) / p;
		vyb = ((-1) * q * r - sqrt(p * p * (p * p + q * q) * R * R - p * p * r * r)) / (p * p + q * q);
		vxb = -(q * vyb + r) / p;

		if (X[j] < x){
			if (vxa < x) a = max(a,atan2(vya,-vxa));
			else a = max(a,atan2(vyb,-vxb));
		}
		else{
			if (vxa > x) b = max(b,atan2(vya,vxa));
			else b = max(b,atan2(vyb,vxb));
		}
	}

	double ret = (PI - a - b) / PI;
	return 12 * ret >= H;
}

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int i,j;

	scanf ("%d",&T); while (T--){
		scanf ("%d %lf %lf",&N,&R,&H); A = L = 0;
		for (i=0;i<N;i++) scanf ("%lf %lf",&X[i],&Y[i]), L += Y[i];
		for (i=0;i<N;i++){
			double l = 0, r = Y[i], m; j = 50;
			while (j--){
				m = (l + r) / 2;
				if (good(i,X[i],m)) r = m;
				else l = m;
			}
			A += Y[i] - m;
		}

		printf ("Case #%d: %.7lf\n",++Case,A/L);
	}
	return 0;
}