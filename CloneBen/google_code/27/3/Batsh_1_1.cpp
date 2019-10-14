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

FILE *in=fopen("B.in","r");
FILE *out=fopen("B.out","w");

int n,dest;
int m;

class gtr{
public:
	int town;
	int cap;
}ar[10000];

bool cmp(gtr a,gtr b)
{
	if(a.town!=b.town)return a.town<b.town;
	return a.cap>b.cap;
}
int ans[10000];
int main()
{
	int i,j,k,test,tests;
	fscanf(in,"%d",&tests);
	for(test=1;test<=tests;test++){
		int ret=0;
		fscanf(in,"%d%d",&n,&dest);
		fscanf(in,"%d",&m);
		for(i=0;i<m;i++){
			fscanf(in,"%d%d",&ar[i].town,&ar[i].cap);

		}
		sort(ar,ar+m,cmp);
		CLR(ans,0);
		int flag=0;
		for(i=1;i<=n;i++){
			int R=0;
			if(i==dest)continue;
			for(j=0;j<m;j++){
				if(ar[j].town!=i)continue;
				R++;
			}
			for(j=0;j<m;j++){
				if(ar[j].town!=i)continue;
				R-=ar[j].cap;
				ans[ar[j].town]++;
				if(R<=0)break;
			}
			if(R>0)flag=1;
		}
		if(flag){
			fprintf(out,"Case #%d: IMPOSSIBLE\n",test);
		}
		else {
			fprintf(out,"Case #%d: ",test);
			for(i=1;i<=n;i++){
				if(i<n)fprintf(out,"%d ",ans[i]);
				else fprintf(out,"%d\n",ans[i]);
			}
		}
	}
	return 0;
}
