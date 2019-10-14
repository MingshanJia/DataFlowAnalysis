#include "std.h"

int main() {
  int n;
  cin >> n;
  FOR(t, n) {
    string num, src, dst;
    cin >> num >> src >> dst;
    int c = 0;
    int b = src.size();
    int p = 1;
    FOR(i, num.size()) {
      FOR(d, b) if (num[num.size()-1-i] == src[d]) { c += d * p; break; }
      p *= b;
    }
    //    cerr << "c="<<c<<endl;
    string r;
    while (c) {
      int d = c % dst.size();
      c /= dst.size();
      r = dst[d] + r;
    }
    cout << "Case #"<<(t+1)<<": "<<r<<endl;
  }
  return 0;
}
