#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
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
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

vector<int> a[2];

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);

	int i,j,k,l,t,n,m,now,tmp,x;	
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d",&n);
		a[0].clear();
		a[0].push_back(n);
		now=0;
		for (i=n-1;i>=1;i--)
		{
			tmp=(i-1)%(n-i+1);
			a[1-now].clear();
			for (j=n-i-tmp;j<n-i;j++)
			{
				a[1-now].push_back(a[now][j]);
			}
			a[1-now].push_back(i);
			for (j=0;j<n-i-tmp;j++)
			{
				a[1-now].push_back(a[now][j]);
			}
			now=1-now;
		}
		scanf("%d",&m);
		printf("Case #%d:",l+1);
		for (i=0;i<m;i++)
		{
			scanf("%d",&x);
			printf(" %d",a[now][x-1]);
		}
		printf("\n");
	}
	return 0;
}

