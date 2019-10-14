#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cctype>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <iostream>
#include <stack>
#include <sstream>
using namespace std; 
#define PB push_back
#define MP make_pair
#define F first
#define S second 
#define BE(a) a.begin(),a.end() 
#define CLS(a,b) memset(a,b,sizeof(a))
#define SZ(a) ((int)a.size())
const long double pi=acos(-1.0);
#define torad(a) ((a)*pi/180.0)
typedef vector<int> vi ; 
typedef vector<string> vs ; 
typedef vector<double> vd ; 
typedef pair<int,int> pii ; 
typedef long long ll ; 
typedef long double ld ; 
typedef double dl ; 
class node {public:
char t;
int a,b,c;
};
typedef vector<node> vn ; 
int cases,g;
int n,m;
bool isT[11];
bool isL[11];
node all[500];
int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
////////////////////////////////////////////
	int i,j,k;
	scanf("%d",&cases);

	for(g=0;g<cases;g++)
	{
		CLS(isT,0);
		CLS(isL,0);
		printf("Case #%d: ",g+1);
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d %c",&all[i].a,&all[i].t);
			if(all[i].t=='S' || all[i].t=='D')
				scanf("%d%d",&all[i].b,&all[i].c);
			else
				scanf("%d",&all[i].b);

			all[i].a--;
			all[i].b--;
			all[i].c--;
		}
		for(i=0;i<(1<<n);i++)
		{
			for(j=0;j<m;j++)
			{
				bool truth= (i & (1<<all[j].a));
				if(all[j].t=='T')
				{
					if(bool(i & (1<<all[j].b))!=truth)
						break;
				}
				else if(all[j].t=='L')
				{
					if(bool(i & (1<<all[j].b))==truth)
						break;
				}
				else if(all[j].t=='S')
				{
					if( (bool(i & (1<<all[j].b)) == bool(i & (1<<all[j].c)))!=truth)
						break;
				}
				else if(all[j].t=='D')
				{
					if( (bool(i & (1<<all[j].b)) == bool(i & (1<<all[j].c)))==truth)
						break;
				}
			}
			if(j==m)
			{
				for(j=0;j<n;j++)
				{
					bool truth= i & (1<<j);
					if(truth)
						isT[j]=1;
					else
						isL[j]=1;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			if(isT[i] && isL[i])
				printf("- ");
			else if(isT[i])
				printf("T ");
			else
				printf("L ");
		}
		printf("\n");
	}

	return 0;
}