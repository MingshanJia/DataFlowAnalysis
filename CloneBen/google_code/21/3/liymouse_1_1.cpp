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
	freopen("B-large.in" , "r" , stdin);
	freopen("B-large.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
		int n;
		i64d k;
		scanf("%d %lld" , &n , &k);
		i64d c[110] , t[110] , s[110];
		i64d res = 0;
		for (int i = 0; i < n; i ++)
			scanf("%lld %lld %lld" , &c[i] , &t[i] , &s[i]);
		for (int i = 0; i < n; i ++)
			for (int j = 1; j < n - i; j ++)
				if (t[j-1] < t[j] || (t[j-1] == t[j] && s[j-1] < s[j]))
				{
					swap(c[j-1] , c[j]);
					swap(t[j-1] , t[j]);
					swap(s[j-1] , s[j]);
				}
		t[n] = 0; n ++;
		i64d now = min(k , t[0]);
		int i = 0;
		while (i < n && t[i] > 0)
		{
			i64d next = 0;
			int x = n-1;
			for (int j = i; j < n; j ++) if (t[j] != t[i]) {next = t[j]; x = j; break;}
			while (1)
			{
				int maxId = -1, maxS = 0;
				for (int h = 0; h < x; h ++)
					if (c[h] > 0 && s[h] > maxS)
					{
						maxId = h; maxS = s[h];
					}
				if (maxId == -1) break;
				if (c[maxId] >= now - next)
				{
					c[maxId] -= now - next;
					res += s[maxId] * (now - next);
					break;
				}
				else
				{
					res += c[maxId] * s[maxId];
					now -= c[maxId];
					c[maxId] = 0;
				}
			}
			now = next;
			i = x;
		}
		printf("%lld\n" , res);
	}
	return 0;
}