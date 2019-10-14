#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair

#define MAXN 33

double p[1<<13];

int n,m;

double prob[MAXN][4];

int main(){
	
	int t,lp;
	int i,j;
	
	scanf("%d",&t);
	
	for(lp=1;lp<=t;lp++){
		scanf("%d %d",&m,&n);
		for(i=0;i<n;i++){
			for(j=0;j<4;j++){
				scanf("%lf",&prob[i][j]);
			}
		}
		
		for(i=0;i<(1<<(2*n));i++){
			p[i] = 1;
			for(j=0;j<n;j++){
				p[i] *= prob[j][(i & ((1<<(2*j)) | (1<<(2*j+1)))) >> (2*j)];
			}
		}
		
		sort(&p[0],&p[(1<<(2*n))]);
		reverse(&p[0],&p[(1<<(2*n))]);
		
		double ret = 0;
		
		for(i=0;i<min(m,(1<<(2*n)));i++){
			ret += p[i];
		}
		
		printf("Case #%d: %.6lf\n",lp,ret);
		
	}
	
	return 0;
	
}

