#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<set>

#include<vector>
using namespace std;
int ar[10];
int used[10];
int tc, nguests, ntables;

set<vector<pair<int, int> > > neighbor_set;


void permute(int n, int cur) {
  if (cur == n) {
    pair<int, int> neighbor[10];
    int last = 0;
    for (int i = 0; i < ntables; i++) {
      int num_in_table = nguests/ ntables;
      if (i < (nguests % ntables))
        num_in_table++;

        if (num_in_table == 1) {
          neighbor[ar[last]] = make_pair(-1, -1);
        }
        else if (num_in_table == 2) {
          neighbor[ar[last]] = make_pair(-1, ar[last+1]);
          neighbor[ar[last+1]] = make_pair(-1, ar[last]);
        } else {
          for (int j = last; j < last + num_in_table; j++) {
    
            if (j == last)
              neighbor[ar[j]] = make_pair(ar[last+num_in_table-1], ar[j+1]);
            else if (j == last + num_in_table - 1)
              neighbor[ar[j]] = make_pair(ar[j-1], ar[last]);
            else
              neighbor[ar[j]] = make_pair(ar[j-1], ar[j+1]);
          }
        }
      last = last + num_in_table;
    }

    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
      pair<int, int> temp;
      temp.first = min(neighbor[i].first, neighbor[i].second);
      temp.second = max(neighbor[i].first, neighbor[i].second);
      v.push_back(temp);
    }
    neighbor_set.insert(v);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      used[i] = 1;
      ar[cur] = i;
      permute(n, cur+1);
      ar[cur] = 0;
      used[i] = 0;
    }
  }
}


int main() {
  scanf("%d", &tc);
  for (int t = 0; t < tc; t++) {
    scanf("%d %d", &nguests, &ntables);
    memset(ar, 0, sizeof(ar));
    memset(used, 0, sizeof(used));
    neighbor_set.clear();
    permute(nguests,0);
    printf("Case #%d: %d\n", t+1, int(neighbor_set.size()));
  }
}
