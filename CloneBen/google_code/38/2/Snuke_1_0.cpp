#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("IMPOSSIBLE"); return;}
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
#define bn(x) ((1<<x)-1)
#define newline puts("")
#define v(T) vector<T>
#define vv(T) vector<vector<T>>
using namespace std;
typedef long long ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

// Lowlink
// bridge : v->u, ord[u]==low[u]
// articulation : exist ord[v]<=low[u] (root:*2)
struct Lowlink {
  int n, m, k;
  vvi to, st, x;
  vi ord, low;
  vi used;
  vvi id; vp es; //
  Lowlink(int n=0):n(n),to(n),st(n),ord(n,-1),low(n) {
    id = x = vvi(n); m = 0;//
  }
  void add(int a, int b) {
    to[a].pb(b); st[a].pb(0); 
    to[b].pb(a); st[b].pb(0);
    ++m; 
    id[a].pb(m); id[b].pb(-m); es.pb(P(a,b)); //
    x[a].pb(INF);
    x[b].pb(INF);
  }
  void dfs(int v, int p=-1) {
    if (!roots[v]) roots[v] = -1;
    ord[v] = low[v] = k++;
    rep(i,sz(to[v])) {
      int u = to[v][i];
      int ei = abs(id[v][i]);
      if (used[ei]) continue;
      if (ord[u] == -1) {
        st[v][i] = 1;
        used[ei] = 1;
        dfs(u,v);
        mins(low[v],low[u]);
      } else {
        // cerr<<"back"<<" "<<id[v][i]<<endl;
        st[v][i] = -1;
        mins(low[v],ord[u]);
      }
    }
  }

  vi roots;
  void init() {
    k = 0;
    used = vi(m+1);
    roots = vi(n);
    rep(i,n) if (!roots[i]) {
      roots[i] = 1;
      dfs(i);
    }
  }

  // Bridge
  bool exbr() {
    rep(i,n)rep(j,sz(to[i])) {
      int v = i, u = to[i][j];
      if (ord[v] > ord[u]) swap(v,u);
      if (ord[u] == low[u]) return true;
    }
    return false;
  }

  vi sum;
  void sfs(int v) {
    rep(i,sz(to[v])) {
      int u = to[v][i];
      if (st[v][i] == 1) {
        sfs(u);
        sum[v] += sum[u];
      } else if (st[v][i] == -1 && ord[v] > ord[u]) {
        // cerr<<id[v][i]<<" : "<<1<<endl;
        // cerr<<"back"<<" "<<v<<" "<<u<<endl;
        x[v][i] = 1;
        sum[v]++; sum[u]--;
      }
    }
    rep(i,sz(to[v])) {
      if (st[v][i] == 0) {
        // cerr<<id[v][i]<<" "<<sum[v]<<endl;
        x[v][i] = -sum[v];
      }
    }
  }
  void solve() {
    sum = vi(n);
    rep(i,n) if (roots[i] == 1) sfs(i);
    vi ans(m);
    rep(v,n)rep(j,sz(to[v])) {
      int i = id[v][j];
      int nx = x[v][j];
      if (nx != INF) {
        if (i < 0) {
          i = -i;
          nx = -nx;
        }
        ans[i-1] = nx;
      }
    }
    cout<<ans<<endl;
  }
};
//
struct Solver {
  void solve() {
    int n,m;
    scanf("%d%d",&n,&m);
    Lowlink g(n);
    rep(i,m) {
      int a,b;
      scanf("%d%d",&a,&b);
      --a; --b;
      g.add(a,b);
    }
    g.init();
    if (g.exbr()) dame;
    g.solve();
  }
};

int main() {
  int ts;
  scanf("%d",&ts);
  rrep(ti,ts) {
    Solver solver;
    printf("Case #%d: ",ti);
    solver.solve();
  }
  return 0;
}




















