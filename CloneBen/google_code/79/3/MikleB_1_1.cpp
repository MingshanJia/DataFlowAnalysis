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
#include <memory.h>
using namespace std;

long long a[1010000], t;
int n, L, C;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for (int _t = 0; _t < T; ++_t)
	{
		scanf("%d %lld %d %d", &L, &t, &n, &C);
		for (int i = 0; i < C; ++i)
		{
			int x;
			scanf("%d", &x);
			for (int j = 0; j * C + i < n; ++j)
				a[j * C + i] = x;
		}
		long long curt = 0;
		bool done = false;
		long long res = 0;
		for (int i = 0; i < n; ++i)
		{
			curt += a[i] * 2;
			res += a[i] * 2;
			if (curt >= t && !done)
			{
				done = true;
				vector<long long> b;
				for (int j = i + 1; j < n; ++j)
					b.push_back(a[j] * 2);
				long long dif = curt - t;
				if (dif != 0)
					b.push_back(dif);
				sort(b.begin(), b.end());
				reverse(b.begin(), b.end());
				for (int j = 0; j < L && j < b.size(); ++j)
				{
					res -= b[j] / 2;
				}
			}
		}
		printf("Case #%d: %lld\n", _t + 1, res);
	}


	
	return 0;
}