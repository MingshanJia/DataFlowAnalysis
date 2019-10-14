#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <math.h>

int min (int a, int b)
{
	if (b < a)
		return b;
	return a;
}

int keys (int* valid, int n)
{
	int ret = 0;
	while (n != 0)
	{
		if (valid [n % 10])
			ret++;
		else
			return INT_MAX;
		n = n/10;
	}
	return ret;
}

void factor (int* arr, int *count, int no)
{
	int l;
	*count = 0;
	for (l = 2; l < no; l++)
	{
		while (no % l == 0)
		{
			arr [*count] = l;
			no = no/l;
			*count = *count + 1;
		}
	}
}

int find (int* valid, int val)
{
	int s = sqrt (val) + 1;
	int ret = keys (valid, val);
	int x,y;
	while (--s > 1)
	{
		if (val%s == 0)
		{
			x = find (valid, val/s);
			y = find (valid, s);
			if (x == INT_MAX || y == INT_MAX)
				continue;
			ret = min (ret, x + y + 1);
		}
	}
	return ret;
}

int main ()
{
	int t, x;
	int l, l1;
	int ans;
	int valid[10];
	scanf ("%d", &t);
	for (l = 0; l < t; l++)
	{
		for (l1 = 0; l1 < 10; l1++)
		{
			scanf ("%d", & valid [l1]);
		}
		scanf ("%d", &x);
		ans = find (valid, x);
		if (ans == INT_MAX)
			printf ("Case #%d: Impossible\n", l + 1);
		else
			printf ("Case #%d: %d\n", l + 1, ans + 1);
	}
	return EXIT_SUCCESS;
}
