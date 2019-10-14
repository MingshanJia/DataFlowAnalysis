#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
int n;
int64 M,F,a[2100000];
typedef pair<int64,int64> p2;
p2 t[210];
void solve(){
  scanf("%lld %lld %d",&M,&F,&n);
  FOR(i,n)scanf("%lld %lld",&t[i].second,&t[i].first);
  sort(t,t+n);
  vector<p2> s;
  FOR(i,n){
    while(!s.empty()&&s.back().second>=t[i].second)s.pop_back();
    if(s.empty()||s.back().first<t[i].first)s.push_back(t[i]);
  }
//  FOR(i,s.size())printf("%lld %lld\n",s[i].first,s[i].second);
  int64 ans=0,cost=F,days=0;
  for(int j=0;j<=s.size();j++){
    int64 next_days=j<s.size()?s[j].first+1:days,diff=next_days-days,cnt=1;
    while(cnt*cost<=M){
      int64 left=M-cnt*cost;
      //printf("%lld %lld %lld\n",cnt,cnt*days,j<s.size()?min(left/s[j].second,diff):0);
      ans=max(ans,cnt*days+(j<s.size()?min(left/s[j].second,diff*cnt):0)); 
      ++cnt;
    }
    if(j==s.size())break;
    cost+=s[j].second*(next_days-days);
    days=next_days;
  }
  printf("%lld\n",ans);
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
    fprintf(stderr,"processing case %d\n",tt);
    printf("Case #%d: ",tt);
    solve();
    fflush(stdout);
  }
  freopen(out,"r",stdin);
  char c;while((c=getc(stdin))!=EOF)putc(c,stderr);
}

