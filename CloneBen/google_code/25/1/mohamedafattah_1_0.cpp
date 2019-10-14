#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;

int N, T;
int g[1024][1024];
bool vis[1024];

int go(int n) {
  vis[n] = true;
  int r = 0, d = 0;
  for (int i = 0; i < N; ++i)
    if (g[n][i]) {
      d += g[n][i];
      if (!vis[i]) r += go(i);
    }
  if (d&1) ++r;
  if (d == 0) return -1;
  return r;
}

int main() {
  int K;
  cin >> K;
  for (int kase = 1; kase <= K; ++kase) {
    cin >> N >> T;
    if (kase == 9 || kase == 12) cerr << N << " " << T << endl;
    memset(g, 0, sizeof(g));
    memset(vis, false, sizeof(vis));
    for (int c = 0; c < T; ++c) {
      int a, b;
      cin >> a >> b;
      if (kase == 9 || kase == 12) cerr << a << " " << b << endl;
      ++g[a][b]; ++g[b][a];
    }
    int r = 0;
    int even = 0, ep = 0, odddeg = 0;
    int flag = 0;
    for (int i = 0; i < N; ++i)
      if (!vis[i]) {
        int x = go(i);
        //cerr << i << ": " << x << endl;
        if (x == -1) continue;
        if (flag++ == 1) cerr << "Yawza at " << kase << endl;
        if (x) {
          odddeg += x;
          r += x/2 - 1;
          ++ep;
        } else ++even;
      }
    cerr << "   " << r << " " << ep << " " << even << endl;
    if (even == 1 && ep == 0) r = 0;
    else r += ep + even;
    //assert((T + r) % 2 == 0);
    if (r > odddeg / 2 || odddeg % 2 != 0) cerr << "Ooops " << kase << "    "  << r <<  " " << odddeg << endl;
    cout << "Case #" << kase << ": " << r << endl;
  }
  return 0;
}

