#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  //freopen("A-large.in", "r", stdin);
  //freopen("A-large.out", "w", stdout);
  int K;
  cin >> K;
  for (int kase = 1; kase <= K; ++kase) {
    int N;
    cin >> N;
    vector<pair<double, string> > in(N);
    vector<string> ans;
    for (int c = 0; c < N; ++c) {
      cin >> in[c].second;
      stringstream ss(in[c].second);
      ss >> in[c].first;
      in[c].first *= 3;
    }
    sort(in.begin(), in.end());
    int round = 0;
    while (in.size()) {
      if (round++ > 16) break;
      for (size_t i = 0; i < in.size(); ++i)
        if (in[i].first >= 1 && in[i].first <= 2) {
          ans.push_back(in[i].second);
          //cerr << round  << " " << in[i].second << endl;
          in.erase(in.begin() + i);
          --i;
        }
      for (size_t i = 0; i < in.size(); ++i) {
        if (in[i].first > 2) in[i].first -= 2;
        in[i].first *= 3;
      }
    }
    for (size_t i = 0; i < in.size(); ++i)
      ans.push_back(in[i].second);
    
    printf("Case #%d:\n", kase);
    for (size_t i = 0; i < ans.size(); ++i)
      printf("%s\n", ans[i].c_str());
  }
  return 0;
}

