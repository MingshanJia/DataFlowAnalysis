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


int A[6000];
int t,n,k;
int P[200];

int main()
{
      scanf("%d",&t);
      FOR(t2,1,t)
      {
            scanf("%d",&k);
            scanf("%d",&n);
            REP(i,n) scanf("%d",P+i);
            REP(i,k) A[i] = 0;
            A[0] = 1;
            int ind = 0;
            FOR(i,2,k)
            {
                  int cnt = i;
                  while(cnt>0)
                  {
                        ind++;if(ind==k) ind=0;
                        if(!A[ind]) cnt--;
                  }
                  A[ind] = i;
            }
            
            printf("Case #%d:",t2);
            REP(i,n) printf(" %d",A[P[i]-1]);
            printf("\n");
      }
      return 0;
}
