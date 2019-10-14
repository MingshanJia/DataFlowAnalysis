#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
using namespace std;
int n,m,x[2010],y[2010],cnt;
vector<int> s[2010],b[2010];
typedef pair<int,int> p2;
map<p2,int> nr;
void solve(){
  scanf("%d %d",&n,&m);
  for(int i=1;i<=n;i++)s[i].clear();
  for(int i=0;i<m;i++)scanf("%d",&x[i]);
  for(int i=0;i<m;i++)scanf("%d",&y[i]);
  for(int i=0;i<m;i++){
    s[x[i]].push_back(y[i]);
    s[y[i]].push_back(x[i]);
  }
  for(int i=1;i<=n;i++){
    int x=i,y=i<n?i+1:1;
    s[x].push_back(y);
    s[y].push_back(x);
  }
  for(int i=1;i<=n;i++)sort(s[i].begin(),s[i].end());
  cnt=0;
  nr.clear();
  for(int i=1;i<=n;i++)for(int j=0;j<s[i].size();j++)if(nr.find(p2(i,s[i][j]))==nr.end()){
    int x=i,y=s[i][j];
    b[cnt].clear();
    while(nr.find(p2(x,y))==nr.end()){
      b[cnt].push_back(x);
      nr[p2(x,y)]=cnt;
      int pos=0;
      while(s[y][pos]!=x)pos++;
      int z=s[y][(pos+1)%s[y].size()];
      x=y;
      y=z;
    }
    ++cnt;
  }
 /* printf("cnt=%d\n",cnt);
  for(int i=0;i<cnt;i++){
    for(int j=0;j<b[i].size();j++)printf("%d ",b[i][j]);
    puts("");
  }*/
  int t[1<<8]={};
  bool ok[1<<8]={};
  for(int left=1;left<(1<<n);left++){
    ok[left]=true;
    for(int i=0;i<cnt;i++)if(b[i].size()<n){
      bool found=false;
      for(int j=0;j<b[i].size();j++)found|=left&(1<<b[i][j]-1);
      ok[left]&=found;
    }
  //  if(ok[left])printf("%d\n",left);
  }
  for(int left=1;left<(1<<n);left++){
    t[left]=-1000000000;
    for(int last=left;last;last=last-1&left)if(ok[last])t[left]=max(t[left],t[left-last]+1);
  }
  printf("%d\n",t[(1<<n)-1]);
  int left=(1<<n)-1,r[2010];
  while(left){
    for(int last=left;last;last=last-1&left)if(ok[last]&&t[left]==t[left-last]+1){
      for(int i=0;i<n;i++)if(last&1<<i)r[i]=t[left];
      left-=last;
      break;
    }
  }
  for(int i=0;i<n;i++)printf("%d%c",r[i],i+1<n?' ':'\n');
}
main(){
  char in[100],out[100],*pos;
  strcpy(in,__FILE__);
  strcpy(out,__FILE__);
  pos=in;
  while(*pos!='.')pos++;
  strcpy(pos,".in");
  pos=out;
  while(*pos!='.')pos++;
  strcpy(pos,".out");
  freopen(in,"r",stdin);
  freopen(out,"w",stdout);
  int t;
  scanf("%d",&t);
  for(int tt=1;tt<=t;tt++){
    printf("Case #%d: ",tt);
    solve();
    fflush(stdout);
  }
}
