#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;

#define CLEAR(t) memset((t),0,sizeof(t))
#define FOR(i,a,b) for(__typeof(a)i=(a);i<=(b);++i)
#define FORD(i,a,b) for(__typeof(a)i=(a);i>=(b);--i)
#define REP(i,n) for(__typeof(n)i=0;i<(n);++i)
#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)

vector<string> split(const string& s, const string& delim=" ")
{ vector<string> res; string t; for(unsigned int i=0;i<s.length();i++) { if(delim.find(s[i])!=string::npos) { if(!t.empty()) { res.PB(t); t=""; } } else t+=s[i]; } if(!t.empty()) res.PB(t); return res; }
vector<int> splitint(const string& s, const string& delim=" ") { vector<string> vs=split(s); vector<int> res; for(unsigned int i=0;i<vs.size();i++) res.PB(atoi(vs[i].c_str())); return res; }

bool b[101][101];

bool ziju()
{
  REP(i,101)REP(j,101) if(b[i][j])return true;
  return false;
}

void update()
{
  bool a[101][101]; REP(i,101)REP(j,101) a[i][j]=b[i][j];
  FOR(i,1,101)FOR(j,1,101)
  {
    if((!a[i-1][j])&&(!a[i][j-1])) b[i][j]=false;
    if((a[i-1][j])&&(a[i][j-1])) b[i][j]=true;
  }
}

void _case(int casenum)
{
  int r; scanf("%d",&r);
  REP(i,101)REP(j,101) b[i][j]=false;
  REP(rr,r)
  {
    int x,y,xx,yy; scanf("%d%d%d%d",&x,&y,&xx,&yy);
    FOR(i,x,xx)FOR(j,y,yy) b[i][j]=true;
  }

  int res=0;
  while(ziju()) { res++; update(); }

  printf("Case #%d: %d\n",casenum,res);
}

int main()
{
  int n;
  scanf("%d ",&n);
  FOR(i,1,n) _case(i);
  return 0;
}
