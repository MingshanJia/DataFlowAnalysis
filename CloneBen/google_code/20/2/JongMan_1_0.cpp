#include<cstdio>
#include<cassert>
#include<cstring>
#include<map>
#include<set>
#include<time.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<utility>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

char op;
string a, b, c;

int checked[251][20][2][2][2];

bool matches(char ch, int digit, int hasDigit, int idx) {
  if(ch == '.') return digit == 0;
  if(ch == '?') return (digit > 0 || hasDigit || idx == a.size()-1);
  return digit == ch - '0';
}

int operate(int a, int b) {
  return op == '+' ? a + b : a - b;
}

string as, bs, cs;

string strip(string s) {
  int left = 0;
  while(left + 1 < s.size() && s[left] == '0') ++left;
  return s.substr(left);
}

string ret;

void go(int idx, int needToCarry, int aHasDigit, int bHasDigit, int cHasDigit) {
  if(idx == a.size()) {
    if(needToCarry == 0) {
      assert(operate(atoi(strip(as).c_str()), atoi(strip(bs).c_str())) ==
             atoi(strip(cs).c_str()));
      string cand = strip(as) + ' ' + op + ' ' + strip(bs) + " = " + strip(cs);
      ret = min(cand, ret);
    }
    return;
  }
  for(int ad = 0; ad < 10; ++ad) if(matches(a[idx], ad, aHasDigit, idx))
    for(int bd = 0; bd < 10; ++bd) if(matches(b[idx], bd, bHasDigit, idx))
      for(int cd = 0; cd < 10; ++cd) if(matches(c[idx], cd, cHasDigit, idx)) {
        for(int carried = -9; carried <= 9; ++carried) {
          if(op == '+' && carried < 0) continue;
          if(op == '-' && carried > 0) continue;
          int sum = operate(ad, bd) + carried;
          if((sum + 30) % 10 != cd) continue;
          int willCarry = 0;
          if(op == '+')
            willCarry = sum / 10;
          else if(sum < 0)
            willCarry = -1;
          if(willCarry == needToCarry) {
            as[idx] = ad + '0';
            bs[idx] = bd + '0';
            cs[idx] = cd + '0';
            go(idx + 1, carried, aHasDigit || ad, bHasDigit || bd, cHasDigit || cd);
          }
        }
      }
}

int main() {
  int cases;
  cin >> cases;
  for(int cc = 0; cc < cases; ++cc) {
    memset(checked, -1, sizeof(checked));
    string o, eq;
    cin >> a >> o >> b >> eq >> c;
    op = o[0];
    int len = max(a.size(), max(b.size(), c.size()));
    a = string(len - a.size(), '.') + a;
    b = string(len - b.size(), '.') + b;
    c = string(len - c.size(), '.') + c;
    as = a;
    bs = b;
    cs = c;
    ret = "z";
    go(0, 0, 0, 0, 0);
    cout << "Case #" << (cc+1) << ": " << ret << endl;
  }
}

