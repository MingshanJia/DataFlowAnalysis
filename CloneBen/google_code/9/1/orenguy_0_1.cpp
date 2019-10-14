#include <bits/stdc++.h>

using namespace std;

typedef long long     LL;
typedef pair<LL,LL> pii;

double PI  = acos(-1);
double EPS = 1e-7;
LL INF    = 1000000000;
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
#define SIZE(a)       (LL)a.size()
#define SORT(a)       sort(ALL(a))
#define UNIQUE(a)     (a).erase( unique( ALL(a) ), (a).end() )
#define FOR(a, b, c)  for (LL (a)=(b); (a)<=(c); (a)++)
#define FORD(a, b, c) for (LL (a)=(b); (a)>=(c); (a)--)
#define FORIT(a, b)   for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); a++)

LL mx[8] = {-1,1,0,0,-1,-1,1,1};
LL my[8] = {0,0,-1,1,-1,1,-1,1};

// ----- //

LL inv[2000005];
LL fac[2000005];
LL mod = 1000000007;



inline long long ipow(long long base, LL exp)
{
    long long result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
        result %= mod;
        base %= mod;
    }

    return result;
}

LL dp[205][205];

LL m,n;

LL go(LL p,LL k)
{
	LL &ret = dp[p][k];
	if (ret != -1) return ret;
	if (p == 0) return ret = (k == 0);
	ret = 0;
	long long tmp = 1;
	FOR(a,1,k)
	{
		tmp = (tmp*inv[a])%mod;
		tmp = (tmp*(LL)(k-(a-1)))%mod;
	//	cout << "mv " << p << " " << k << " " << a << " " << tmp << " " << inv[a] << " " << k-(a-1) << endl;
		ret = ((LL)ret+(tmp*go(p-1,k-a))%mod)%mod;
	}
	//cout << p << " " << k << " " << ret << endl;
	return ret;
}

int main()
{
	inv[0] = 1;
	fac[0] = 1;
	inv[1] = 1;
	fac[1] = 1;
	FOR(a,2,200)
	{
		inv[a] = (ipow(a,mod-2))%mod;
		fac[a] = (fac[a-1]*(LL)a)%mod;
	}
	LL t;
	scanf("%lld",&t);
	FOR(T,1,t)
	{
		scanf("%lld%lld",&m,&n);
		RESET(dp,-1);
		printf("Case #%lld: %lld\n",T,go(m,n));
	}
}
