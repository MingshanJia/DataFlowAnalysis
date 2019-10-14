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
int cases,g;
int deg[1000];
bool mat[1000][1000];
bool vis[1000];
int n,m;
int cnt=0,cur;
int all[1000];
void flood(int x)
{
	if(vis[x])return;
	vis[x]=1;
	if(deg[x]%2)
		cur++;
	int i;
	for(i=0;i<n;i++)
		if(mat[x][i])
			flood(i);
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
////////////////////////////////////////////
	int i,j,k;
	scanf("%d",&cases);
	for(g=0;g<cases;g++)
	{
		CLS(deg,0);
		CLS(mat,0);
		CLS(vis,0);
		printf("Case #%d: ",g+1);
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			mat[a][b]=1;
			mat[b][a]=1;
			deg[a]++;
			deg[b]++;
		}
		cnt=0;
		for(i=0;i<n;i++)
		{
			if(!vis[i] && deg[i]>0)
			{
				cur=0;
				flood(i);
				all[cnt++]=cur;
			}
		}
		int ans;
		if(cnt>1)
			ans=cnt;
		else
			ans=0;

		if(cnt>1)
		{
			for(i=0;i<cnt;i++)
				if(all[i]>0)
					all[i]-=2;
		}
		for(i=0;i<cnt;i++)
			ans+=all[i]/2;
		printf("%d\n",ans);
	}

	return 0;
}