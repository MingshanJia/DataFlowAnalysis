#include <stdio.h>
#include <stdarg.h>
#include <cstring>
#include <algorithm>
#define clr(a) memset(a, 0, sizeof(a))
typedef long long ll;

#define DEBUG 1

void dbg(const char * fmt, ...)
{
#if DEBUG
	va_list args;
	va_start(args, fmt);
	vfprintf(stdout, fmt, args);
	va_end(args);
#endif
}


ll d;
int c, n;
ll pos[1000000];;

bool check(ll len)
{
	ll last = -(1LL << 60);
	for(int i = 0; i < n; i++)
	{
		last = std::max(last + d, pos[i] - len);
		if (last > pos[i] + len)
			return false;
	}
	return true;
}

void solve(int test_case)
{
	printf("Case #%d: ", test_case);
	scanf("%d%lld", &c, &d);
	n = 0;
	d *= 2;
	for(int i = 0; i < c; i++)
	{
		int v, p;
		scanf("%d%d", &p, &v);
		p *= 2;
		while(v--)
			pos[n++] = p;		
	}
	ll l = 0, r = n * d;
	while (l < r)
	{
		ll m = (l + r) / 2;
		if (check(m))
			r = m;
		else
			l = m + 1;
	}
	printf("%lld.%lld\n", l / 2, (l % 2) * 5);
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		solve(i);

	return 0;
}
