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

int f(i64d x)
{
	int t = 0;
	while (x) {x &= x - 1; t ++;}
	return t;
}
int main()
{
	freopen("C-large.in" , "r" , stdin);
	freopen("C-large.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		i64d n , m;
		printf("Case #%d: " , ca);
		scanf("%lld" , &n);
		int t = 1;
		m = 2;
		while (m <= n) m <<= 1;
		if (m-1 == n) printf("%d\n" , f(n));
		else
		{
			m /= 2;
			printf("%d\n" , f(m-1) + f(n-m+1));
		}
	}
	return 0;
}