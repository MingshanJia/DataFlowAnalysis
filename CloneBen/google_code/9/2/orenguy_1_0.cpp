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

double x[405][405][405];
double ans[405][160000];

int main()
{
	int tc;
	scanf("%d",&tc);
	FOR(T,1,tc)
	{
		int b,l,n;
		scanf("%d%d%d",&b,&l,&n);
		x[1][1][1] = 750*b;
		ans[1][1] = min(250.0,x[1][1][1]);
		FOR(a,2,l)
		{
			int u = 0;
			FOR(b,1,a)
			{
				FOR(c,1,b)
				{
					x[a][b][c] = (max(0.0,x[a-1][b-1][c-1]-250.0)+max(0.0,x[a-1][b-1][c]-250.0)+max(0.0,x[a-1][b][c]-250.0))/3.0;
					u++;
					ans[a][u] = min(250.0,x[a][b][c]);
				}
			}
		}
		printf("Case #%d: %.7lf\n",T,ans[l][n]);
	}
}
