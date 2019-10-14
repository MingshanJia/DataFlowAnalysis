#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>

#define MAX 1024

using namespace std;
FILE *in; FILE *out;

int n;
long long l, h;
long long a[MAX];

long long parseLong()
{
	char buff[32];
	fscanf(in, "%s", buff);
	long long ret = 0;
	for (int i = 0; i < (int)strlen(buff); i++)
		ret = ret * 10 + buff[i] - 48;
	return ret;
}

string toString(long long num)
{
	if (num == 0) return "0";
	string ret;
	while (num) {ret.push_back(num % 10 + 48); num /= 10;}
	reverse(ret.begin(), ret.end());
	return ret;
}


void eval(int testNum)
{
	n = parseLong();
	l = parseLong();
	h = parseLong();
	for (int i = 0; i < n; i++)
		a[i] = parseLong();
	
	long long ans = -1;
	for (long long cur = l; cur <= h; cur++)
	{
		int flag = 1;
		for (int i = 0; i < n; i++)
			if (a[i] % cur != 0 && cur % a[i] != 0) {flag = 0; break;}
		if (flag) {ans = cur; break;}
	}
	if (ans == -1)
		fprintf(out, "NO\n");
	else
		fprintf(out, "%s\n", toString(ans).c_str());
}

int main(void)
{
	unsigned sTime = clock();
	in = fopen("PerfectHarmony.in", "rt");
	out = fopen("PerfectHarmony.out", "wt");
	
	int numTests;
	fscanf(in, "%d", &numTests);
	for (int test = 1; test <= numTests; test++)
	{
		fprintf(stderr, "Currently executing testcase %d...\n", test);
		fprintf(out, "Case #%d: ", test);
		eval(test);
	}
	
	fprintf(stderr, "Total execution time %.3lf seconds.\n", (double)(clock() - sTime) / (double)CLOCKS_PER_SEC);
	system("pause");
	return 0;
}
