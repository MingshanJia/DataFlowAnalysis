#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int m[1000];


int main()
{
	m[0] = 1;
	m[1] = 5;
	for (int i = 2; i <= 100; i++)
	{
		m[i] = (6*m[i-1] - 4*m[i-2] + 1 + 100000) % 1000;
	}

	freopen("c:\\3.txt", "r", stdin);
	freopen("c:\\3_out.txt", "w", stdout);

	int t;
	scanf("%d", &t);

	for (int te = 1; te <= t; te++)
	{
		int n;
		scanf("%d\n", &n);

		printf("Case #%d: %03d\n", te, m[n]);
	}




	return 0;
}