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
    int n,x; scanf("%d%d",&n,&x);
    std::vector<int> A(n);
    REP(i,n) scanf("%d",&A[i]);
    std::sort(A.begin(),A.end());
    int res = 0; int j = n-1;
    REP(i,n)
    {
      while(j>i && A[i]+A[j]>x){ j--; res++; }
      res++;
      if(i==j) break;
      if(A[i]+A[j]<=x) j--; 
      if(i==j) break;
    }
    printf("Case #%d: %d\n",_,res);
  }
  return 0;
}
