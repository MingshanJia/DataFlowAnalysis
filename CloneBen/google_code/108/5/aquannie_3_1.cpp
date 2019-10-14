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
const LL INF = LL(1e18);
const int MAX = 51 * 51 * 2 * 2;
LL d[51][51];
int U[51*51],V[51*51],W[51*51],m,n,len,vis[51];
pair<double,int> A[MAX];
bool check(){
  sort(A+1,A+1+len);
  int cnt = 0;
  SET(vis,0);
  for(int i=1;i<=len;i++){
    int idx = A[i].S;
    if(idx < 0){
      if(!vis[abs(idx)])cnt++;
      vis[abs(idx)]++;
    }
    else {
      vis[idx]--;
      if(!vis[idx])cnt--;
    }
    if(cnt == n)return true;
  }
  return false;
}
bool ok(double MAX){
  bool ret = false;
  for(int e=1;e<=m;e++){
    int u = U[e],v = V[e], w = W[e];
    len = 0;
    for(int i=1;i<=n;i++){
      double mn = 1e18,mx = -1e18;
      mn = min(mn,min((d[v][i]+w-d[u][i]+0.0)/2.0,MAX - d[u][i]));
      mx = max(mx,max((d[v][i]+w-d[u][i]+0.0)/2.0,d[v][i]+w-MAX));
      if(mn >= 0.0){
        A[++len] = MP(0.0,-i);
        A[++len] = MP(mn,i);
      }
      if(mx <= w){
        A[++len] = MP(mx,-i);
        A[++len] = MP(w*1.0,i);
      }
    }
    ret |= check();
  }
  return ret;
}
int main()
{
  int t;si(t);
  for(int T=1;T<=t;T++){
    printf("Case #%d: ",T);
    si(n);
    SET(d,0);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        d[i][j] = INF;
    for(int i=1;i<=n;i++)d[i][i]=0;
    m = 0;
    for(int i=2;i<=n;i++){
      for(int j=1;j<i;j++){
        int x;si(x);
        if(x == -1)continue;
        d[i][j] = d[j][i] = x;
        U[++m] = i; V[m] = j; W[m] =x;
      }
    }
    //floyd warshall
    for(int k=1;k<=n;k++)
      for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
    //binary search on the answer
    double l = 0, h = 1e20;
    for(int i=0;i<100;i++){
      double m = (l+h)/2;
      if(ok(m))h=m;
      else l = m;
    }
    printf("%.9lf\n",l);
  }
  return 0;
}
