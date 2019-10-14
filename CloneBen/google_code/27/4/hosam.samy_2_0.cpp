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
FILE * out=  fopen("out.out","w");

int n ,  c;
int t[1001];

int main()
{
	int i , a , k , caseID = 0 , co , flag;
	int ret = 0;
	fscanf(in,"%d",&k);
	while(k--)
	{
		fprintf(out,"Case #%d: ",++caseID);
		fscanf(in,"%d %d",&n,&c);
		co = 0;
		for(i=0;i<n;i++){ fscanf(in,"%d",&t[i]); co+=t[i];}
		ret = 0;
		for(i=0;i<co;i++)
		{
			flag = 0;
			sort(t,t+n);
			for(a=n-1;a>-1;a--)
				if(t[a])
				{
					t[a]--;
					flag++;
					if(flag == c) break;
				}
			if(flag == c) ret++;
		}
		fprintf(out,"%d\n",ret);
	}
	return 0;
}