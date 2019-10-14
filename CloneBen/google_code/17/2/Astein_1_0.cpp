#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int> > pos;
int N, R;

double calc(int x, double y) {
  vector<pair<double, double> > tmp;
  tmp.push_back(make_pair(-R, 0));
  tmp.push_back(make_pair(R, 0));
  //cout << "x = " << x << " y = " << y << endl;
  for (int i = 0; i < N; ++i) {
    if (pos[i].first == x) continue;
    double a = pos[i].first;
    double b = pos[i].second;
    //theta1;
    double d = sqrt(x * x + y * y);
    double x1 = sqrt((x - a) * (x - a) + (y - b) * (y - b));
    double r1 = sqrt(a * a + b * b);
    double cost1 = (x1 * x1 + d * d - r1 * r1) / (2.0 * d * x1);
    //cout << "d = " << d << endl;
    //cout << "x1 = " << x1 << endl;
    //cout << "r1 = " << r1 << endl;
    //cout << cost1 << endl;
    double x2 = d * cost1 + sqrt((d * d * (cost1 * cost1 - 1)) + R * R);
    double x3 = d * cost1 - sqrt((d * d * (cost1 * cost1 - 1)) + R * R);
    if (x3 > 0) while(1);
    //cout << x2 << "," << x3 << endl;
    double dx = a - x, dy = b - y;
    double xx = x + dx * (x2 / x1), yy = y + dy * (x2 / x1);
    //cout << xx << "," << yy << "," << sqrt(xx * xx + yy * yy) << endl;
    if (yy < 0) continue;
    /*{
    	cout << xx << "," << yy << endl;
      while(1);
    }*/
    tmp.push_back(make_pair(xx, yy));
  }
  sort(tmp.begin(), tmp.end());
  for (int i = 0; i < tmp.size(); ++i) {
    if (tmp[i].first < x && x < tmp[i + 1].first) {
      //cout << tmp[i].first << "," << tmp[i].second << " -- " << tmp[i + 1].first << "," << tmp[i + 1].second << endl;
      double t1 = atan2(tmp[i].first, tmp[i].second);
      double t2 = atan2(tmp[i + 1].first, tmp[i + 1].second);
      //cout << (t2 - t1) * 12 / (3.141592653589793) << endl;
      return (t2 - t1) * 12 / 3.1415926535897;
    }
  }
  return 0;
}

int main() {
	int T;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; ++cn) {
  	int H;
    scanf("%d%d%d", &N, &R, &H);
    pos.resize(N);
    double sum = 0.0;
    for (int i = 0; i < N; ++i) {
    	scanf("%d%d", &pos[i].first, &pos[i].second);
      sum += pos[i].second;
    }
    sort(pos.begin(), pos.end());
    double ret = 0.0;

    for (int i = 0; i < N; ++i) {
      double minh = 0, maxh = pos[i].second;
      for (int j = 0; j < 100; ++j) {
      	double mid = (minh + maxh) * 0.5;
      	//cout << calc(pos[i].first, mid) << endl;
      	if (calc(pos[i].first, mid) >= H) {
          maxh = mid;
        } else {
          minh = mid;
        }
      }
      ret += (pos[i].second - minh);
      //printf("%d, %lf, %lf\n", pos[i].first, minh, maxh);
    }
    printf("Case #%d: %.8lf\n", cn, ret / sum);
  }
}

