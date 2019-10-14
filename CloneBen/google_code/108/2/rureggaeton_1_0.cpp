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

double solve_test()
{
  // solve for each testcase
  int n;
  cin >> n;
  n *= 2;
  vector<double>vec(n);
  vector<int>perm(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lf", &vec[i]);
    perm[i] = i;
  }
  double res = 0;
  do {
    double cur = 1;
    for (int i = 0; i < n; i += 2) {
      cur *= (1 - vec[perm[i]] * vec[perm[i + 1]]);
    }
    res = max(res, cur);
  } while (next_permutation(all(perm)));
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
    tidy();
    printf("Case #%d: %.6lf\n", i + 1, solve_test());
  }

  return 0;
}