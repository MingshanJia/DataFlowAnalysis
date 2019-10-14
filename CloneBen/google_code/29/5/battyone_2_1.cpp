#include "std.h"

LL m[1000001][101];

LL go(int d, int b) {
  if (b < 1 || d < 1) return 0;
  if (b == 1) {
    return d;
  }
  d <?= 1000000;
  b <?= d; b <?= 100;
  return m[d][b];
}

int main() {
  int n;
  cin >> n;
  for (int d = 1; d <= 1000000; d++) for (int b = 1; b <= d && b <= 100; b++)
    m[d][b] = (m[d-1][b<?(d-1)] + 1 + m[d-1][b-1]) <? UINT_MAX;
  FOR(t, n) {
    unsigned f, d, b;
    cin >> f >> d >> b;
    cout << "Case #"<<(t+1)<<": ";
    LL ff = go(d, b);
    if (ff == UINT_MAX) cout <<  -1; else cout << ff;
    cout << ' ';
    assert(ff >= f);
    if (b == 1) {
      cout << f;
    }
    else for(int dd = 1; dd <= 1000000; dd++) { 
      ff = go(dd, b);
      //cerr << "dd="<<dd<<" b="<<b << " =>ff="<<ff<<endl;
      if (ff >= f) {cout << dd; break; }
      assert(dd<1000000);
    }
    for(int bb = 1; bb <= 100; bb++) {
      assert(bb<=100);
      ff = go(d, bb);
      //cerr << "d="<<d<<" bb="<<bb << " =>ff="<<ff<<endl;
      if (ff >= f) {cout << ' ' << bb; break;}
      assert(bb<100);
    }
    cout << endl;
  }
  return 0;
}
