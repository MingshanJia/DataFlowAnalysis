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

const int NumH = 24;

int amountTime(int h1, int h2) {
  if (h1 <= h2) {
    return h2 - h1;
  } else {
    return NumH - (h1 - h2);
  }
}

struct MST {
  int sz;
  vector<int> fuParent;
  vector<tuple<int,int,int>> edges;

  MST(int N) : sz(N), fuParent(N) {
    iota(ALL(fuParent), 0);
  }

  int fuFind(int v) {
    if (fuParent[v] == v) { return v; }
    return fuParent[v] = fuFind(fuParent[v]);
  }

  bool fuUnion(int a, int b) {
    a = fuFind(a); b = fuFind(b);
    if (a == b) { return false; }
    fuParent[a] = b;
    return true;
  }

  void addEdge(int u, int v, int c) {
    edges.emplace_back(c, u, v);
  }


  int getMST() {
    sort(ALL(edges));
    int result = 0;
    for (auto &E : edges) {
      int c, u, v;
      tie(c, u, v) = E;
      if (fuUnion(u, v)) { result += c; }
    }

    for (int i = 0; i < sz; i++) {
      if (fuFind(i) != fuFind(0)) { return -1; }
    }

    return result;
  }
};

struct Testcase {
  vector<int> startI, endI, hStartI, hEndI, hTime;
  int N;
  vector<VI> idsIn, idsOut;
  vector<int> costStraight, costCross, costChange;
  vector<int> nextEdge;
  vector<PII> sampleOmit;

  int startEdge;

  int getCost(int from, int to) {
    if (to == startEdge) {
      return hTime[from];
    }
    return hTime[from] + amountTime(hEndI[from], hStartI[to]);
  }

  int getRes(int start) {
    startEdge = start;

    costStraight.resize(N);
    costCross.resize(N);
    costChange.resize(N);
    nextEdge.resize(2 * N);
    sampleOmit.resize(2 * N);

    int result = hStartI[startEdge];


    for (int v = 0; v < N; v++) {
      costStraight[v] = getCost(idsIn[v][0], idsOut[v][0]) +
                        getCost(idsIn[v][1], idsOut[v][1]);
      costCross[v]    = getCost(idsIn[v][0], idsOut[v][1]) +
                        getCost(idsIn[v][1], idsOut[v][0]);

      debug(v, idsIn[v], idsOut[v], costStraight[v], costCross[v]);

      if (costStraight[v] <= costCross[v]) {
        nextEdge[idsIn[v][0]] = idsOut[v][0];
        nextEdge[idsIn[v][1]] = idsOut[v][1];
        result += costStraight[v];
        costChange[v] = costCross[v] - costStraight[v];
        sampleOmit[v] = PII(idsIn[v][0], idsOut[v][1]);
      } else {
        nextEdge[idsIn[v][0]] = idsOut[v][1];
        nextEdge[idsIn[v][1]] = idsOut[v][0];
        result += costCross[v];
        costChange[v] = costStraight[v] - costCross[v];
        sampleOmit[v] = PII(idsIn[v][0], idsOut[v][0]);
      }
    }

    vector<bool> visited(2 * N);
    vector<int> idCycle(2 * N);
    int numCycs = 0;

    for (int i = 0; i < 2 * N; i++) {
      if (visited[i]) { continue; }
      int ptr = i;

      do {
        visited[ptr] = true;
        idCycle[ptr] = numCycs;
        ptr = nextEdge[ptr];
      } while (ptr != i);
      numCycs++;
    }

    
    debug(numCycs);
    MST mst(numCycs);
    for (int v = 0; v < N; v++) {
      int a, b;
      tie(a, b) = sampleOmit[v];
      a = idCycle[a]; b = idCycle[b];
      if (a != b) { mst.addEdge(a, b, costChange[v]); }
    }

    int nres = mst.getMST();
    assert(nres != -1);

    debug(startEdge, result, nres);

    return result + nres;
  }

  void run(int tid) {
    cin >> N;
    idsIn.resize(N);
    idsOut.resize(N);

    for (int i = 0; i < 2 * N; i++) {
      int e, s, l;
      startI.PB(i / 2);
      cin >> e >> s >> l;
      e--;
      endI.PB(e);
      hStartI.PB(s);
      hEndI.PB((s + l) % 24);
      hTime.PB(l);

      idsIn[e].PB(i);
      idsOut[i / 2].PB(i);
    }


    cout << "Case #" << tid << ": " <<
        min(getRes(0), getRes(1)) << "\n";
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
