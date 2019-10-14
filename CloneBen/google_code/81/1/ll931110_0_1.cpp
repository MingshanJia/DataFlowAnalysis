#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int T,pd,pg;
long long n;

int gcd(int x,int y)
{
	if (x > y) swap(x,y);
	return (!x) ? y : gcd(y % x,x);
}

int main()
{
	freopen("a.i2","r",stdin);
	freopen("a.o2","w",stdout);
	
	scanf("%d", &T);
	for (int it = 1; it <= T; it++)
	{
		scanf("%lld %d %d", &n, &pd, &pg);
		printf("Case #%d: ", it);
		if (pd < 100 && pg == 100)
		{
			printf("Broken\n");  continue;
		}
		if (pd > 0 && pg == 0)
		{
			printf("Broken\n");  continue;
		}
		int f = gcd(pd,100);
		int s = 100/f;
		if (s > n)
		{
			printf("Broken\n");  continue;
		}
		printf("Possible\n");
	}
}
