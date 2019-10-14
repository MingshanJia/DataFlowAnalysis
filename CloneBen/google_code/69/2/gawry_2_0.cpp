#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<cstring>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

int n,x[110],y[110],z[110];
int ans_x,ans_y;
bool found=false;
void check(int cx,int cy){
  bool ok=true;
  FOR(i,n)ok&=max(abs(x[i]-cx),abs(y[i]-cy))%2==z[i];
  if(!ok)return;
  if(!found)ans_x=cx,ans_y=cy,found=true;
  else if(abs(cx)+abs(cy)<abs(ans_x)+abs(ans_y)||abs(cx)+abs(cy)==abs(ans_x)+abs(ans_y)&&(cx>ans_x||cx==ans_x&&cy>ans_y))ans_x=cx,ans_y=cy;
}
void solve(){
  scanf("%d",&n);
  FOR(i,n){
    char c;
    scanf("%d %d %c",&x[i],&y[i],&c);
    z[i]=c=='#';
  }
  found=false;
  FOR(i,n)for(int dx=-1;dx<=1;dx++)for(int dy=-1;dy<=1;dy++){
    check(x[i]+dx,y[i]+dy);
  }
  for(int cx=-1000;cx<=1000;cx++)for(int cy=-1000;cy<=1000;cy++)check(cx,cy);
  FOR(i,n)for(int dx=-1;dx<=1;dx++)for(int dy=-1;dy<=1;dy++)FOR(i2,n)for(int dx2=-1;dx2<=1;dx2++)for(int dy2=-1;dy2<=1;dy2++){
    int sum=x[i]+dx+y[i]+dy,diff=x[i2]+dx2-y[i2]-dy2;
    check((sum+diff)/2,sum-(sum+diff)/2);
    check(x[i2]+dx2,sum-(x[i2]+dx2));
    check(sum-(y[i2]+dy2),y[i2]+dy2);
    check(x[i]+dx,x[i]+dx-diff);
    check(diff+y[i]+dy,y[i]+dy);
  }

  if(found)
  cout<<ans_x<<" "<<ans_y<<endl;
  else cout<<"Too damaged"<<endl;
}

main(){
  int C;cin>>C;
  for(int c=1;c<=C;c++){
    cout<<"Case #"<<c<<": ";
    solve();
    cout<<flush;
  }
}
