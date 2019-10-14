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

int sil[11];

struct Sol{
  int res = 0;
  set<string> vis;
  int L;
  void licz(string z){
    if(!vis.insert(z).SE)return;
    res++;
    string x;
    int sum = 0;
    R(i,SZ(z)){
      cerr << (int)z[i];
      R(j,z[i]){
        x += char(i+1);
        sum += i+1;
      }
    }
    cerr << "\n";
    if(SZ(x) > L)return;
    
    if(sum > L){
      int pom = sil[L];
      for(char el:z)
        pom /= sil[(int)el];
      pom /= sil[L - SZ(x)];
      res += pom;
      return;
    }
    
    
    while(SZ(x) != L) x = char(0) + x;
    do{
      licz(x);
    }while(next_permutation(ALL(x)));
  }
  
  void run(int cas){
    string z;
    cin >> z;
    L = SZ(z);
    for(char &el:z)el -= '0';
    licz(z);
    cout << "Case #" << cas << ": " << res << "\n";
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  sil[0] = 1;
  R(i,10)sil[i+1] = sil[i] * (i+1);
  
  int t;
  cin >> t;
  R(i,t){
    Sol sol;
    sol.run(i+1);
  }
}
