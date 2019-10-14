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


const int N = 10000, inf = 10000;
int f[N + 1];





void solve() {
  int n;
  cin >> n;
  cout << f[n] << ln;
  
}

void init() {
  FOR(i, 1, N) {
    f[i] = i;
    for (int j = 1; j*j <= i; j++) {
      Min(f[i], f[i - j*j] + 1);
    }
  }
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

