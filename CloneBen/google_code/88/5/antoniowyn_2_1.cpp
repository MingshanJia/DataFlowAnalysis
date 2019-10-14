#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <cassert>
using namespace std;
#define psb push_back
#define mpr make_pair
#define infinity 1000000010
#define mineps 1e-8
#define sqr(x) ((x)*(x))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)>(y)?(x):(y))
#define LL long long
#define UC unsigned long
#define UI unsigned int
#define pi 3.14159265358979323846 
inline int cmp(double x) {
  if (fabs(x) < mineps) return 0;
  else if (x < 0) return -1;
  else return 1;       
}
//////////////////////////////////////////////
//Start here

const int n = 1000000;

pair<int,int> a[1000010];
int nowi;

bool yes(int A, int B) {
  if (B < A) swap(A, B);
  if (A < nowi) {
    if (a[A].first <= B && B <= a[A].second) return false; else return true;      
  }
  else {
    for(int k = 1; k*B < A; k++)
      if (!yes(A-k*B, B)) return true;
    for(int k = 1; k*A < B; k++)
      if (!yes(A, B-k*A)) return true;
    return false;     
  }     
} 

int T;
int a1, a2, b1, b2;
LL ans;

int main() {
    
  freopen("C-large.in", "rt", stdin);
  freopen("C-large.out", "wt", stdout);
  
  a[1] = mpr(1, 1);
  for(int i = 2; i <= n; i++) {
    nowi = i;
    int p1 = a[i-1].first;
    while (yes(i, p1)) p1++;
    int p2 = MAX(a[i-1].second, p1);
    while (!yes(i, p2)) p2++;
    a[i] = mpr(p1, p2-1);        
  }
  
  scanf("%d", &T);
  for(int tn = 1; tn <= T; tn++) {
    scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
    ans = 0;
    for(int i = a1; i <= a2; i++) {
      LL p1 = a[i].first, p2 = a[i].second;
//      printf("%d: (%lld, %lld)\n", i, p1, p2);
      if (p1 < b1) p1 = b1;
      if (p2 > b2) p2 = b2;
      ans += b2-b1+1;
      if (p1 <= p2) ans -= p2-p1+1;
    }        
    
    printf("Case #%d: %lld\n", tn, ans);    
  }
  
  return 0;
    
}
