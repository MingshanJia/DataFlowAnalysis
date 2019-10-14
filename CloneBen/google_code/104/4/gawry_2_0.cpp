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
#include<deque>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

main(){
  int T;cin>>T;
  for(int c=1;c<=T;c++){
    int K,n,q[5010];
    cin>>K>>n;
    FOR(i,n)cin>>q[i];
    deque<int> s;
    for(int i=K;i>=1;i--){
      s.push_front(i);
      int m=i%s.size();
      while(m--){
        int x=s.front();
        s.pop_front();
        s.push_back(x);
      }
    }
//    FOR(i,s.size())cout<<s[i]<<" ";cout<<endl;
    cout<<"Case #"<<c<<":";
    FOR(i,n)cout<<" "<<s[s.size()-q[i]];
    cout<<endl;
  }
}
