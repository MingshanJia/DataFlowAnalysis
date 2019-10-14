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

int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const string tmp = "I/O";

void tidy()
{
  // clear all globals

}

vector<string> solve_test(int d, int n)
{
  vector<string>res(d);
  for (int i = 0; i < d; ++i) {
    res[i].resize(d, 'I');
  }
  int ii = 2, jj = 2;
  while (n > 0) {
    int cur = n % 8;
    if (cur == 0) cur = 8;
    n -= cur;
    for (int k = 0; k < cur; ++k) {
      for (int p = 0; p < 3; ++p) {
        res[ii + p*dx[k]][jj + p*dy[k]] = tmp[p];
      }
    }
    jj += 5;
    if (jj >= d) {
      jj = 2;
      ii += 5;
    }
  }
  return res;
}

int cnt(const vector<string> & vec)
{
  int res = 0;
  int sz = vec.size();
  for (int i = 2; i < sz - 2; ++i) {
    for (int j = 2; j < sz - 2; ++j) {
      for (int dir = 0; dir < 8; ++dir) {
        string cur = "";
        for (int k = 0; k < 3; ++k) {
          cur += vec[i + dx[dir] * k][j + dy[dir] * k];
        }
        if (cur == tmp) res++;
      }
    }
  }
  return res;
}

bool check(const vector<string> & vec, int d, int n)
{
  return (cnt(vec) == n);
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
    int d, n;
    scanf("%d%d", &d, &n);
    vector<string> res = solve_test(d, n);
    printf("Case #%d:\n", i + 1);
    for (int j = 0; j < res.size(); ++j) {
      cout << res[j] << endl;
    }

    //if (!check(res, d, n)) {
    //  puts("BAD");
    //}
  }

  return 0;
}