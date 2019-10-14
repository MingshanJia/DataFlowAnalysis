#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i,n) for (i = 0; i < (n); i++)
#define FORI(i,a,b) for (i = (a); i <= (b); i++)
#define FORD(i,a,b) for (i = (a); i >= (b); i--)
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, -1, sizeof(a))
#define DBG(a) cerr << a << endl;
#define DEBUG 1

int tc, n, m;
int disallow[301][301];

int main()
{
	int i,j,k,t,ct;
	bool ok;

	scanf("%d", &tc);
	FOR(t, tc)
	{
		scanf("%d %d", &n, &m);
		ZERO(disallow);
		FOR(i, m) { scanf("%d %d", &j, &k); disallow[j-1][k-1] = disallow[k-1][j-1] = 1; }
		
		vector<int> a;
		FOR(i, n) a.push_back(i);
		ct = 0;
		do
		{
			if (a[0] != 0) break;
			vector<int> b = a;
			reverse(b.begin(), b.end());
			if (b < a) continue;
			ok = true;
			FOR(i, n-1) if (disallow[a[i]][a[i+1]]) ok = false;
			if (disallow[a[i]][0]) ok = false;
			if (ok) ct++;
		}
		while(next_permutation(a.begin(), a.end()));
		
		printf("Case #%d: ", t+1);
		printf("%d\n", (ct / 2) % 9901);
	}
	return 0;
}

