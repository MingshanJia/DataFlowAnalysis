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
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

bool p[1010];
bool e[1010][1010],seen[1010];
void dfs(int x){
  seen[x]=1;
  FOR(i,1010)if(!seen[i]&&e[x][i])dfs(i);
}
main(){
  for(int i=2;i<1010;i++)p[i]=1;
  for(int i=2;i<1010;i++)if(p[i])for(int j=2*i;j<1010;j+=i)p[j]=0;
  int C;
  cin>>C;
  for(int c=1;c<=C;c++){
    int64 A,B,P,ans=0;
    cin>>A>>B>>P;
    memset(e,0,sizeof(e));
    for(int i=P;i<1010;i++)if(p[i])for(int x=i;x<=B;x+=i)for(int y=i;y<=B;y+=i)if(x>=A&&y>=A)
      e[x][y]=e[y][x]=1;
    for(int i=A;i<=B;i++)seen[i]=0;
    for(int i=A;i<=B;i++)if(!seen[i]){ans++;dfs(i);}

    cout<<"Case #"<<c<<": "<<ans<<endl;
  }
}
