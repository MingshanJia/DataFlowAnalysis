// @author peter50216
// #includes {{{
#include <bits/stdc++.h>
using namespace std;
// }}}
// #defines {{{
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#ifdef ONLINE_JUDGE
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define FILEIO(x) ;
#define FILEIOS ;
#endif
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
// }}}

map<string,int> mp;
char tmp[101000];

inline int getid(const string& s){
  if(mp.count(s)==0){
    int ii=mp.size();
    mp[s]=ii;
    return ii;
  }
  return mp[s];
}

inline vector<int> read(){
  gets(tmp);
  stringstream ss;
  ss<<tmp;
  string s;
  vector<int> ret;
  while(ss >> s){
    ret.push_back(getid(s));
  }
  return ret;
}

vector<int> in[210];

int n;
int cnt[201000][2];
int diff;
inline void add(int x,int c){
  if(cnt[x][c]==0&&cnt[x][1-c])diff++;
  cnt[x][c]++;
}
inline void add(const vector<int>& v,int c){
  for(int a:v)add(a,c);
}
inline void del(int x,int c){
  cnt[x][c]--;
  if(cnt[x][c]==0&&cnt[x][1-c])diff--;
}
inline void del(const vector<int>& v,int c){
  for(int a:v)del(a,c);
}
int ans;
inline void dfs(int np){
  if(np==n){
    ans=min(ans,diff);
    return;
  }
  REP(k,2){
    add(in[np],k);
    dfs(np+1);
    del(in[np],k);
  }
}

int main(){
  CASET{
    mp.clear();
    RI(n);gets(tmp);
    REP(i,n)in[i]=read();
    MS0(cnt);
    diff=0;
    add(in[0],0);
    add(in[1],1);
    ans=3000000;
    dfs(2);
    printf("Case #%d: %d\n",cas++,ans);
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

