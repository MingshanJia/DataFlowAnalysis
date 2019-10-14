/* Jakub Radoszewski (jakubr) */

//#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
using namespace std;

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define INFTY 100000000
#define VAR(V,init) __typeof(init) V=(init)
#define FORE(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define SIZE(x) ((int)(x).size())

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef vector<string> VS;

ll nwd(ll a,ll b) { return !b?a:nwd(b,a%b); }
inline int CEIL(int a,int b) { return a%b ? a/b+1 : a/b; }
template <class T> inline T sqr(const T&a) { return a*a; }

VS parse(string s)
{
  string a;
  VS wyn;
  REP(i,(int)s.size())
    if (s[i]!=' ') a+=s[i];
    else if (!a.empty()) { wyn.PB(a); a=""; }
  if (!a.empty()) wyn.PB(a);
  return wyn;
}

int toi(char ch) { return int(ch)-int('0'); }

int chg(char ch) { return int(ch)-int('a'); }

int ILE;
#define MD 10007
int t[110][110];

inline int ins1(int a,int b) { return a>=1 && a<=b; }

int main()
{
  scanf("%d",&ILE);
  FOR(LICZ,1,ILE)
  {
    printf("Case #%d: ",LICZ);
    int h,w,r;
    scanf("%d%d%d",&h,&w,&r);
    memset(t,0,sizeof(t));
    REP(i,r)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      t[a][b]=-1;
    }
    t[1][1]=1;
    FOR(i,1,h) FOR(j,1,w) if (i!=1 || j!=1)
    {
      if (t[i][j]<0) continue;
      t[i][j]=0;
      if (ins1(i-2,h) && ins1(j-1,w) && t[i-2][j-1]!=-1) t[i][j]+=t[i-2][j-1];
      if (ins1(i-1,h) && ins1(j-2,w) && t[i-1][j-2]!=-1) t[i][j]+=t[i-1][j-2];
      t[i][j]%=MD;
    }
    printf("%d\n",t[h][w]%MD);
  }
  return 0;
}
