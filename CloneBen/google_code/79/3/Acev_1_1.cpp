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

#define MAX 1048576

using namespace std;
FILE *in; FILE *out;

int n, l;
long long t;
int a[MAX];

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


long long solve()
{
	long long ans = 0;
	vector <long long> v;
	for (int i = 0; i < n; i++)
	{
		if (t < ans + a[i] * 2LL)
			v.push_back(a[i] - max(0LL, t - ans) / 2);
		ans += a[i] * 2LL;
	}
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < min((int)v.size(), l); i++)
		ans -= v[i];
	return ans;
}

void eval(int testNum)
{
	l = parseLong();
	t = parseLong();
	n = parseLong();
	
	int tmp, what;
	fscanf(in, "%d", &tmp);
	for (int i = 0; i < tmp; i++)
	{
		fscanf(in, "%d", &what);
		for (int c = i; c < n; c += tmp)
			a[c] = what;
	}
	fprintf(out, "%s\n", toString(solve()).c_str());
}

int main(void)
{
	unsigned sTime = clock();
	in = fopen("SpaceEmergency.in", "rt");
	out = fopen("SpaceEmergency.out", "wt");
	
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
