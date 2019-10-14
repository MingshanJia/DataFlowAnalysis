#include <cstdio>
#include <algorithm>

using namespace std;

char grid[128][128];
bool cole[128][128][128];

int main() {
  int N;
  scanf("%d", &N);
  for (int u = 1; u <= N; ++u) {
    int R, C;
    scanf("%d%d", &C, &R);
    for (int i = 0; i < R; ++i) scanf("%s", grid[i]);
    for (int i = 0; i < R; ++i)
      for (int j = 0; j < C; ++j)
        if (grid[i][j] == 'G' || grid[i][j] == 'S')
          grid[i][j] = 'E';
        else
          grid[i][j] = 'F';
    
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        cole[i][j][j] = grid[i][j] == 'E';
        for (int k = j + 1; k < C; ++k)
          cole[i][j][k] = cole[i][j][k - 1] && (grid[i][k] == 'E');
      }
    }
    
    int biggest = 0;
    for (int si = 0; si < R; ++si)
      for (int sj = 0; sj < C; ++sj)
        for (int ei = si; ei < R; ++ei)
          for (int ej = sj; ej < C; ++ej) {
            bool clear = true;
            for (int i = si; i <= ei; ++i)
              if (!cole[i][sj][ej]) {
                clear = false;
                break;
              }
            if (!clear) continue;
            biggest = max(biggest, (ei - si + 1) * (ej - sj + 1));
          }
    printf("Case #%d: %d\n", u, biggest);
  }
  return 0;
}

