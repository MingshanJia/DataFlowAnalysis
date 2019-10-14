#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;
typedef long long LL;

bool a[310][310];
int adj[310][310];

int dx[8]={-1,0,1,0,-1,1,-1,1};
int dy[8]={0,1,0,-1,1,1,-1,-1};

int x[1000010], y[1000010];

int main()
{
	freopen("cube_iv.in","r",stdin);
	freopen("cube_iv.out","w",stdout);
	int tc, nt=1;
	cin>>tc;
	while (tc--)
	{
		int n;
		cin>>n;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				int t;
				scanf("%d",&t);
				x[t]=i;
				y[t]=j;
			}
		int ret=1, best=1;
		for (int i=1;i<=n*n;i++)
		{
			int j=i+1;
			while (j<=n*n && abs(x[j]-x[j-1])+abs(y[j]-y[j-1])==1) j++;
			if (j-i>ret)
			{
				ret=j-i;
				best=i;
			}
			i=j-1;
		}
		cout<<"Case #"<<nt++<<": "<<best<<" "<<ret<<endl;
	}
}
