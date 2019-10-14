#include <cstdio>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <map>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

// init(n)            ==> resetira i postavi broj cvorova
// edge(x, y, c1, c2) ==> doda edge x->y kapaciteta c1 i edge y->x kapaciteta c2
// run(src, sink)     ==> pokrene algoritam i vrati flow
// odredi: konstanta MAXV
// odredi: konstanta MAXE (barem 2*edge_poziva)
// odredi: konstanta oo (max kapacitet)

namespace Dinic {
  const int MAXV = 1000100;
  const int MAXE = 1000100;
  const llint oo = 1e18;

  int V, E;
  int last[MAXV], dist[MAXV], curr[MAXV];
  int next[MAXE], adj[MAXE]; llint cap[MAXE];

  void init(int n) {
    V = n;
    E = 0;
    REP(i, V) last[i] = -1;
  }

  void edge(int x, int y, llint c1, llint c2) {
    adj[E] = y; cap[E] = c1; next[E] = last[x]; last[x] = E++;
    adj[E] = x; cap[E] = c2; next[E] = last[y]; last[y] = E++;
  }

  llint push(int x, int sink, llint flow) {
    if (x == sink) return flow;

    for (int &e = curr[x]; e != -1; e = next[e]) {
      int y = adj[e];

      if (cap[e] && dist[x] + 1 == dist[y])
        if (llint f = push(y, sink, min(flow, cap[e])))
          return cap[e] -= f, cap[e^1] += f, f;
    }
    return 0;
  }

  llint run(int src, int sink) {
    llint ret = 0;
    for (;;) {
      REP(i, V) curr[i] = last[i];
      REP(i, V) dist[i] = -1;

      queue<int> Q;
      Q.push(src), dist[src] = 0;

      while (!Q.empty()) {
        int x = Q.front(); Q.pop();

        for (int e = last[x]; e != -1; e = next[e]) {
          int y = adj[e];
          if (cap[e] && dist[y] == -1) Q.push(y), dist[y] = dist[x] + 1;
        }
      }
      if (dist[sink] == -1) break;

      while (llint f = push(src, sink, oo)) ret += f;
    }
    return ret;
  }
}

const int MAX = 50100;
const int oo = 1e9;

int N, K;
vector<int> lines[MAX];

bool eng[MAX];
bool french[MAX];

int main() {
  int T;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt, fflush(stdout)) {
    scanf("%d ", &N);
    K = 0;

    map<string, int> idx;
    REP(i, N) {
      static char buf[1<<20];
      scanf(" %[^\n]s", buf);

      stringstream ss(buf);
      lines[i].clear();

      for (string w; ss >> w;) {
        if (!idx.count(w)) idx[w] = K++;
        lines[i].push_back(idx[w]);
      }
    }

    int V = K*2;
    int src = V++;
    int sink = V++;
    Dinic::init(V);

    for (int w : lines[0]) Dinic::edge(src, w, oo, 0);
    for (int w : lines[1]) Dinic::edge(K+w, sink, oo, 0);
    REP(i, K) Dinic::edge(i, K+i, 1, 0);

    REP(w, K) {
      FOR(i, 2, N) {
        bool ima = false;
        for (int x : lines[i]) ima |= x == w;
        if (ima) for (int x : lines[i]) if (x != w) Dinic::edge(K+w, x, oo, 0);
      }
    }

    printf("Case #%d: %lld\n", tt, Dinic::run(src, sink));
  }
  return 0;
}
