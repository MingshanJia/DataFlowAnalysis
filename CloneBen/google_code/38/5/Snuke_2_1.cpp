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
#define dame { puts("-1"); return;}
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
typedef pair<int,P> Q;
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

// Union find
struct uf {
  vi d;
  uf(){}
  uf(int mx):d(mx,-1){}
  int root(int x) {
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y]; d[y] = x;
    return true;
  }
  int size(int x) { return -d[root(x)];}
};
//

struct E {
  int to, h, id; //c;
};

int f(int s, int t) {
  if (s <= t) return t-s;
  return t+24-s;
}

struct Solver {
  int n, m;
  int calc(int si, vv(E) l, vv(E) r) {
    int res = 0;
    vi cost(n);
    rep(i,n) {
      int best = INF;
      rep(j,2) {
        int now = 0;
        rep(k,2) {
          if (!i && k == si) {
            now += f(0, l[i][k^j].h);
          } else {
            now += f(r[i][k].h, l[i][k^j].h);
          }
        }
        if (j) {
          cost[i] = abs(best-now);
          if (best > now) {
            best = now;
            swap(r[i][0],r[i][1]);
          }
        } else best = now;
      }
      res += best;
    }
    uf t(m);
    v(Q) es;
    rep(i,n) {
      rep(j,2) {
        t.unite(l[i][j].id, r[i][j].id);
      }
      es.pb(Q(cost[i], P(l[i][0].id, l[i][1].id)));
    }
    sort(rng(es));
    for (auto e : es) {
      int a = e.se.fi, b = e.se.se, c = e.fi;
      if (t.unite(a,b)) res += c;
    }
    return res;
  }
  void solve() {
    scanf("%d",&n);
    vv(E) l(n), r(n);
    int sum = 0;
    m = 0;
    rep(i,n)rep(j,2) {
      int to,h,c;
      scanf("%d%d%d",&to,&h,&c);
      --to;
      // l[i].pb((E){to,h,c});
      // r[to].pb((E){i,h,c});
      l[i].pb((E){to,h,m});
      r[to].pb((E){i,(h+c)%24,m}); ++m;
      sum += c;
    }
    int ans = calc(0,l,r);
    mins(ans,calc(1,l,r));
    ans += sum;
    cout<<ans<<endl;
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




















