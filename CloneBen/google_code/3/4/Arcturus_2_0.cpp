#include <stdio.h>
#define INF 9999

struct V3{
	int x, y, z;
};

V3 holes[3];

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	
	int jcase;
	
	scanf("%d", &jcase);
	for(int icase=0; icase<jcase; icase++){
		for(int i=0; i<3; i++) scanf("%d %d %d", &holes[i].x, &holes[i].y, &holes[i].z);
		
		int min = INF;
		int max = -INF;
		for(int i=0; i<3; i++){
			if(holes[i].x < min) min = holes[i].x;
			if(holes[i].x > max) max = holes[i].x;
		}
		
		double ans = (max-min)/6.0;
		printf("Case #%d: %.7lf\n", icase+1, ans);
	}
	return 0;
	
	return 0;
}
