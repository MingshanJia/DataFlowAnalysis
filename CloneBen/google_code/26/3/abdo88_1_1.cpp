#include <iostream>
#include <cstdio>

using namespace std;

int p[12];

int main() {
  int N;
  scanf("%d", &N);
  for (int u = 1; u <= N; ++u) {
    int M;
    scanf("%d", &M);
    for (int i = 0; i < 12; ++i) scanf("%d", &p[i]);
    
    int max_i = -1, max_j = -1;
    int maxi = 0;
    for (int i = 0; i < 11; ++i)
      for (int j = i + 1; j < 12; ++j) {
        int units = M / p[i];
        int pro = units * (p[j] - p[i]);
        if (pro > maxi || (pro == maxi && i >= 0 && p[i] < p[max_i])) {
          maxi = pro;
          max_i = i;
          max_j = j;
        }
      }
    
    printf("Case #%d: ", u);
    if (maxi > 0) {
      printf("%d %d %d", max_i + 1, max_j + 1, maxi);
    } else {
      printf("IMPOSSIBLE");
    }
    printf("\n");
  }
  return 0;
}

