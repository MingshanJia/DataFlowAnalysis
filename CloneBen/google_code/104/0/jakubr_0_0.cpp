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

int main()
{
  scanf("%d",&ILE);
  FOR(LICZ,1,ILE)
  {
    vector<PII> t;
    printf("Case #%d:",LICZ);
    int n, A, B, C, D, x0, y0, M;
    scanf("%d%d%d%d%d%d%d%d",&n, &A, &B, &C, &D, &x0, &y0, &M);
    int X = x0, Y = y0;
    t.PB(MP(X,Y));
    FOR(i,1,n-1)
    {
      X = ((ll)A * X + B) % (ll)M;
      Y = ((ll)C * Y + D) % (ll)M;
      t.PB(MP(X,Y));
    }
    sort(ALL(t));
    t.erase(unique(ALL(t)),t.end());
//    REP(i,n) printf("%d %d\n",t[i].FI,t[i].SE);
    ll licz=0;
    REP(i,n) FOR(j,i+1,n-1) FOR(k,j+1,n-1)
    {
      ll a=(t[i].FI+t[j].FI+t[k].FI);
      if (a%3) continue;
      a/=3;
      ll b=(t[i].SE+t[j].SE+t[k].SE);
      if (b%3) continue;
      b/=3;
      licz++;
//      REP(l,n) if (t[l]==MP((int)a,(int)b)) licz++;
    }
    printf(" %I64d\n",licz);
  }
  return 0;
}
