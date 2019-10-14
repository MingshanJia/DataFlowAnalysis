#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<functional>
#include<algorithm>

using namespace std;

#define _INFILE		"A-small-attempt5.in"
#define _OUTFILE	"a-small5.out"

typedef long long ll;

bool a[1001][101001];


int solve()
{
	int n;
	scanf("%d",&n);
	vector<pair<int, int> > v;

	memset(a, 0, sizeof(a));
	for(int i=0; i<n; i++)
	{
		int p, s;
		scanf("%d %d",&p,&s);
		v.push_back(make_pair(p+s, s));
	}
	sort(v.begin(), v.end());

	a[0][0] = true;
	int bound = 0;

	for(int i=0; i<v.size(); i++)
	{
		for(int j=0; j<=bound; j++)
		{
			if (a[i][j]) {
				a[i+1][j] = true;
				if (j <= v[i].first - v[i].second) {
					a[i+1][j+v[i].second] = true;
					bound = max(bound, j+v[i].second);
				}
			}
		}
	}
	for(int i=101000; i>=0; i--) if (a[v.size()][i]) return i;
}

int main(void)
{
	int T;
	freopen(_INFILE, "r", stdin);
	freopen(_OUTFILE, "w", stdout);

	scanf("%d",&T);

	for(int i=0; i<T; i++)
	{
		printf("Case #%d: %d\n", i+1, solve());
	}
	return 0;
}

