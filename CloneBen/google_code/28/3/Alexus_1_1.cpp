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

#define PROBLEM "b"

const int MAXN = 17;

int n, k;
int xs[MAXN], ys[MAXN];

char can[MAXN][1<<MAXN];

vector<int> subsets;

int can_cover(int d){
  memset(can, 0, sizeof(can));
  subsets.clear();
  int i, j, h;
  for (i=1; i<=n; i++){
    for (j=1; j<=n; j++){
      if ((xs[j] < xs[i])||(xs[j] > xs[i]+d)||(ys[i] < ys[j]) || (ys[i] > ys[j]+d)) continue;
      int cx = xs[i], cy = ys[j];
      int cset = 0;
      for (h=1; h<=n; h++){
        if ((xs[h] >= cx) && (xs[h] <= cx+d) && (ys[h] >= cy) && (ys[h] <= cy+d)){
          cset |= (1<<(h-1));
        }
      }
      subsets.push_back(cset);
    }
  }
  int sz = subsets.size();
  can[0][0] = 1;
  for (i=0; i<k; i++){
    for (j=0; j<(1<<n); j++){
      if (!can[i][j]) continue;
      for (h=0; h<sz; h++){
        can[i+1][j | subsets[h]] = 1;
      }
    }
  }
  return can[k][(1<<n)-1];
}

int main(){
  freopen(PROBLEM".in", "r", stdin);
  freopen(PROBLEM".out", "w", stdout);
  int tn, t;
  scanf("%d", &tn);
  for (t=1; t<=tn; t++){
    printf("Case #%d: ", t);
    scanf("%d%d", &n, &k);
    int i;
    for (i=1; i<=n; i++){
      scanf("%d%d", &xs[i], &ys[i]);
    }
    int l=1, r=64000;
    while (l < r){
      int m = (l+r)>>1;
      if (!can_cover(m)){
        l = m+1;
      }
      else{
        r = m;
      }
    }
    printf("%d\n", l);
  }
  return 0;
}
