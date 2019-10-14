#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>

#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,p,k) for(int i=(p); i<=(k); ++i)

int main()
{
  int t; std::cin >> t;
  FOR(_,1,t)
  {
     int A[2][1100]={};
     int n; scanf("%d",&n);
     std::vector<int> E(n); REP(i,n) scanf("%d",&E[i]);
     REP(i,n) REP(j,n) if(E[i]<E[j]) A[i<j][i]++;
     int res = 0; REP(i,n) res += std::min(A[0][i],A[1][i]);
     printf("Case #%d: %d\n",_,res);
  }
  return 0;
}
