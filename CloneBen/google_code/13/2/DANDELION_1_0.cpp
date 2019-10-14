#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include <hash_map>
#include <string>
#include<cmath>
using namespace std;
//#define TEST_SMALL
#define TEST_BIG
#define pi  3.14159265
int main(){

#ifndef TEST_SMALL
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("Bs1.out", "w", stdout);
#endif
#ifndef TEST_BIG
	freopen("B-large-practice.in", "r", stdin);
	freopen("Bl.out", "w", stdout);
#endif	
	int cas;
	int n;
	scanf("%d", &cas);
	for(int t = 1; t <= cas; t++){
		double v, d, ans;
		scanf("%lf%lf", &v, &d);
		if (fabs(d) < 0.00001)
			ans = 90.00000000;
		else{
		//ans = asin(1.0);
		double t = d/v*9.8/v;
		
		ans = asin(t > 1 ? 1: t)*180/pi;
		ans /= 2;
		}
		printf("Case #%d: %.7lf\n", t, ans);
	
	
	}
}