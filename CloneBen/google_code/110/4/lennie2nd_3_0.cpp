#include<stdio.h>
#include<stdlib.h>
#include <string.h>
bool visited[15][15];
int r, c;
int ret;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int tc;

bool allowed(int cur_r, int cur_c) {
  if ((cur_r >= r) || (cur_r < 0)) {
    return false;
  }
  if ((cur_c >= c) || (cur_c < 0)) {
    return false;
  }
  if (visited[cur_r][cur_c]) {
    return false;
  }
  return true;
}

void dfs(int cur_r, int cur_c, int direction) {
  bool has_move = false;
  visited[cur_r][cur_c] = true;
  int next_r = cur_r + dr[direction];
  int next_c = cur_c + dc[direction];
  if (allowed(next_r, next_c)) {
    has_move = true;
    dfs(next_r, next_c, direction);
  }

  int next_direction = (direction + 1) % 4;

  next_r = cur_r + dr[next_direction];
  next_c = cur_c + dc[next_direction];
  if (allowed(next_r, next_c)) {
    has_move = true;
    dfs(next_r, next_c, next_direction);
  }

  visited[cur_r][cur_c] = false;
  if (!has_move) {
    ret += 1;
  }
}

int main() {

  scanf("%d", &tc);
  for (int t = 0; t < tc; t++) {
    scanf("%d %d", &r, &c);
    memset(visited, 0, sizeof(visited));
    ret = 0;
    dfs(0, 0, 0);
    printf("Case #%d: %d\n", t + 1, ret);
  }
}
