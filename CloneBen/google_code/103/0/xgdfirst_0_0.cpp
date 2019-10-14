#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define eps 1e-8
#define PI 3.14159265358979323846
using namespace std;

int a[100];


int main(){
	int T,TT;
	scanf("%d",&T);
	for(TT=1;TT<=T;TT++){
		int p,k,l,i;
		scanf("%d%d%d",&p,&k,&l);
		for(i=0;i<l;i++){
			scanf("%d",&a[i]);
		}
		if(p*k<l){
			printf("Case #%d: Impossible\n",TT);
		}else{
			sort(a,a+l,greater<int>());
			int j=0,cnt=1;
			int ret=0;
			for(i=0;i<l;i++){
				ret+=a[i]*cnt;
				j++;
				if(j==k){
					j=0;
					cnt++;
				}
			}
			printf("Case #%d: %d\n",TT,ret);
		}
		
	}
}

