#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<complex>
#define EPS (1e-10)
#define PI (3.141592653589793238)
#define MP make_pair
typedef long long ll;
using namespace std;

int main(void){
	int T;
	scanf("%d",&T);
	for(int casenum=1;casenum<=T;casenum++){
		int i,j;
		int n,pd,pg;
		scanf("%d %d %d",&n,&pd,&pg);
		bool ok=false;
		for(i=1;i<=min(n,110);i++){
			for(j=0;j<=i;j++){
				if(j*100==pd*i)ok=true;
			}
		}
		printf("Case #%d: ",casenum);
		if(!ok || (pg==100 && pd!=100) || (pg==0 && pd!=0)){
			printf("Broken\n");
		}else{
			printf("Possible\n");
		}
	}
	return 0;
}
