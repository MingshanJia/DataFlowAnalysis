//MADE BY lordmonsoon A.I.
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<iostream>
#include<utility>
#include<bitset>

using namespace std;

#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pi>
#define fst first
#define snd second
#define pb push_back
#define SIZE(a) (int)(a.size())
#define LENGTH(a) (int)(a.length())
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FOR(i,n,m) for(int i=(n);i<=(m);i++)
#define FORD(i,n,m) for(int i=(n);i>=(m);i--)
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define ABS(a) ( (a)<0 ? -(a) : (a))
#define STRUMIEN(A,B) istringstream A(B)
#define SORT(A) sort(A.begin(),A.end())


////////////////////////////////////////////////////////////////////////////////

int t,a,b,p;
int PR[1001],pr;
int F[3000];

int find(int p)
{
      if(F[p]!=p) F[p] = find(F[p]);
      return F[p];
}

void unite(int a,int b)
{
      a = find(a);
      b = find(b);
      F[a] = b;
}

int main()
{
      scanf("%d",&t);
      FOR(t2,1,t)
      {
            scanf("%d %d %d",&a,&b,&p);
            int ans = 0;
            pr = 0;
            FOR(i,p,b)
            {
                  int j = 2, gut = 1;
                  while(j*j<=i)
                  {
                        if(i%j == 0) gut = 0;
                        j++;
                  }
                  if(gut) PR[pr++] = i;
            }
            FOR(i,a,b) F[i] = i;
            
            FOR(i,a,b) FOR(j,a,i-1) if(find(i)!=find(j))
            {
                  bool gut = false;
                  REP(k,pr) if(i%PR[k]==0 && j%PR[k]==0) {gut=true;break;}
                  if(gut) unite(i,j);
            }
            FOR(i,a,b) if(F[i]==i) ans++;
            printf("Case #%d: %d\n",t2,ans);
      }
      return 0;
}
