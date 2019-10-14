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



void tidy()
{
  // clear all globals

}

double solve_slow(int n, vector<double> vec)
{
  // solve for each testcase
  n *= 2;
  vector<int>perm(n);
  for (int i = 0; i < n; ++i) {
    perm[i] = i;
  }
  double res = -1;
  vector<int> best_perm;
  do {
    double cur = 1;
    for (int i = 0; i < n; i += 2) {
      cur *= (1 - vec[perm[i]] * vec[perm[i+1]]);
    }
    if (cur > res) {
      res = cur;
      best_perm = perm;
    }
  } while (next_permutation(all(perm)));
  for (int i = 0; i < n; ++i) {
    cout << best_perm[i] << " ";
  }
  cout << endl;
  return res;
}

double solve_1(int n, vector<double> vec)
{
  double res = 1;
  for (int i = 0; i < n; i++) {
    res *= (1-vec[2*i] * vec[2*i + 1]);
  }
  return res;
}

double solve_2(int n, vector<double> vec)
{
  double res = 1;
  for (int i = 0; i < n; i++) {
    res *= (1- vec[i] * vec[i + n]);
  }
  return res;
}

double solve_3(int n, vector<double> vec)
{
  double res = 1;
  for (int i = 0; i < n; i++) {
    res *= (1 - vec[i]*vec[2*n-1-i]);
  }
  return res;
}

double solve_clever(int n, vector<double> vec)
{
  double res = solve_1(n, vec);
  res = max(res, solve_2(n, vec));
  res = max(res, solve_3(n, vec));
  return res;
}

double solve_superclecver(int n, vector<double> vec)
{
  vector<vector<double>> dp(2 * n+1, vector<double>(2 * n+1, 1));
  for (int len = 2; len <= 2 * n; len += 2) {
    for (int start = 0; start + len <= 2 * n; ++start) {
      int end = start + len - 1;
      int mid = start + len / 2 - 1;
      double a = (1 - vec[start] * vec[start + 1]) * dp[start + 2][end];
      double b = (1 - vec[start] * vec[end]) * dp[start + 1][end - 1];
      double c = (1 - vec[start] * vec[mid]) * dp[start + 1][mid - 1] * dp[mid + 1][end];
      dp[start][end] = max(a, max(b, c));
    }
  }
  return dp[0][2 * n - 1];
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
    scanf("%d", &n);
    vector<double>vec(2 * n);
    for (int j = 0; j < 2 * n; ++j) {
      scanf("%lf", &vec[j]);
    }
    sort(all(vec));
   
    double clever = solve_clever(n, vec);
    printf("Case #%d: %.6lf\n", i + 1, clever);
  }

  return 0;
}