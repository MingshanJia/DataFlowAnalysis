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

int n;
bool pr[20][20];

int a[20][1<<11];

const int MOD=9901;

int f(int p, int m){
  if(m== ((1<<n)-1)){
    if(pr[p][0])return 0;
    return 1;
  }
  if(a[p][m]!=-1)return a[p][m];
  int r=0;
  REP(i,n)if(!pr[p][i] && (m&(1<<i))==0)r+=f(i,m|(1<<i));
  return a[p][m]=r%MOD;
}

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);
    int k;scanf("%d%d",&n,&k);CLEAR(pr);
    REP(i,k){int a,b;scanf("%d%d",&a,&b);a--;b--;pr[a][b]=pr[b][a]=true;}
    memset(a,-1,sizeof(a));
    printf(" %d\n",(f(0,1)*4951)%MOD);
  }
  return 0;
}
