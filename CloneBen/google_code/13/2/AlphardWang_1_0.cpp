#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

double v, d, a = 9.8, pi = acos(-1);

int main(){
  int C;
  scanf("%d", &C);
  for (int c = 1; c <= C; ++ c) {
    scanf("%lf%lf", &v, &d);
    double s2q = asin(d * a / (v * v));
    printf("Case #%d: %lf\n", c, s2q / 2 / pi * 180);
  }
  return 0;
}

