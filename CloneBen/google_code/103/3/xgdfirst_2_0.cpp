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

int a[500000];
int b[500001];
int ret[500001];

int main(){
	int T,TT;
	scanf("%d",&T);
	for(TT=1;TT<=T;TT++){
		int i,n,m,x,y,z,j;
		scanf("%d%d%d%d%d",&n,&m,&x,&y,&z);
		for(i=0;i<m;i++){
			scanf("%d",&a[i]);
		}
		b[0]=-1;
		for(i=0;i<n;i++){
			b[i+1]=a[i%m];
			a[i%m]=((long long)x * (long long)a[i%m] + (long long)y * ((long long)i + 1)) % z;
		}
		memset(ret,0,sizeof(ret));
		ret[0]=1;
		for(i=1;i<=n;i++){
			for(j=0;j<i;j++){
				if(b[i]>b[j]){
					ret[i]+=ret[j];
					if(ret[i]>=1000000007){
						ret[i]-=1000000007;
					}
				}
			}
		}
		int sum=0;
		for(i=1;i<=n;i++){
			sum+=ret[i];
			if(sum>1000000007)
				sum-=1000000007;
		}
		printf("Case #%d: %d\n",TT,sum);
	}
}

