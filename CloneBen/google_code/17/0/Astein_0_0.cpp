#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  int n, m, b;
  for (int cn = 1; cn <= T; ++cn) {
    scanf("%d%d%d", &n, &m, &b);
    vector<pair<int, int> > a(m);
    vector<pair<int, pair<int, int> > > all_pairs;
    for (int i = 0; i < m; ++i) {
      scanf("%d%d", &a[i].first, &a[i].second);
    }
    for (int i = 0; i < m; ++i) {
      all_pairs.push_back(make_pair(a[i].first, make_pair(i, -1)));
      all_pairs.push_back(make_pair(a[i].first * 2, make_pair(i, i)));
      for (int j = i + 1; j < m; ++j) {
      	all_pairs.push_back(make_pair(a[i].first + a[j].first, make_pair(i, j)));
      }
    }
    sort(all_pairs.begin(), all_pairs.end());
    int ret = 0;
    for (int i = 0; i < all_pairs.size(); ++i) {
      if (all_pairs[i].first >= b) {
        int t1 = all_pairs[i].second.first;
        int t2 = all_pairs[i].second.second;
        if (t1 == t2) {
        	int nums = a[t1].second / 2;
        	if (nums > n) nums = n;
        	ret += nums * a[t1].first * 2;
        	a[t1].second -= nums * 2;
        	n -= nums;
        	if (n == 0) break;
          continue;
        }
        if (a[t1].second > 0 && (t2 == -1 || a[t2].second > 0)) {
          int nums = a[t1].second;
          if (t2 != -1 && nums > a[t2].second) nums = a[t2].second;
          if (nums > n) nums = n;

          ret += nums * a[t1].first;
          a[t1].second -= nums;
          if (t2 != -1) {
          	ret += a[t2].first * nums;
            a[t2].second -= nums;
           }
          n -= nums;
          if (n == 0) break;
        }
      }
    }
    if (n > 0) {
      printf("Case #%d: -1\n", cn);
    } else {
    	printf("Case #%d: %d\n", cn, ret);
    }
  }
}

