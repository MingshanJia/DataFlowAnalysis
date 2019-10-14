#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#define MN 200
#define ll long long
#define PI 3.1415926535897932384626433832795
using namespace std;
struct DATA {
	int a, b, p, q;
};
bool cmp(DATA a, DATA b)
{
	// a.p/a.q > b.p/b.q , a.q > 0 , b.q > 0
	return (ll)a.p*b.q > (ll)b.p*a.q;
}
int N, R, H;
int p, q, k;
double r;
int X[MN], Y[MN];
vector<DATA> a;
double help(double st, double et)
{
	double s, e, m;
	double t, x1, y1, x2, y2;
	double dx, dy, A, B, C;

	for (s = st, e = et; e-s > 1e-9;) {
		m = (s+e)/2; t = 0;
		if (p != -1) {
			dx = X[p]-X[k]; dy = Y[p]-m;
			A = dx*dx + dy*dy;
			B = 2*dx*X[k] + 2*dy*m;
			C = X[k]*X[k] + m*m - R*R;
			t = (-B+sqrt(B*B-4*A*C + 1e-6))/(2*A); // A > 0
			x1 = X[k]+dx*t; y1 = m+dy*t;
			if (y1 < 0) {x1 = -R; y1 = 0;}
		}
		else {x1 = -R; y1 = 0;}
		if (q != -1) {
			dx = X[q]-X[k]; dy = Y[q]-m;
			A = dx*dx + dy*dy;
			B = 2*dx*X[k] + 2*dy*m;
			C = X[k]*X[k] + m*m - R*R;
			t = (-B+sqrt(B*B-4*A*C + 1e-6))/(2*A); // A > 0
			x2 = X[k]+dx*t; y2 = m+dy*t;
			if (y2 < 0) {x2 = R; y2 = 0;}
		}
		else {x2 = R; y2 = 0;}

		if ((atan2(y1,x1)-atan2(y2,x2))/PI*12 >= H) e = m;
		else s = m;
	}
	return et-e;
}
int main()
{
	printf("%lf %lf %lf %lf %lf\n",atan2(0.0,1.0),atan2(1.0,1.0),atan2(1.0,0.0),atan2(1.0,-1.0),atan2(0.0,-1.0));
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	int t, T, i, j;
	DATA asdf; int dx, dy, x1, y1, x2, y2;
	int m, M, fm, fM;
	double nt;

	fscanf(in,"%d",&T);
	for (t = 1; t <= T; t++) {
		printf("Case #%d:\n",t);
		fprintf(out,"Case #%d: ",t);

		fscanf(in,"%d%d%d",&N,&R,&H);
		for (i = 0; i < N; i++)
			fscanf(in,"%d%d",&X[i],&Y[i]);
		for (i = 0; i < N; i++) {
			for (j = i+1; j < N; j++) {
				if (X[j] < X[i]) {
					swap(X[i],X[j]);
					swap(Y[i],Y[j]);
				}
			}
		}
		r = 0;
		for (k = 0; k < N; k++) {
			p = -1;
			for (i = 0; i < k; i++) {
				if (p != -1) {
					x1 = X[p]-X[k]; y1 = Y[p]-Y[k];
					x2 = X[i]-X[k]; y2 = Y[i]-Y[k];
					if (x1*y2 - y1*x2 <= 0)
						p = i;
				}
				else p = i;
			}
			q = -1;
			for (i = N-1; i >= k+1; i--) {
				if (q != -1) {
					x1 = X[q]-X[k]; y1 = Y[q]-Y[k];
					x2 = X[i]-X[k]; y2 = Y[i]-Y[k];
					if (x1*y2 - y1*x2 >= 0)
						q = i;
				}
				else q = i;
			}

			a.clear();
			for (i = 0; i < k; i++) {
				for (j = i+1; j < k; j++) {
					dx = X[j]-X[i]; dy = Y[j]-Y[i];
					asdf.a = j; asdf.b = i;
					asdf.p = dy*X[k] + (dx*Y[i]-dy*X[i]);
					asdf.q = dx;
					// 0 <= p/q <= Y[k] , q > 0
					if (0 <= asdf.p && asdf.p <= Y[k]*asdf.q)
						a.push_back(asdf);
				}
			}
			for (i = k+1; i < N; i++) {
				for (j = i+1; j < N; j++) {
					dx = X[j]-X[i]; dy = Y[j]-Y[i];
					asdf.a = i; asdf.b = j;
					asdf.p = dy*X[k] + (dx*Y[i]-dy*X[i]);
					asdf.q = dx;
					// 0 <= p/q <= Y[k]
					if (0 <= asdf.p && asdf.p <= Y[k]*asdf.q)
						a.push_back(asdf);
				}
			}
			sort(a.begin(),a.end(),cmp);
			nt = Y[k];
			for (i = 0; i < a.size(); i = j) {
				m = M = -1; fm = fM = 0;
				for (j = i; j < a.size(); j++) {
					// a[i].p/a[i].q != a[j].p/a[j].q , a[i].q > 0 , a[j].q > 0
					if ((ll)a[i].p*a[j].q != (ll)a[j].p*a[i].q) break;
					if (a[i].a < k) {
						if (M == -1 || M < a[i].a) M = a[i].a;
						if (a[i].a == p || a[i].b == p) fM = 1;
					}
					else {
						if (m == -1 || m > a[i].a) m = a[i].a;
						if (a[i].a == q || a[i].b == q) fm = 1;
					}
				}

				r += help((double)a[i].p/a[i].q,nt);
				nt = (double)a[i].p/a[i].q;

				if (M != -1 && fM) p = M;
				if (m != -1 && fm) q = m;
			}
			r += help(0.0,nt);
		}
		k = 0;
		for (i = 0; i < N; i++) k += Y[i];
		fprintf(out,"%lf\n",r/k);
	}
	return 0;
}