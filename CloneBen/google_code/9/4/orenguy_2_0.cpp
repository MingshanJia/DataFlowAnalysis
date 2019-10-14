#include <bits/stdc++.h>

using namespace std;

typedef long long     LL;
typedef pair<int,int> pii;

double PI  = acos(-1);
double EPS = 1e-7;
int INF    = 1000000000;
LL INFLL   = 1000000000000000000LL;

#define fi            first
#define se            second
#define mp            make_pair
#define pb            push_back

#define input(in)     freopen(in,"r",stdin)
#define output(out)   freopen(out,"w",stdout)

#define MIN(a, b)     (a) = min((a), (b))
#define MAX(a, b)     (a) = max((a), (b))

#define RESET(a, b)   memset(a,b,sizeof(a))
#define ALL(a)        (a).begin(), (a).end()
#define SIZE(a)       (int)a.size()
#define SORT(a)       sort(ALL(a))
#define UNIQUE(a)     (a).erase( unique( ALL(a) ), (a).end() )
#define FOR(a, b, c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a, b, c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a, b)   for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); a++)

int mx[8] = {-1,1,0,0,-1,-1,1,1};
int my[8] = {0,0,-1,1,-1,1,-1,1};

// ----- //

int main()
{
	int t;
	scanf("%d",&t);
	FOR(tc,1,t)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		vector<int> x;
		FOR(a,1,n)
		{
			int u;
			scanf("%d",&u);
			x.pb(u);
			if (SIZE(x) >= 3)
			{
				if (x.back() == x[SIZE(x)-2] && x.back() == x[SIZE(x)-3])
				{
					x.pop_back();
					x.pop_back();
					x.pop_back();
				}
			}
		}
		printf("Case #%d: %d\n",tc,SIZE(x));
	}	
}
