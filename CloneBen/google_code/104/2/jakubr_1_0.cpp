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

bool pr[10000];
int dz[10000];

void sito()
{
  FOR(i,2,1000) pr[i]=1;
  FOR(i,2,1000) if (pr[i])
  {
    int j=2*i;
    while (j<=1000) { pr[j]=0; dz[j]=max(dz[j],i); j+=i; }
  }
}

VI t[1010];
bool c[1010];

void dfs(int v)
{
  c[v]=1;
  REP(i,SIZE(t[v])) if (!c[t[v][i]]) dfs(t[v][i]);
}

int dziel(int x)
{
  if (x==1) return 1;
  if (pr[x]) return x;
  return max(dz[x],dziel(x/dz[x]));
}

int main()
{
  scanf("%d",&ILE);
  sito();
  FOR(LICZ,1,ILE)
  {
    printf("Case #%d:",LICZ);
    ll a,b,p;
    scanf("%I64d%I64d%I64d",&a,&b,&p);
    int A(a),B(b),P(p);
    FOR(i,A,B) { t[i].clear(); c[i]=0; }
    FOR(i,A,B) FOR(j,i+1,B)
    {
      int x=nwd(i,j);
      int y=dziel(x);
      if (y>=P) { t[i].PB(j); t[j].PB(i); }
    }
    int wyn=0;
    FOR(i,A,B) if (!c[i])
    {
      wyn++;
      dfs(i);
    }
    printf(" %d\n",wyn);
  }
  return 0;
}
