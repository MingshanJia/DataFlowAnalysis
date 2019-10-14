#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int T,TN,N,R,H,all;
double sum;

struct Z{
	int x,y;
	bool operator < (const Z &b)const{
		return x<b.x;
	}
} A[201];

int main()
{
	int i,j,k,t;
	double h,s,e,m,a,b,x,maxx,y1,minx,y2,s1,s2;
	freopen("input.txt","r",stdin), freopen("output.txt","w",stdout);
	for (scanf("%d",&T);T--;){
		scanf("%d%d%d",&N,&R,&H); sum = all = 0;
		for (i=1;i<=N;i++){
			scanf("%d%d",&A[i].x,&A[i].y);
			all += A[i].y;
		}
		sort(A+1,A+N+1);
		for (i=1;i<=N;i++){
			s = 0, e = A[i].y;
			h = A[i].y;
			for (t=100;t--;){
				m = (s+e)/2;
				maxx = -R;
				minx = R;
				for (j=1;j<i;j++){
					a = (m-A[j].y)/(A[i].x-A[j].x);
					b = A[j].y-a*A[j].x;
					x = (-a*b-sqrt(a*a*b*b-(a*a+1)*(b*b-R*R)))/(a*a+1);
					if (a*x+b >= 0 && maxx < x) maxx = x;
				}
				for (j=i+1;j<=N;j++){
					a = (m-A[j].y)/(A[i].x-A[j].x);
					b = A[j].y-a*A[j].x;
					x = (-a*b+sqrt(a*a*b*b-(a*a+1)*(b*b-R*R)))/(a*a+1);
					if (a*x+b >= 0 && minx > x) minx = x;
				}

				y1 = sqrt(R*R-maxx*maxx);
				y2 = sqrt(R*R-minx*minx);

				s1 = atan2(y1,maxx);
				s2 = atan2(y2,minx);

				if (s1-s2 >= 3.14159265*H/12.) e = m, h = m;
				else s = m;
			}
			sum += A[i].y-m;
		}
		printf("Case #%d: %.8lf\n",++TN,sum/all);
	}
}