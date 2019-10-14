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

const int N = int(4e3)+10;
const LL mod = LL(1e9)+7;
unordered_map< string, int > M;
LL dp[N],ans[N];

int main()
{
	fast_io;
	int T,test=0; cin>>T; while(T--)
	{
		M.clear();
		test++;
		int v,n,mx=0; cin>>v>>n;
		for(int i=0; i<v; i++)
		{
			string s; cin>>s;
			sort(ALL(s));
			M[s]++;
			mx = max(mx,SZ(s));
		}
		for(int ii=0; ii<n; ii++)
		{
			string s; cin>>s;
			dp[0] = 1;
			for(int i=1; i<=SZ(s); i++)
			{
				string tmp;
				dp[i] = 0;
				for(int j=i; j>0; j--)
				{
					if(SZ(tmp)==mx) break;
					tmp.PB(s[j-1]);
					sort(ALL(tmp));
					if(M.count(tmp)) dp[i] = (dp[i] + M[tmp]*dp[j-1])%mod;
				}
			}
			ans[ii] = dp[SZ(s)];
		}
		cout<<"Case #"<<test<<":";
		for(int ii=0; ii<n; ii++) cout<<" "<<ans[ii];
		cout<<"\n";
	}
	return 0;
}

