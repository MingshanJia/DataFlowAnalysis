#include <math.h>
#include <stdio.h>

double G =9.8;
double V,D;
double pi = acos(-1.0);
double calcD(double theta){
	double v = -V*sin(theta);
	double t = -2*v/G;
	return t*V*cos(theta);
}

int main(){
	int tt,tcas = 1;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&tt);
	while(tt--){
		scanf("%lf%lf",&V,&D);
		double left = 0, right = pi/2, mid1, mid2;
		int tot = 10000;
		while(tot--&&left<right){
			mid1 = left+ (right-left)/3;
			mid2 = left+ 2*(right-left)/3;
			double val1 = calcD(mid1);
			double val2 = calcD(mid2);
			if (val1<val2)
				left = mid1;
			else right = mid2;
		}
		right = left;
		left = 0;
		tot = 10000;
		double mid;
		while(tot--&&left<right){
			mid = (left+right)/2;
			double val = calcD(mid);
			if (val<D)
				left = mid;
			else right = mid;
		}
		printf("Case #%d: %.9lf\n",tcas++, left*360/2/pi);
	}
}

