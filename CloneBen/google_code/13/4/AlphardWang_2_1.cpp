#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int n;
char name[200][201];
int rank[200];

void input(){
  scanf("%d", &n);
  fgets(name[0], 200, stdin);
  for (int i = 0; i < n; ++ i){
    fgets(name[i], 200, stdin);
    rank[i] = i;
  }
}
int ans;
void solve(){
  ans = 0;
  int curmax = 0;
  for (int i = 1; i < n; ++ i){
    if (strcmp(name[curmax], name[rank[i]]) > 0){
      ++ ans;
    } else {
      curmax = rank[i];
    }
  }
}

int main(){
  int C;
  scanf("%d", &C);
  for (int c = 1; c <= C; ++ c){
    input();
    solve();
    printf("Case #%d: %d\n", c, ans);
  }
  return 0;
}

