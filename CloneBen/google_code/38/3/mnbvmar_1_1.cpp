#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
#define LD long double

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
} 

template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}


#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif


struct Testcase {
  vector<vector<tuple<int,int,bool>>> adj;
  vector<vector<PII>> dirAdj;
  vector<PII> edges, dirEdges;
  int N, M;
  vector<bool> sameOrient;
  VI visited;

  void dfs(int v, int pid = -1) {
    visited[v] = 1;

    for (auto &E : adj[v]) {
      int s, id;
      bool same;
      tie(s, id, same) = E;
      debug(v, s, id, same);

      if (id == pid) { continue; }

      if (visited[s]) {
        if (visited[s] == 1) {
          sameOrient[id] = same;
        }
        continue;
      }

      sameOrient[id] = same;
      dfs(s, id);
    }

    visited[v] = 2;
  }


  VI path, totalRes;

  bool dfsFindPath(int from, int to) {
    if (from == to) { return true; }
    visited[from] = 1;

    for (auto &E : dirAdj[from]) {
      if (visited[E.st]) { continue; }
      if (dfsFindPath(E.st, to)) {
        path.PB(E.nd);
        return true;
      }
    }
    return false;
  }

  bool findPath(int from, int to) {
    path.clear();
    fill(ALL(visited), 0);
    return dfsFindPath(from, to);
  }


  void run(int tid) {
    cin >> N >> M;
    adj.resize(N);

    debug(tid);
    for (int i = 0; i < M; i++) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      debug(u, v);
      adj[u].emplace_back(v, i, true);
      adj[v].emplace_back(u, i, false);
      edges.emplace_back(u, v);
    }

    sameOrient.resize(M, false);
    visited.resize(N, 0);

    for (int i = 0; i < N; i++) {
      if (!visited[i]) {
        dfs(i);
      }
    }

    dirAdj.resize(N);


    for (int i = 0; i < M; i++) {
      int u = edges[i].st, v = edges[i].nd;
      if (!sameOrient[i]) { swap(u, v); }
      debug("!", u, v);
      dirEdges.emplace_back(u, v);
      dirAdj[u].emplace_back(v, i);
    }

    bool fail = false;
    totalRes.resize(M);

    for (int i = 0; i < M; i++) {
      path.clear();
      if (!findPath(dirEdges[i].nd, dirEdges[i].st)) {
        fail = true;
        break;
      }
      path.push_back(i);

      for (int v : path) {
        totalRes[v]++;
      }
    }

    cout << "Case #" << tid << ":";

    if (fail) {
      cout << " IMPOSSIBLE\n";
    } else {
      vector<int> sumVerts(N);

      for (int i = 0; i < M; i++) {
        int u = edges[i].st, v = edges[i].nd;
        int res = totalRes[i];
        assert(res > 0 && res < N * N);
        if (!sameOrient[i]) { res = -res; }
        cout << " " << res;
        sumVerts[u] += res;
        sumVerts[v] -= res;
      }

      for (int i = 0; i < N; i++) {
        assert(sumVerts[i] == 0);
      }

      cout << "\n";
    }
  }
};



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    Testcase tc;
    tc.run(i);
  }
}
