#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

char buff[128];

int main() {
  int N;
  scanf("%d", &N);
  for (int u = 1; u <= N; ++u) {
    int S;
    scanf("%d", &S);
    vector<int> r, b;
    for (int i = 0; i < S; ++i) {
      scanf("%s", buff);
      string x(buff);
      char c = x[x.length() - 1];
      x = x.substr(0, x.length() - 1);
      stringstream ss;
      ss << x;
      int l;
      ss >> l;
      if (c == 'B') b.push_back(l);
      else r.push_back(l);
    }
    sort(r.begin(), r.end());
    reverse(r.begin(), r.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    
    int half = min((int)r.size(), min(S / 2, (int)b.size()));
    int total = 0;
    for (int i = 0; i < half; ++i) {
      total += r[i] + b[i] - 2;
    }
    printf("Case #%d: %d\n", u, total);
  }
}

