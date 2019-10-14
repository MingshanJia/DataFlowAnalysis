#include <bits/stdc++.h>
using namespace std;

const int N = 7005;

int arr[N];
int n;

void read() {
  scanf("%d", &n);
  for (int i = 0 ; i < n ; i++) {
    scanf("%d", &arr[i]);
  }
}

int bf() {
  int ret = 0;
  for (int i = 0 ; i < n ; i++)
    for (int j = i+1 ; j < n ; j++)
      for (int k = j+1 ; k < n ; k++) {
        int x = arr[i];
        int y = arr[j];
        int z = arr[k];

        if (1ll * x * y == z || 1ll * x * z == y || 1ll * y * z == x) {
          ret++;
        }
      }
  return ret;
}

int main() {
  int t; cin >> t;

  for (int tc = 1 ; tc <= t ; tc++) {
    read();
    printf("Case #%d: %d\n", tc, bf());
  }
  return 0;
}