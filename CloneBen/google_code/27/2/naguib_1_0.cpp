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
	int p,ind;
};
typedef vector<node> vn ; 
int cases,g;
int n,t,e;
node all[509];
int ans[509];

vector <int> towns[500];
bool cmp(int a,int b)
{
	return a>b;
}
int solve(int x)
{
	if(x==t)return 0;
	int ret=0;
	sort(towns[x].begin(),towns[x].end(),cmp);
	int i,done=0,e=towns[x].size();
	for(i=0;i<e;i++)
		{
			if(done>=e)
				break;
			if(towns[x][i]==0)
				continue;
			ret++;
			done+=towns[x][i];
		}
	if(done<e)return -1;
	return ret;
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
////////////////////////////////////////////
	int i,j,k,sum;
	int done;
	scanf("%d",&cases);
	for(g=0;g<cases;g++)
	{
		sum=0;
		done=0;
		CLS(ans,0);
		printf("Case #%d: ",g+1);
		scanf("%d%d%d",&n,&t,&e);
		t--;

		for(i=0;i<e;i++)
		{
			scanf("%d%d",&j,&k);
			j--;
			towns[j].PB(k);
		}
		for(i=0;i<n;i++)
		{
			k=solve(i);
			if(k==-1)
				break;
			else
				ans[i]=k;
		}
		if(k==-1)
			printf("IMPOSSIBLE\n");
		else
		{
			for(i=0;i<n;i++)
				printf("%d ",ans[i]);
			printf("\n");

		}
			
		for(i=0;i<n;i++)
			towns[i].clear();
	}

	return 0;
}