#include <map>
#include <set>
#include <list>
#include <cmath>
#include <stack>
#include <queue>
#include <bitset>
#include <cstdio>
#include <climits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <array>
#include <assert.h>
#include <functional>
#define _USE_MATH_DEFINES
#include <math.h>
#include <complex>

using namespace std;
typedef long long ll;
#define ln '\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define drep(i,n) int i = 0;for(;i<(n);++i)
#define FOR(i,s,e) for(int i=s;i<=(e);++i)
#define FORR(i,s,e) for(int i=s;i>=(e);--i)
#define fore(a, x) for(auto& a : x)
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define ft first
#define sd second
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(),a.end()
#define Fill(a,b) memset(a,b,sizeof(a))
template<typename T1, typename T2> bool Max(T1& a, T2 b) { return a<b ? a = b, 1 : 0; }
template<typename T1, typename T2> bool Min(T1& a, T2 b) { return a>b ? a = b, 1 : 0; }


const int N = 101, inf = 10000;
int d[N][N];
double dmean[N];
double pro[2][N];





void solve() {
  int n, m, p, u, v, dd;
  cin >> n >> m >> p;
  rep(i, n)rep(j, n)d[i][j] = inf;
  rep(i, m) {
    cin >> u >> v >> dd;
    u--, v--;
    d[u][v] = d[v][u] = dd;
  }
  rep(k, n)rep(i, n)rep(j, n)Min(d[i][j], d[i][k] + d[k][j]);
  rep(i, n) {
    dmean[i] = 0;
    rep(j, n)if (i != j)dmean[i] += d[i][j];
    dmean[i] /= n - 1;
    //cout << "i " << dmean[i] << ln;
  }
  double mean = 0;
  rep(i, n)mean += dmean[i];
  mean /= n;

  rep(i, n)pro[0][i] = 0;
  pro[0][0] = 1;
  int c = 0;
  double ans = 0;
  rep(it, min(200,p)) {
    c ^= 1;
    rep(i, n)pro[c][i] = 0;
    rep(i, n) {
      ans += pro[!c][i] * dmean[i];
      double t = pro[!c][i] / (n - 1);
      rep(j, n)if (i != j)pro[c][j] += t;
    }
  }
  p -= min(200,p);
  ans += p * mean;
  cout << ans << ln;
  
}

void init() {
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
  //freopen("C:\\Users\\LENOVO\\Documents\\Visual Studio 2015\\Projects\\Test\\Input\\in.in", "r", stdin);

  init();
  int TC = 1;
#if 1
  cin >> TC; cin.get();
#endif
  FOR(TI, 1, TC) {
    cout << "Case #" << TI << ": ";
    solve();
  }
  
  
  return 0;
}

