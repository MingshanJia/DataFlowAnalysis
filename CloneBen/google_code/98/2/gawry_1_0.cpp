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

string c[310];
int from[310],to[310],m[310][310][310];
main(){
  int C,N;cin>>C;
  for(int cc=1;cc<=C;cc++){
    cin>>N;
    FOR(i,N)cin>>c[i]>>from[i]>>to[i];
    FOR(i,N)FOR(j,i)if(to[i]<to[j]){
      swap(c[i],c[j]);
      swap(from[i],from[j]);
      swap(to[i],to[j]); 
    }
#define INF 1000000
    FOR(i,N)FOR(j,N)FOR(k,N)m[i][j][k]=INF;
    FOR(i,N)FOR(j,N)FOR(k,N){
      if(from[i]==1){m[i][j][k]=1;continue;}
      FOR(prev,i)if(to[prev]>=from[i]-1){
        if(c[i]==c[prev])m[i][j][k]<?=m[prev][j][k]+1;
        if(c[j]==c[prev])m[i][j][k]<?=m[prev][i][k]+1;
        if(c[k]==c[prev])m[i][j][k]<?=m[prev][j][i]+1;
      }
    }
    int ans=INF;
    FOR(i,N)FOR(j,N)FOR(k,N)if(to[i]==10000)ans<?=m[i][j][k];
    cout<<"Case #"<<cc<<": ";
    if(ans<INF)cout<<ans;else cout<<"IMPOSSIBLE";
    cout<<endl;
  }
}
