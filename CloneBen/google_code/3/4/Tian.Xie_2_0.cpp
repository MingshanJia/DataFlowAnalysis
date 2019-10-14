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

int N;
int X[3], Y[3], Z[3];

// for small
int Check(double r)
{
	double g = (double) X[0] + r * 6.0;
	return (X[1] <= g && X[2] <= g);
}

void Work()
{
	for (int i = 0; i < 3; i ++)
		scanf("%d%d%d", &X[i], &Y[i], &Z[i]);

	for (int i = 0; i < 3; i ++)
		for (int j = 0; j < 3; j ++)
			if (X[i] < X[j])
			{
				swap(X[i], X[j]);
				swap(Y[i], Y[j]);
				swap(Z[i], Z[j]);
			}

	double Left = 0, Right = 1e4, Mid;
	for (int rep = 0; rep < 1000; rep ++)
	{
		Mid = (Left + Right) * 0.5;
		if (Check(Mid))
			Right = Mid;
		else
			Left = Mid;
	}
	printf("%.10lf\n", Left);
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
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
