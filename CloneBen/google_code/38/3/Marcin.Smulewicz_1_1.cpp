#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
#define LD long double

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
} 

template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}


#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

struct Sol{
//   int find(int v){
//     return f[v] == v ? v : f[v] = find(f[v]);
//   }
//   bool uni(int a,int b){
//     a = find(a);
//     b = find(b);
//     if(a == b)return 0;
//     f[a] = b;
//     return 1;
//   }
  int n,m;
  vector<vector<PII>> d;
  vector<int> res;
  vector<int> vis;
  bool nie = 0;
  int dfs(int nr,int oj){
    vis[nr] = 1;
    int il = 0;
    for(PII el:d[nr])if(el.SE / 2 != oj){
      if(!vis[el.FI]){
        int pom = dfs(el.FI, el.SE / 2);
        il += pom;
        if(pom == 0)nie = 1;
        res[el.SE / 2] = ((el.SE&1) ? pom : -pom);
      }else{
        if(res[el.SE / 2] == 0){
          res[el.SE / 2] = ((el.SE&1) ? 1 : -1);
          il++;
        }else{
          il--;
        }
      }
    }
    return il;
  }
  
  vector<int> a,b,xx;
  void run(int cas){
    cin >> n >> m;
    a.resize(m);
    b.resize(m);
    res.resize(m);
    d.resize(n);
    vis.resize(n);
    R(i,m){
      cin >> a[i] >> b[i];
      a[i]--;b[i]--;
      d[a[i]].PB({b[i],i*2});
      d[b[i]].PB({a[i],i*2+1});
    }
    
    R(i,n){
      if(!vis[i]){
        dfs(i,-1);
      }
    }
    
    
    cout << "Case #" << cas << ": ";
    if(nie){
      cout << "IMPOSSIBLE\n";
      return;
    }else{
      R(i,m)cout << res[i] << " ";
      cout << "\n";
    }
    
    xx.resize(n);
    R(i,m){
      assert(res[i] != 0);
      xx[a[i]] += res[i];
      xx[b[i]] -= res[i];
    }
    R(i,n)assert(xx[i] == 0);
    
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int t;
  cin >> t;
  R(i,t){
    Sol sol;
    sol.run(i+1);
  }
}
