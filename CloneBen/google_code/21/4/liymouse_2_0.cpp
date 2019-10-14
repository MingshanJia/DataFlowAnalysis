#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef long long i64d;

int main()
{
	freopen("C-small-attempt0.in" , "r" , stdin);
	freopen("C-small-attempt0.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		i64d n;
		printf("Case #%d: " , ca);
		scanf("%lld" , &n);
		if (n == 1) {printf("1\n"); continue;}
		int r = 0;
		for (int i = 1; i <= n / 2; i ++)
		{
			int x = i;
			int y = n - i;
			int t = 0;
			while (x) { x &= x - 1; t ++; }
			while (y) { y &= y - 1; t ++; }
			r = max(r , t);
		}
		printf("%d\n" , r);
	}
	return 0;
}