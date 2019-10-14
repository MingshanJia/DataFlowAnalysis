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

long long a[10100];
long long na[10100];
long long L, H;
long long gl[10110];
long long gr[10101];
long long lcm[10100];
int n;
void reducea()
{
	int nn = 1;
	na[0] = a[0];
	for (int i = 1; i < n; ++i)
		if (a[i] != a[i - 1])
		{
			na[nn] = a[i];
			++nn;
		}
	n = nn;
	memcpy(a, na, sizeof(a));
}
long long gcd(long long a, long long b)
{
	if (a < b)
		swap(a, b);
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void precalc()
{
	gl[0] = a[0];
	lcm[0] = a[0];
	if (lcm[0] > H)
		lcm[0] = -1;
	for (int i = 1; i < n; ++i)
	{	
		lcm[i] = -1;
		if (lcm[i - 1] != -1)
		{
			long long d = gcd(lcm[i - 1], a[i]);
			lcm[i] = lcm[i - 1] / d;
			long double x = lcm[i];
			x *= a[i];
			if (x <= 5e+17)
			{
				lcm[i] *= a[i];
				if (lcm[i] > H)
					lcm[i] = -1;
			}
			else
				lcm[i] = -1;
		}
	}
	gr[n - 1] = a[n - 1];
	for (int i = n - 1; i >= 0; --i)
	{
		gr[i] = gcd(gr[i + 1], a[i]);
	}

}


long long findsol()
{
	for (int x = L; x <= H; ++x)
	{
		bool ok = true;
		for (int i = 0; i < n; ++i)
		{
			if (a[i] % x != 0 && x % a[i] != 0)
			{
				ok = false;
				break;
			}
		}
		if (ok)
			return x;
	}
	return -1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		scanf("%d %lld %lld", &n, &L, &H);
		for (int i = 0; i < n; ++i)
			scanf("%lld", &a[i]);
		sort(a, a + n);
		reducea();
		vector<long long> divs;
		for (long long d = 1; d * d <= a[n - 1]; ++d)
		{
			if (a[n - 1] % d == 0)
			{
				if (d >= L && d <= H)
					divs.push_back(d);
				long long nd = a[n - 1] / d;
				if (nd != d && nd >= L && nd <= H)
					divs.push_back(nd);
			}
		}
		sort(divs.begin(), divs.end());
		
		long long res = -1;
		for (int i = 0; i < divs.size(); ++i)
		{
			long long d = divs[i];
			bool ok = true;
			for (int j = 0; j < n; ++j)
			{
				if (a[j] % d != 0 && d % a[j] != 0)
				{
					ok = false;
					break;
				}
			}
			if (ok)
			{
				res = d;
				break;
			}
		}
		precalc();
		if (res == -1 && lcm[n - 1] != -1)
		{
			res = (L + lcm[n - 1] - 1) / lcm[n - 1] * lcm[n - 1];
			if (res > H)
				res = -1;
		}
		printf("Case #%d: ", t + 1);
		if (res == -1)
			printf("NO\n");
		else
			printf("%lld\n", res);
		
	}


	
	return 0;
}