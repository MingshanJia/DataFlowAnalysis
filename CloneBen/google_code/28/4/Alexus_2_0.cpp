#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;

#define PROBLEM "c"

const int N = 310;
const int K = 17;
const int MOD = 9901;

int n, k;
int edges[K][2];
int pows[N];
vector<int> adj[N];
int prev[N], used[N];

int pow2[N], hfac[N], fac[N];

int cycle, incycle;

void dfs(int a){
  if (used[a]){
    cycle = 1;
    return;
  }
  used[a] = 1;
  incycle++;
  int i, k;
  for (i=0; i<(int)(adj[a].size()); i++){
    k = adj[a][i];
    if (k != prev[a]){
      prev[k] = a;
      dfs(k);
    }
  }
  return;
}

int calc(int k){
  int i, one = 0, two = 0;
  if (n < k) return 0;
  
  for (i=1; i<=n; i++){
    if (pows[i] > 2) return 0;
    else if (pows[i] == 2) two++;
    else if (pows[i] == 1) one++;
  }

  memset(prev, 0, sizeof(prev));
  memset(used, 0, sizeof(used));
  cycle = 0;
  for (i=1; i<=n; i++){
    if (!used[i] && pows[i]){
      incycle = 0;
      dfs(i);
    }
  }
  if (cycle && incycle < n) return 0;

  if (cycle && incycle == n) return 1;

  int chains = one / 2;
  if (chains > 0) return (pow2[chains-1] * fac[n-k-1]) % MOD;
  else return hfac[n-k-1];
}

int main(){
  freopen(PROBLEM".in", "r", stdin);
  freopen(PROBLEM".out", "w", stdout);

  pow2[0] = 1;
  pow2[1] = 2;
  pow2[2] = 4;
  hfac[0] = hfac[1] = hfac[2] = 1;
  fac[0] = fac[1] = 1;
  fac[2] = 2;
  for (int i=3; i<N; i++){
    hfac[i] = (hfac[i-1] * i) % MOD;
    pow2[i] = (pow2[i-1] * 2) % MOD;
    fac[i] = (fac[i-1] * i) % MOD;
  }

  int tn, t;
  scanf("%d", &tn);
  for (t=1; t<=tn; t++){
    printf("Case #%d: ", t);
    scanf("%d%d", &n, &k);
    int i, j;
    for (i=0; i<k; i++){
      scanf("%d%d", &edges[i][0], &edges[i][1]);
    }
    int ans = 0;
    for (i=0; i<(1<<k); i++){
      int q = 0;
      memset(pows, 0, sizeof(pows));
      for (j=1; j<=n; j++){
        adj[j].clear();
      }
      for (j=0; j<k; j++){
        if (i & (1<<j)){
          q++;
          int a = edges[j][0];
          int b = edges[j][1];
          pows[a]++;
          pows[b]++;
          adj[a].push_back(b);
          adj[b].push_back(a);
        }
      }
      int cur = calc(q);
      if (q&1) ans -= cur;
      else ans += cur;
      ans %= MOD;
      if (ans < 0) ans += MOD;
    }
    printf("%d\n", ans);
  }
  return 0;
}
