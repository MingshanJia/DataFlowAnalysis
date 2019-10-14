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
int n;
char L[200];
char R[200];
char N[200];
string ans;

int main()
{
      scanf("%d",&n);
      REP(i,n)
      {
            scanf("%s %s %s",N,L,R);
            long long v = 0;
            int a,b,c;
            a = strlen(N);
            b = strlen(L);
            c = strlen(R);
            REP(i,a)
            {
                  v = v*b;
                  REP(j,b) if(N[i] == L[j]) v+=j;
            }
            ans = "";
            while(v>0)
            {
                  ans += R[v%c];
                  v/=c;
            }
            printf("Case #%d: ",i+1);
            REPD(i,SIZE(ans)-1) printf("%c",ans[i]);
            printf("\n");
      }
      return 0;
}
