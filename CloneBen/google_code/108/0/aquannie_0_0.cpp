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
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

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
const int N = 101;
int vis[N][N],L[N],R[N];
int main()
{
  int T;si(T);
  for(int t=1;t<=T;t++){
    int m,n;
    si(m);si(n);
    for(int i=1;i<=m;i++)
      scanf("%d %d",L+i,R+i);
    int ans = 0;
    for(int i=1;i<=n;i++){
      int c = 0;
      SET(vis,0);
      for(int j=1;j<=m;j++)
        if(L[j] == i || R[j] == i){
          int x = L[j], y = R[j];
          if(x != i)swap(x,y);
          if(vis[x][y])continue;
          vis[x][y]=1;
          c++;
        }
      ans = max(ans,c);
    }
    printf("Case #%d: %d\n",t,ans);
  }
	return 0;
}
