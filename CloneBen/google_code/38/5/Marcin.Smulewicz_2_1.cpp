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
  vector<int> f;
  int find(int v){
    return f[v] == v ? v : f[v] = find(f[v]);
  }
  bool uni(int a,int b){
    a = find(a);
    b = find(b);
    if(a == b)return 0;
    f[a] = b;
    return 1;
  }
  int n;
  
  vector<int> p,l;
  vector<vector<int>> d;
  
  int kon(int a){
    return (l[a] + p[a]) % 24;
  }
  int odl(int a,int b){
    if(a <= b){
      return b - a;
    }else{
      return 24 - a + b;
    }
  }
  
  int res = 0;
  void run(int cas){
    cin >> n;
    f.resize(n*2);
    R(i,n*2)f[i] = i;
    p.resize(n*2);
    l.resize(n*2);
    d.resize(n);
    R(i,2*n){
      int pom;
      cin >> pom >> p[i] >> l[i];
      pom--;
      d[pom].PB(i);
      res += l[i];
    }
    vector<PII> x;
    R(i,n){
      
      
      int c1 = odl(kon(d[i][0]), p[i*2]) + 
               odl(kon(d[i][1]), p[i*2+1]);
      int c2 = odl(kon(d[i][0]), p[i*2+1]) + 
               odl(kon(d[i][1]), p[i*2]);
      debug(   i,c1,c2);
      if(i == 0){
        c1 = min(
          odl(kon(d[i][0]), p[i*2]) + 
          odl(0, p[i*2+1]),
          
          odl(0, p[i*2]) + 
          odl(kon(d[i][1]), p[i*2+1])
        );
        
        c2 = min(
          odl(kon(d[i][0]), p[i*2+1]) + 
          odl(0, p[i*2]),
          
          odl(0, p[i*2+1]) + 
          odl(kon(d[i][1]), p[i*2])  
        );
      }
      debug(i,c1,c2);
      x.PB({abs(c2-c1),i});
      if(c1 < c2){
        res += c1;
        uni(d[i][0], i*2);
        uni(d[i][1], i*2+1);
      }else{
        res += c2;
        uni(d[i][0], i*2+1);
        uni(d[i][1], i*2);
      }
    }
    sort(ALL(x));
    R(_,n){
      int i = x[_].SE;
      if(find(i*2) != find(i*2 + 1)){
        res += x[_].FI;
        uni(i * 2, i * 2 + 1);
      }
    }
    cout << "Case #" << cas << ": " << res << "\n";
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
