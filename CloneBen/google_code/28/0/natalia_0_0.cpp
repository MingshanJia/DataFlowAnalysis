#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cassert>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forv(i, v) forn(i, v.size())
#define for1(i, n) for (int i = 1; i <= int(n); i++)

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef vector<int> VI;
typedef long long ll;

#define NMAX 5005

int b, w;
int d[NMAX][NMAX];

void solve(int test)
{
	printf("Case #%d: ", test);
	scanf("%d %d", &w, &b);
	if (d[b][w] == 1) printf("BLACK\n");
	if (d[b][w] == 2) printf("WHITE\n");
	if (d[b][w] == 0) printf("UNKNOWN\n");
}
int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	d[1][0] = 1;
	d[0][1] = 2;
	forn(b, NMAX)
	{
		forn(w, NMAX)
		{
			if (b + w <= 1) continue;
			if (b >= 2 && w >= 1 && w < NMAX - 1)
			{
				if (d[b - 2][w + 1] == d[b][w - 1])
				{
					d[b][w] = d[b][w - 1];
				}
				else
				{
					d[b][w] = 0;
				}
			}
			else if (b < 2 && w >= 1)
			{
				d[b][w] = d[b][w - 1];
			}
			else if (b >= 2 && w < NMAX - 1)
			{
				d[b][w] = d[b - 2][w + 1];
			}
		}			
	}

/*	forn(i, 20)
	{
		forn(j, 20)
		{
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	*/
	int tc; scanf("%d", &tc);
	forn(it, tc)
	{
		solve(it + 1);
	}
	return 0;
}
