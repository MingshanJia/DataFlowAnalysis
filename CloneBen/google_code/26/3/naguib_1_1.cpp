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
int cases,g,m;
int price[13];
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
////////////////////////////////////////////
	int i,j,k;
	scanf("%d",&cases);
	for(g=0;g<cases;g++)
	{
		printf("Case #%d: ",g+1);
		scanf("%d",&m);
		for(i=0;i<12;i++)
			scanf("%d",&price[i]);
		int s,e,profit=-(1<<29),p;
		for(i=0;i<11;i++)
			for(j=i+1;j<12;j++)
			{
				int u=m/price[i];
				int cprofit=u*(price[j]-price[i]);
				if(cprofit> profit)
				{
					s=i;
					e=j;
					profit=cprofit;
				}
				else if(cprofit == profit && price[i] < price[s])
				{
					s=i;
					e=j;
					profit=cprofit;
				}
			}
			if(profit <=0)
				printf("IMPOSSIBLE\n");
			else
				printf("%d %d %d\n",s+1,e+1,profit);
	}

	return 0;
}