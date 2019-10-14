#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <utility>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

#define CLEAR(X) memset(X,0,sizeof(X))
#define REP(i,n) for(int i=0;i<(n);i++) 
template <class T> vector<T>parse(string s,const char d=' '){
  vector<T> v; string p; s+=d; int i=0; 
  while(i<(int)s.size())
    if (s[i] == d){stringstream u; u<<p; T t; u>>t; v.push_back(t); p=""; while(i<(int)s.size() && s[i]==d)i++;} else p+=s[i++];   
  return v;
} 

typedef long long ll;
typedef long double ld;

int n,k,all;
int x[20],y[20];

int len;
int q[20][1<<15];

bool f(int m, int p){
  if(p>k)return false;
  if(m==all)return true;
  if(q[p][m]!=-1)return q[p][m];
  REP(i,n)REP(j,n){
    if((m&(1<<i))!=0 && (m&(1<<j))!=0)continue;
    int left=x[i],top=y[j];
    int nm=m;
    REP(k,n)if(x[k]>=left && x[k]<=left+len && y[k]>=top && y[k]<=top+len)
      nm|=(1<<k);
    if(nm!=m && f(nm,p+1))return q[p][m]=1;
  }
  return q[p][m]=0;
}

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);
    scanf("%d%d",&n,&k);
    REP(i,n)scanf("%d%d",&x[i],&y[i]);
    all=(1<<n)-1;
    int l=0,r=100000;
    while(l!=r){
      int mid=(l+r)/2;
      len=mid;memset(q,-1,sizeof(q));
      if(f(0,0))r=mid;
      else l=mid+1;
    }
    printf(" %d\n",l);
  }
  return 0;
}
