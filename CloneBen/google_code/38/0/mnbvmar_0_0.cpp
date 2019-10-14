#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
//#define int LL
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


const int MaxVal = 1e9;

int *result[10];

string ddecay(string num) {
  string res(SZ(num), '0');
  for (char ch : num) {
    if (ch > '0') { res[ch - '1']++; }
  }
  return res;
}

int getId(const string &ns) {
  int res = 0, base = 1;
  int len = SZ(ns);
  for (char ch : ns) {
    res += base * (ch - '0');
    base *= len + 1;
  }
  return res;
}

const int MaxLen = 5;

void preproc() {
  for (int len = 1; len <= MaxLen; len++) {
    int range = 1;
    for (int i = 0; i < len; i++) { range *= len + 1; }

    result[len] = new int[range];

    for (int i = 0; i < range; i++) { result[len][i] = 1; }

    for (int sum = len * (len + 1); sum > 0; sum--) {
      for (int i = 0; i < range; i++) {
        int gotSum = 0;
        int x = i;
        for (int j = 0; j < len; j++) {
          gotSum += x % (len + 1); x /= len + 1;
        }
        if (gotSum != sum) { continue; }

        x = i;
        string s;
        for (int j = 0; j < len; j++) {
          s += '0' + x % (len + 1);
          x /= len + 1;
        }

        reverse(ALL(s));

        string ns = ddecay(s);
        int nxtsum = 0;
        for (char ch : ns) { nxtsum += ch - '0'; }

        //debug(s, ns, i, result[len][i]);
        if (ns == s) { continue; }

        //debug(s, ns);

        reverse(ALL(ns));

        result[len][getId(ns)] += result[len][i];
      }
    }
  }
}


struct Testcase {
  void run(int tid) {
    string s;
    cin >> s;
    reverse(ALL(s));
    cout << "Case #" << tid << ": " << result[SZ(s)][getId(s)] << "\n";
  }
};



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  preproc();

  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    Testcase tc;
    tc.run(i);
  }
}
