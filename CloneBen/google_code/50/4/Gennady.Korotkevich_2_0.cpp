#include <bits/stdc++.h>

using namespace std;

vector <int> words[12345];
char foo[1234567];
int mp[1234567];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n;
    scanf("%d", &n);
    gets(foo);
    map <string, int> qwe;
    for (int i = 0; i < n; i++) {
      gets(foo);
      stringstream ss;
      for (int j = 0; foo[j]; j++) ss << foo[j];
      words[i].clear();
      string word;
      while (ss >> word) {
        if (qwe.find(word) == qwe.end()) {
          int id = qwe.size();
          qwe[word] = id;
        }
        words[i].push_back(qwe[word]);
      }
    }
    int word_cnt = qwe.size();
    int ans = (int)1e9;
    for (int i = 0; i < word_cnt; i++) mp[i] = 0;
      for (int i = 0; i < 2; i++) {
        int type;
        if (i == 0) type = 1; else
        if (i == 1) type = 2;
        for (int j = 0; j < (int)words[i].size(); j++) {
          mp[words[i][j]] += (type == 1 ? 1 : 100000);
        }
      }
    for (int t = 0; t < (1 << (n - 2)); t++) {
      for (int i = 2; i < n; i++) {
        int type;
        if (i == 0) type = 1; else
        if (i == 1) type = 2; else
        if (t & (1 << (i - 2))) type = 1;
        else type = 2;
        for (int j = 0; j < (int)words[i].size(); j++) {
          mp[words[i][j]] += (type == 1 ? 1 : 100000);
        }
      }
      int cnt = 0;
      for (int i = 0; i < word_cnt; i++) {
        int u = mp[i];
        cnt += (u % 100000 > 0 && u >= 100000);
      }
      ans = min(ans, cnt);
      for (int i = 2; i < n; i++) {
        int type;
        if (i == 0) type = 1; else
        if (i == 1) type = 2; else
        if (t & (1 << (i - 2))) type = 1;
        else type = 2;
        for (int j = 0; j < (int)words[i].size(); j++) {
          mp[words[i][j]] -= (type == 1 ? 1 : 100000);
        }
      }
    }
    printf("%d\n", ans);
    fflush(stdout);
    cerr << "test " << qq << " done" << endl;
  }
  return 0;
}
