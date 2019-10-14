#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;
vector<long long> T;

pair<double, double> d(int x, int y, double E) {
  double dd = T[x] - T[y];
  double dl = x-y;
  double a = (dd - 2*E) / dl;
  double b = (dd + 2*E) / dl;
  if(a > b)
    swap(a, b);
  return make_pair(a, b);
}

bool  mag(double E) {
    pair<double, double> m = make_pair(-INFINITY, INFINITY);
    for(unsigned j = 0; j < T.size(); ++j) 
      for(unsigned k = j+1; k < T.size(); ++k) {
        pair<double, double> i = d(j, k, E);
        m.first = max(m.first, i.first);
        m.second = min(m.second, i.second);
        if(m.second < m.first - 1e-9) return false;
      }
    return true;
}

void doit(int casenum) {
  int N;
  cin >> N;
  T.resize(N);
  for(unsigned i = 0; i < N; ++i)
    cin >> T[i];
  double lo = 0.0;
  double hi = 2 * T.back() - T.front() + 2.0;
  while(hi - lo > 1e-8) {
    double mid = (lo + hi) / 2;
    (mag(mid) ? hi : lo) = mid;
  }
  cout.precision(8);
  cout << "Case #" << casenum << ": " << hi << endl;
}
int main(int argc, char **argv) {
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i)
      doit(i);
    return 0;
}
