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

int R[16][1<<15];
int S[1<<15];
int X[16];
int Y[16];

int main()
{
//	freopen("B-small.in", "r", stdin);
//	freopen("B-small.out", "w", stdout);
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T, t;
	scanf("%d", &T);
	for (t = 0; t < T; ++t)
	{
		int N, K;
		scanf("%d%d", &N, &K);
		int i;
		for (i = 0; i < N; ++i)
			scanf("%d%d", &X[i], &Y[i]);
		int mask;
		int end = (1<<N);
		S[0] = 0;
		for (mask = 1; mask < end; ++mask)
		{
			int ax, ay, bx, by;
			ax = 100000;
			bx = -100000;
			ay = 100000;
			by = -100000;
			for (i = 0; i < N; ++i)
				if (mask & (1<<i))
				{
					if (X[i] < ax)
						ax = X[i];
					if (X[i] > bx)
						bx = X[i];
					if (Y[i] < ay)
						ay = Y[i];
					if (Y[i] > by)
						by = Y[i];
				}
			S[mask] = max(bx-ax, by-ay);
		}
		CLEAR(R, -1);
		R[0][0] = 0;
		for (mask = 0; mask < end; ++mask)
			for (i = 0; i < K; ++i)
				if (R[i][mask] != -1)
				{
					int rm = (end-1)&(~mask);
					int nm;
					for (nm = rm; nm > 0; nm = ((nm-1)&rm))
					{
						int nr = max(R[i][mask], S[nm]);
						int ni = i+1;
						int nmask = (mask|nm);
						if (R[ni][nmask] == -1 || R[ni][nmask] > nr)
							R[ni][nmask] = nr;
					}
				}
		int res = R[1][end-1];
		for (i = 2; i <= K; ++i)
			res = min(res, R[i][end-1]);
		printf("Case #%d: %d\n", t+1, res);
		fprintf(stderr, "%d\n", t+1);
	}
	return 0;
};
