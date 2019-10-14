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

int tc, n;

int main()
{
	int i,j,k,t, b, w, nn;

	scanf("%d", &tc);
	FOR(t, tc)
	{
		scanf("%d %d", &w, &b);

		n = w + b;
		
		printf("Case #%d: ", t+1);	
		printf("%s\n", ((n & 1) ^ (w & 1)) == 1 ? "BLACK" : "WHITE");
	}
	return 0;
}

