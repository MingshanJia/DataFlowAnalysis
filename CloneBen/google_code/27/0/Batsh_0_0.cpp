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

FILE *in=fopen("A.in","r");
FILE *out=fopen("A.out","w");

int n;

map < int , int > mp;

int ar[10000];

int main()
{
	int i,j,k,test,tests;
	fscanf(in,"%d",&tests);
	for(test=1;test<=tests;test++){
		int ret=0;
		fscanf(in,"%d",&n);
		mp.clear();
		for(i=0;i<n;i++)fscanf(in,"%d",&ar[i]);
		for(i=0;i<n;i++)mp[ar[i]]++;
		for(i=0;i<n;i++)if(mp[ar[i]]==1){
			ret=ar[i];
		}
		fprintf(out,"Case #%d: %d\n",test,ret);
		printf("Case #%d: %d\n",test,ret);
	}
	return 0;
}
