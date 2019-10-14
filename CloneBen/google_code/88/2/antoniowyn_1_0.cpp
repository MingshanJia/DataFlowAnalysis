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

#define maxn 110
#define maxc 310

int T, n, D, I, M;
int a[maxn];
int f[maxn][maxc];

bool vis[maxc];

inline void update(int &r, int x) {
  if (x < r) r = x;       
}

void dijkstra(int p) {
  for(int i = 0; i < 256; i++)
    vis[i] = false;
  while (1) {
    int min1 = infinity, min2 = -1;
    for(int i = 0; i < 256; i++)
      if (!vis[i] && f[p][i] < min1) min1 = f[p][i], min2 = i;
    if (min2 == -1) break;
    vis[min2] = true;
    for(int i = 0; i < 256; i++)
      if (abs(min2-i) <= M && min1 + I < f[p][i]) f[p][i] = min1 + I;      
  }
}

void doit() {
     
  for(int i = 0; i <= n; i++)
    for(int j = 0; j < 256; j++)
      f[i][j] = infinity;
  for(int i = 0; i < 256; i++)
    f[0][i] = 0;
    
  for(int i = 0; i < n; i++) {
    int nowcolor = a[i];
    for(int nc = 0; nc < 256; nc++)
      if (f[i][nc] != infinity) {
        int orig = f[i][nc];
        //Delete this block
        update(f[i+1][nc], orig + D);
        //Change the color
        for(int tc = 0; tc < 256; tc++)
          if (abs(tc-nc) <= M)
            update(f[i+1][tc], orig + abs(tc-nowcolor));             
      }
    dijkstra(i+1);        
  }
     
}

int main() {
    
  freopen("B-small.in", "rt", stdin);
  freopen("B-small.out", "wt", stdout);
  
  scanf("%d", &T);
  for(int tn = 1; tn <= T; tn++) {
          
    scanf("%d%d%d%d", &D, &I, &M, &n);
    memset(a,0,sizeof(a));
    for(int i = 0; i < n; i++)  scanf("%d", &a[i]);
    doit();
    int ans = D * n;
    for(int i = 0; i < 256; i++)
      ans = MIN(ans, f[n][i]);
    printf("Case #%d: %d\n", tn, ans);        
          
  }   
  
  return 0;
    
}
