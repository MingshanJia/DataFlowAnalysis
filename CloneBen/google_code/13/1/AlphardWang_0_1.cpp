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

map<string, int> name_idx;
vector<vector<int> > edge;

bool input();
bool solve();

int main(){
  int C;
  scanf("%d", &C);
  for (int c = 1; c <= C; ++ c){
    input();
    if (solve()){
      printf("Case #%d: Yes\n", c);
    } else {
      printf("Case #%d: No\n", c);
    }
  }
  return 0;
}

inline int get_name_idx(const string &s){
  int idx;
  if (name_idx.find(s) == name_idx.end()){
    idx =  name_idx.size();
    name_idx[s] = idx;
    edge.push_back(vector<int>());
  } else {
    idx = name_idx[s];
  }
  return idx;
}

char str[20000];

bool input(){
  name_idx.clear();
  scanf("%d", &n);
  edge.clear();
  
  for (int i = 0; i < n; ++ i){
    scanf("%s", str);
    string s1(str);
    int a = get_name_idx(s1);
    scanf("%s", str);
    string s2(str);
    int b = get_name_idx(s2);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  return true;
}
vector<int> color;

bool dfs(int v, int c){
  if (color[v] != -1){
    if (color[v] == c) return true;
    return false;
  }
  color[v] = c;
  for (int i = 0; i < edge[v].size(); ++ i){
    if (!dfs(edge[v][i], c ^ 1)) return false;
  }
  return true;
}

bool solve(){
  n = edge.size();
  color.clear();
  color.resize(n, -1);
  for (int i = 0; i < n; ++ i) {
    if (color[i] == -1){
      if (!dfs(i, 0)) return false;
    }
  }
  return true;
}
