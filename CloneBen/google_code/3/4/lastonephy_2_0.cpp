#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 100010
#define LL long long
using namespace std;

struct NODE{
	int x, y, z;
	bool operator<(const struct NODE &a)const{
		return x < a.x;
	}
}nodes[3];

bool judge(double x){
	double c1 = nodes[0].x + x;
	double c2 = c1 + x + x;
	double c3 = c2 + x + x;
	if (nodes[1].x >= c1 - x && nodes[1].x <= c3 + x){
		if (nodes[2].x >= c1 - x && nodes[2].x <= c3 + x){
			return true;
		}
	}
	return false;
}

int main(){
	freopen("C-small-attempt0.in", "r",stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++){
		for (int i = 0; i < 3; i++){
			scanf("%d%d%d", &nodes[i].x, &nodes[i].y, &nodes[i].z);
		}
		sort(nodes, nodes + 3);
		double left = 0, right = 1000000000;
		for (int i = 0; i < 1000; i++){
			double mid = (left + right) / 2;
			if (judge(mid)){
				right = mid;
			}
			else{
				left = mid;
			}
		}
		printf("Case #%d: %.10lf\n",ii,left);
	}
	return 0;
}