#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>

#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,p,k) for(int i=(p); i<=(k); ++i)

struct Build
{
  int x0,x1,y0,y1;
  bool cross(const Build &b) const
  { return std::max(x0,b.x0)<=std::min(x1,b.x1) && std::max(y0,b.y0)<=std::min(y1,b.y1); }
  void grow(){ x0--; x1++; y0--; y1++; }
};

int main()
{
  int t; std::cin >> t;
  FOR(_,1,t)
  {
    int w,h,b; scanf("%d%d%d",&w,&h,&b);
    std::vector<Build> B(b); REP(i,b) scanf("%d%d%d%d",&B[i].x0,&B[i].y0,&B[i].x1,&B[i].y1);
    int b0 = B.size(), b1 = B.size()+1;
    std::vector<int> A,I;
    REP(i,b) I.push_back(i); I.push_back(b1); A.push_back(b0);
    B.push_back(Build{-1,-1,0,h-1});
    B.push_back(Build{w,w,0,h-1});
    int res = 0;
    while(1)
    {
      bool ok = 1;
      REP(i,A.size())
      {
        int v = A[i]; B[v].grow();
        REP(j,I.size()) if(B[I[j]].cross(B[v]))
        {
          std::swap(I[j],I.back()); A.push_back(I.back()); I.pop_back();
          if(A.back()==b1) ok = 0; j--;
        }
      }
      if(!ok) break;
      res++;
    }
    printf("Case #%d: %d\n",_,res);
  }
  return 0;
}
