#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

bool used[N];
int to[N], ta[N], tb[N];
int n;
int ans;

void dfs(int v, int len, int t, int sum) {
  if (used[2 * v] && used[2 * v + 1]) {
    if (len == 2 * n) {
      ans = min(ans, sum);
    }
    return;
  }
  for (int i = 2 * v; i <= 2 * v + 1; i++) {
    if (used[i]) {
      continue;
    }
    int wait = ta[i] - t;
    if (wait < 0) {
      wait += 24;
    }
    int new_t = (t + wait + tb[i]) % 24;
    int new_sum = sum + wait + tb[i];
    used[i] = true;
    dfs(to[i], len + 1, new_t, new_sum);
    used[i] = false;
  }
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++) {
      scanf("%d %d %d", to + i, ta + i, tb + i);
      to[i]--;
      used[i] = false;
    }
    ans = (int) 1e9;
    dfs(0, 0, 0, 0);
    printf("%d\n", ans);
  }
  return 0;
}
