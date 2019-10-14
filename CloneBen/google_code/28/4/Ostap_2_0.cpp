#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long double Double;
typedef vector<int> VInt;
typedef vector< vector<int> > VVInt;
typedef long long Int;
typedef pair<int, int> PII;

#define FOR(i, n, m) for(i = n; i < m; ++i)
#define RFOR(i, n, m) for(i = (n) - 1; i >= (m); --i)
#define CLEAR(x, y) memset(x, y, sizeof(x))
#define COPY(x, y) memcpy(x, y, sizeof(x))
#define PB push_back
#define MP make_pair
#define SIZE(v) ((int)((v).size()))
#define ALL(v) (v).begin(), (v).end()

#define MOD 9901

int res;
int U[12];
int A[12][12];
int N;
void F(int v, int k)
{
	if (k == N && v == 0)
	{
		++res;
		if (res == MOD)
			res = 0;
		return;
	}
	if (U[v])
		return;
	U[v] = 1;
	int i;
	for (i = 0; i < N; ++i)
		if (A[v][i] == 0)
			F(i, k+1);
	U[v] = 0;
}

int step(int x, int s)
{
	if (s == 0)
		return 1;
	int r = step(x, s>>1);
	r = (r*r)%MOD;
	if (s&1)
		r = (r*x)%MOD;
	return r;
}

int main()
{
	freopen("C-small.in", "r", stdin);
	freopen("C-small.out", "w", stdout);
//	freopen("-large.in", "r", stdin);
//	freopen("-large.out", "w", stdout);

	CLEAR(U, 0);
	int T, t;
	scanf("%d", &T);
	for (t = 0; t < T; ++t)
	{
		int K;
		scanf("%d%d", &N, &K);
		CLEAR(A, 0);
		int i;
		for (i = 0; i < K; ++i)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			--a;
			--b;
			A[a][b] = A[b][a] = 1;
		}
		res = 0;
		F(0, 0);
		int inv = step(2, MOD-2);
		res = (res*inv) % MOD;
		printf("Case #%d: %d\n", t+1, res);
		fprintf(stderr, "%d\n", t+1);
	}

	return 0;
};
