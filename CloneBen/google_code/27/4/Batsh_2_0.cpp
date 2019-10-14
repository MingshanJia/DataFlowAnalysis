#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iterator>
#include <iostream>
#include <functional>
#include <sstream>
#include <numeric>

#define CLR( x , y ) ( memset( (x) , (y) , sizeof( (x) ) ) )
#define EPS 1e-9

using namespace std;

FILE *in=fopen("C.in","r");
FILE *out=fopen("C.out","w");

int n,m;
long long ar[1000],car[1000];

bool ok(long long mid)
{
	long long sum=0;
	for(int i=0;i<n;i++){
		car[i]=ar[i];
		car[i]=min(car[i],mid);
		sum+=car[i];
	}
	if(sum/m>=mid)return 1;
	return 0;
}



int main()
{
	int i,j,k,test,tests;
	fscanf(in,"%d",&tests);
	for(test=1;test<=tests;test++){
		long long ret=0;
		fscanf(in,"%d%d",&n,&m);
		for(i=0;i<n;i++)fscanf(in,"%lld",&ar[i]);

		sort(ar,ar+n);
		reverse(ar,ar+n);
		long long low=0,high=1000000000000000000LL;
		long long best=0;
		ok(364);
		while(low<=high){
			long long mid=(low+high)/2;
			if(ok(mid)){
				best=mid;
				low=mid+1;
			}
			else {
				high=mid-1;
			}
		}
		fprintf(out,"Case #%d: %lld\n",test,best);
		printf("Case #%d: %lld\n",test,best);
	}
	return 0;
}
