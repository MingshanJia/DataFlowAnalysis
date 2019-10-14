#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

const int MAXN = 10000 + 10;

int N;
int DP[MAXN];

void Prework()
{
	DP[0] = 0;
	for (int i = 1; i < MAXN; i ++)
	{
		DP[i] = i;
		for (int j = 1; j * j <= i; j ++)
			DP[i] = min(DP[i], DP[i - j * j] + 1);
	}
}

void Work()
{
	scanf("%d", &N);
	printf("%d\n", DP[N]);
}

int main()
{
	Prework();
	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);
	int Cases;
	scanf("%d", &Cases);
	for (int Case = 1; Case <= Cases; Case ++)
	{
		printf("Case #%d: ", Case);
		fprintf(stderr, "Case #%d: \n", Case);
		Work();
		fflush(stdout);
	}
	return 0;
}
