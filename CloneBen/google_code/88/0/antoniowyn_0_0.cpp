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

#define maxn 55

int cinc[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

int T, n, kk;
char a[maxn][maxn], b[maxn][maxn];

inline bool inrange(int x, int y) {
  return 0<=x&&x<n && 0<=y&&y<n;       
}

void clockrotate(char a[][maxn], char b[][maxn]) {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      b[j][n-i-1] = a[i][j];
}

void gravity(char a[][maxn], char b[][maxn]) {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      b[i][j] = '.';
  for(int i = 0; i < n; i++) {
    int bp = 0;
    for(int j = 0; j < n; j++)
      if (a[i][j] != '.') b[i][bp++] = a[i][j];        
  }
}

bool check(char a[][maxn], char tar) {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) 
      if (a[i][j] == tar) {
        for(int k = 0; k < 8; k++) {
          bool flag = true;
          for(int t = 0; t < kk; t++) {
            int ti = i + cinc[k][0] * t, tj = j + cinc[k][1] * t;
            if (!inrange(ti, tj) || a[ti][tj] != tar) {flag = false; break; };        
          }
          if (flag) return true;        
        }
      }     
  return false;
}

int main() {
    
  freopen("A-small.in", "rt", stdin);
  freopen("A-small.out", "wt", stdout);
  
  scanf("%d\n", &T);
  for(int tn = 1; tn <= T; tn++) {
  
    scanf("%d %d\n", &n, &kk);
    memset(a,0,sizeof(a));
    for(int j = n-1; j >= 0; j--) {
      for(int i = 0; i < n; i++)
        a[i][j] = getchar();
      scanf("\n");        
    }
    
    clockrotate(a, b);
    
 /*   puts("b:");
    for(int j = n-1; j >= 0; j--) {
      for(int i = 0; i < n; i++)
        putchar(b[i][j]);
      puts("");
    }*/
    
    gravity(b, a);
    
    bool flag1 = check(a, 'R');
    bool flag2 = check(a, 'B');
    
    printf("Case #%d: ", tn);
    if (flag1 && flag2) puts("Both");
    else if (flag1 && !flag2) puts("Red");
    else if (!flag1 && flag2) puts("Blue");
    else puts("Neither");
    
  }   
  
  return 0;
    
}
