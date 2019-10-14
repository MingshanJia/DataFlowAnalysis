#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

int main()
{
  int brt;
  scanf("%d", &brt);
  
  FOR(tt, 1, brt+1) {
    int n, p;
    scanf("%d%d", &n, &p);
    int cnt[p];
    memset(cnt, 0, sizeof cnt);

    REP(i, n) {
      int x;
      scanf("%d", &x);
      cnt[x%p]++;
    }

    int rje = cnt[0];
    if (p == 2) rje += (cnt[1]+1) / 2;
    else if (p == 3) {
      if (cnt[1] + cnt[2]) {
	rje += min(cnt[1], cnt[2]);
	rje += (max(cnt[1], cnt[2]) - min(cnt[1], cnt[2]) + 2) / 3;
      }
    }
    else {
      //      rje += (cnt[2] + 1) / 2;
      
    }

    printf("Case #%d: %d\n", tt, rje);
  }  

  return 0;
}
