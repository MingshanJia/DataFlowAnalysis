#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <algorithm>
#include <vector> 
#include <string> 
#include<set>
#include<map>
#include<queue>
using namespace std; 

#define pb push_back
#define all(n) n.begin(),n.end() 

typedef vector<int> vi ; 
typedef vector<string> vs ; 
typedef vector<double> vd ; 
typedef vector<long long> vll ;

FILE * in = fopen("in.in","r");
FILE * out = fopen("out.out","w");

map<int , int> vis;

int main()
{
	int i , a , k , caseID = 0 , n , t[10000];
	fscanf(in,"%d",&k);
	while(k--)
	{
		fscanf(in,"%d",&n);
		fprintf(out,"Case #%d: ",++caseID);
		vis.clear();
		for(i=0;i<n;i++)
		{
		fscanf(in,"%d",&t[i]);
		vis[t[i]]++;
		}
		for(i=0;i<n;i++)
		if(vis[t[i]] == 1)
		{
			fprintf(out,"%d\n",t[i]);
			break;
		}
	}
	return 0;
}