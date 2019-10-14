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

int t,n,x,y,m;
int a,b,c,d;


pi D[200];
set<pi> S;

long long ilwek(pi a,pi b,pi c)
{
      return (a.fst - (long long)(c.fst))*(b.snd - c.snd) - (a.snd - (long long)(c.snd))*(b.fst - c.fst);
}

int main()
{
      scanf("%d",&t);
      FOR(t2,1,t)
      {
            int ans = 0;
            scanf("%d",&n);
            scanf("%d %d %d %d %d %d %d",&a,&b,&c,&d,&x,&y,&m);
            
            D[0] = pi(x,y);
//                  printf("%d %d\n",x,y);
            S.clear();
            S.insert(D[0]);
            FOR(i,1,n-1)
            {
                  x = (a*(long long)(x) + b)%m;
                  y = (c*(long long)(y) + d)%m;
                  D[i] = pi(x,y);
//                  printf("%d %d\n",x,y);
                  S.insert(D[i]);
            }
            
            REP(i,n) REP(j,i) REP(k,j)
            {
                  long long xx = D[i].fst;
                  long long yy = D[i].snd;
                  xx+=D[j].fst + D[k].fst;
                  yy+=D[j].snd + D[k].snd;
                  if(xx%3 == 0 && yy%3==0 /*&& ilwek(D[i],D[j],D[k])!=0*/) ans++;
            }
            
            printf("Case #%d: %d\n",t2,ans);
      }
      return 0;
}
