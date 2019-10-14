#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#pragma comment(linker, "/STACK:130000000")
#include <stdio.h>
#include <iostream>
#include <climits>
#include <algorithm>
#include <random>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <map>
#include <set>
#include <stack>
#include <bitset>
using namespace std;


#define mp make_pair
#define all(x) x.begin(),x.end()

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;

/*
struct set_cmp {
bool operator()(const int& a, const int& b){
return a > b;
}
};*/

#define TIMESTAMP cout << "\nTime: " << (double)clock() / CLOCKS_PER_SEC\n;

template<typename T> T gcd(T a, T b)
{
  return ((!b) ? a : gcd(b, a%b));
}
template<typename T>T gcd(T a, T b, T&x, T&y)
{
  if (!a) {
    x = 0, y = 1; return b;
  }T x1, y1; T d = gcd(b%a, a, x1, y1); x = y1 - (b / a)*x1; y = x1; return d;
}
template<typename T> T lcm(T a, T b)
{
  return (a / gcd(a, b))*b;
}
template<typename T, typename M> T neg_mod(T a, M mod)
{
  return ((a%mod) + mod) % mod;
}
ll binpow(ll x, ll p)
{
  ll res = 1; while (p) {
    if (p & 1) res *= x; x *= x; p >>= 1;
  }return res;
}
ll binpow_mod(ll x, ll p, ll m)
{
  ll res = 1; while (p) {
    if (p & 1) res = (res*x) % m; x = (x*x) % m; p >>= 1;
  }return res;
}

int b;
ll dist[101][101];
const ll INF = 100000000000000LL; // 1e14

void tidy()
{
  // clear all globals

}

double calc(int fr, int to, double pos)
{
  double longest = 0;
  for (int i = 0; i < b; ++i) {
    double cur = dist[i][fr] + pos;
    cur = min(cur, dist[i][to] + (dist[fr][to] - pos));
    longest = max(longest, cur);
  }
  return longest;
}

double solve()
{
  //for (int i = 0; i < b; ++i) {
  //  for (int j = 0; j < b; ++j) {
  //    printf("%I64d ", dist[i][j]);
  //  }
  //  cout << endl;
  //}
  //cout << endl;
  for (int k = 0; k < b; ++k) {
    for (int i = 0; i < b; ++i) {
      for (int j = 0; j < b; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  //for (int i = 0; i < b; ++i) {
  //  for (int j = 0; j < b; ++j) {
  //    printf("%I64d ", dist[i][j]);
  //  }
  //  cout << endl;
  //}
  //cout << endl;
  double res = 1e20;
  for (int i = 0; i < b; ++i) {
    for (int j = i + 1; j < b; ++j) {
      if (dist[i][j] < INF) {
        double le = 0, ri = dist[i][j];
        for (int k = 0; k < 300; ++k) {
          double m1 = le + (ri - le) / 3;
          double m2 = ri - (ri - le) / 3;
          double f1 = calc(i,j, m1);
          double f2 = calc(i, j, m2);
          if (f1 < f2) {
            ri = m2;
          }
          else {
            le = m1;
          }
        }
        res = min(res, calc(i,j, le));
      }
    }
  }
  return res;
}

void print_ans()
{

}

int main()
{
  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

  int tests_cnt;
  cin >> tests_cnt;

  for (int i = 0; i < tests_cnt; ++i) {
    int n;
    scanf("%d", &b);
    for (int j = 1; j < b; ++j) {
      for (int k = 0; k < j; ++k) {
        scanf("%I64d", &dist[j][k]);
        if (dist[j][k] == -1) {
          dist[j][k] = INF;
        }
        dist[k][j] = dist[j][k];
      }
    }
    printf("Case #%d: %.7lf\n", i + 1, solve());
  }

  return 0;
}