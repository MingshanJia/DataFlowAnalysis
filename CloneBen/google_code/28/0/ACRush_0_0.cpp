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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


int f[2005][2005];

int solve(int n,int m)
{
	if (n+m==1) return (n>0)?1:2;
	int &ret=f[n][m];
	if (ret!=-1) return ret;
	ret=0;
	if (n>=2) ret|=solve(n-1,m);
	if (m>=2) ret|=solve(n+1,m-2);
	if (n>=1 && m>=1) ret|=solve(n-1,m);
	return ret;
}
int main()
{
//	freopen("..\\A.in","r",stdin);
	freopen("..\\A-small-attempt0.in","r",stdin);freopen("..\\A-small-attempt0.out","w",stdout);
//	freopen("..\\A-small-attempt1.in","r",stdin);freopen("..\\A-small-attempt1.out","w",stdout);
//	freopen("..\\A-large.in","r",stdin);freopen("..\\A-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	memset(f,255,sizeof(f));
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		printf("Case #%d: ",caseId);
		int n,m;
		scanf("%d%d",&n,&m);
		int ret=solve(n,m);
		if (ret==1) printf("WHITE\n");
		else if (ret==2) printf("BLACK\n");
		else printf("UNKNOWN\n");
		fflush(stdout);
	}
	return 0;
}

