//itisalways42
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

const int N = int(2e3)+10;
double dp[N][N];

int main()
{
	int test=0;
	int T; si(T); while(T--)
	{
		test++;
		int n,m; si(n); si(m);
		dp[0][0] = 1;
		for(int i=1; i<=n; i++)
			for(int j=0; j<=m; j++)
			{
				if(i<=j)
				{
					dp[i][j] = 0;
					continue;
				}
				dp[i][j] = dp[i-1][j]*i;
				if(j>0) dp[i][j] += dp[i][j-1]*j;
				dp[i][j] /= (i+j);
			}
		double ans = dp[n][m];
		printf("Case #%d: %.8lf\n",test,ans);
	}
	return 0;
}

