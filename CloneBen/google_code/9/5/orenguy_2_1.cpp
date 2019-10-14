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

int x[105];
int dp[105][105][2][2];
int K;


int go(int l,int r,int must,int pick)
{
	int &ret = dp[l][r][must][pick];
	if (ret != -1) return ret;
	if (l > r)
	{
		if (must) return ret = !pick;
		else return ret = 0;
	}
	if (must)
	{
		if (pick)
		{
			FOR(a,l+1,r-1)
			{
				if (x[l]+K == x[a] && go(l+1,a-1,1,0) && go(a+1,r-1,1,0))
				{
					return ret = 1;
				}
			}
			return ret = 0;
		}
		else
		{
			//cout << "yo " << l << " " << r << endl;
			FOR(a,l+1,r)
			{
				//cout << "y " << a << " " << x[l]+2*K << " " << x[a] << endl;
				if (x[l]+2*K == x[a] && go(l,a,1,1) && go(a+1,r,1,0))
				{
				//	cout << l << " " << r << " " << a << endl;
					return ret = 1;
				}
			}
			return ret = 0;
		}
	}
	else
	{
		ret = INF;
		//cout << "hue " << l << " " << r <<endl;
		if (go(l,r,1,0)) ret = 0;
		FOR(a,l,r)
		{
			MIN(ret,1+go(l,a-1,0,0)+go(a+1,r,0,0));
		}
		return ret;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	FOR(tc,1,t)
	{
		RESET(dp,-1);
		int n,k;
		scanf("%d%d",&n,&k);
		
		K = k;
		FOR(a,1,n)
		{
			scanf("%d",&x[a]);
		}
		printf("Case #%d: %d\n",tc,go(1,n,0,0));
	}	
}
