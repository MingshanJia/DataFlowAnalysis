#include <stdio.h>
#include <stdarg.h>
#include <cstring>
#define clr(a) memset(a, 0, sizeof(a))

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


int count[100];
double wp[100];
double owp[100];
double oowp[100];
char map[100][102];

void solve(int test_case)
{
	printf("Case #%d:\n", test_case);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		wp[i] = owp[i] = oowp[i] = count[i] = 0;
	}
	for(int i = 0; i < n; i++)
		scanf("%s", map[i]);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if (map[i][j] == '1')
				wp[i] ++;
			if (map[i][j] != '.')
				count[i] ++;
		}
		wp[i] /= count[i];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if (map[i][j] != '.')
				owp[i] += (wp[j] * count[j] - (map[j][i] - '0')) / (count[j] - 1);
		}
		owp[i] /= count[i];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if (map[i][j] != '.')
				oowp[i] += owp[j];
		}
		oowp[i] /= count[i];
	}
	for(int i = 0; i < n; i++)
		printf("%.10lf\n", (wp[i] + 2*owp[i] + oowp[i]) / 4.);

}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		solve(i);

	return 0;
}
