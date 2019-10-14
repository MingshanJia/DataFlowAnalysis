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


const int N = 1000000;
int a[N];






void solve() {
  int ee, n;
  cin >> ee >> n;
  rep(i, n)cin >> a[i];
  sort(a, a + n);
  if (a[0] >= ee) {
    cout << 0 << ln;
    return;
  }
  FOR(i, 1, n - 1)a[i] += a[i - 1];
  int ans = 0;
  rep(i, n)FOR(j, 0, i) {
    int honor = i + 1 - (n - 1 - j);
    int p = ee + a[n - 1] - a[i] - a[j];
    if (p > 0 && honor > ans) ans = honor;
  }
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

