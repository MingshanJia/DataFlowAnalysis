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

struct State
{
	int idx, rem;
	long long price;
	
	bool operator < (const State& r) const
	{
		if (price != r.price)
			return price > r.price;
		return idx != r.idx ? idx < r.idx : rem < r.rem;
	}
};

int n, l;
long long t;
int a[MAX];
int vis[MAX][3];

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

long long dijkstra()
{
	State cur, nxt;
	priority_queue <State> q;
	memset(vis, 0, sizeof(vis));
	
	nxt.idx = 0;
	nxt.price = 0;
	nxt.rem = l;
	q.push(nxt);
	
	while (!q.empty())
	{
		cur = q.top(); q.pop();
		if (vis[cur.idx][cur.rem])
			continue;
		vis[cur.idx][cur.rem] = 1;
		if (cur.idx >= n) return cur.price;
		
		// Do not build
		nxt.idx = cur.idx + 1;
		nxt.rem = cur.rem;
		nxt.price = cur.price + a[cur.idx] * 2LL;
		
		if (!vis[nxt.idx][nxt.rem])
			q.push(nxt);
		
		// Try to build
		if (cur.rem > 0 && cur.price + a[cur.idx] * 2 > t)
		{
			long long nu = max(0LL, t - cur.price);
			
			
			nxt.idx = cur.idx + 1;
			nxt.rem = cur.rem - 1;
			nxt.price = cur.price + nu + (a[cur.idx] - nu / 2);
			if (!vis[nxt.idx][nxt.rem])
				q.push(nxt);
		}
	}
	return -1;
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
	fprintf(out, "%s\n", toString(dijkstra()).c_str());
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
