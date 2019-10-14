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

int getNum(int a , int b , int c)
{
	if (c <= b) return a + c - 1;
	if (c <= b + a - 1) return c - b;
	return c;
}

int main()
{
	freopen("A-small-attempt0.in" , "r" , stdin);
	freopen("A-small-attempt0.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		int m , c , w;
		int a[110] , b[110];
		scanf("%d %d %d" , &m , &c , &w);
		for (int i = 0; i < c; i ++) scanf("%d %d" , &a[i] , &b[i]);
		int y = w;
		for (int i = c-1; i >= 0; i --)
		{
			y = getNum(a[i] , b[i] , y);
		}
		printf("Case #%d: %d\n" , ca , y);
	}
	return 0;
}