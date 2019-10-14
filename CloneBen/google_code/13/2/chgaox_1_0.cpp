#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int main()
{
  int cases;

  scanf("%d", &cases);
  
  double PI = acos(-1.0);

  int N = 0;
  while(N < cases)
  {
    N++;

    int V, D;
    scanf("%d %d", &V, &D);

    double g = 9.8;
    double sin_angle = (D * g) / V / V;
    //printf("sin angle %f\n", sin_angle);
    if (sin_angle > 0.9999999999999)
    {
      sin_angle = 1.0;
    }
    double angle = asin(sin_angle);
    //printf("angle %f\n", angle);
    double ans = angle / 2.0 / PI * 180.0;

    printf("Case #%d: %.7f\n", N, ans);
  }
  return 0;
}
