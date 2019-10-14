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
};
typedef vector<node> vn ; 
int cases,g,h,w;
char gmap[60][60];
int grid[60][60];
bool isclear(int y,int x1,int x2)
{
	for(int i=x1;i<=x2;i++)
		if(grid[y][i])
			return 0;
	return 1;
}
int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
////////////////////////////////////////////
	int i,j,k;
	scanf("%d",&cases);
	for(g=0;g<cases;g++)
	{
		printf("Case #%d: ",g+1);
		scanf("%d%d",&w,&h);
		for(i=0;i<h;i++)
			scanf("%s",&gmap[i]);
		CLS(grid,0);
		for(i=0;i<h;i++)
			for(j=0;j<w;j++)
				if(!(gmap[i][j]=='G' || gmap[i][j]=='S'))
					grid[i][j]=1;

		int x1,x2,y;
		int best=0;
		int prev=0;
		for(x1=0;x1<w;x1++)
		{
			for(x2=x1;x2<w;x2++)
			{
				for(y=0;y<=h;y++)
				{
					if(y!=h && isclear(y,x1,x2))
					{
						prev++;
					}
					else
					{
						best=max(best,(x2-x1+1)*prev);
						prev=0;
					}
				}
			}
		}
		printf("%d\n",best);
	}

	return 0;
}