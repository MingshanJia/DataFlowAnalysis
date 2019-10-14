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

int a[2010][2010];

int comb(int a, int b){
  if(a==-1) return b;
  if(a==2) return 2;
  if(a==b) return a;
  return 2;
}

int f(int w, int b){
  if(w==1&&b==0)return 0;
  if(w==0&&b==1)return 1;
  if(a[w][b]!=-1)return a[w][b];
  int co=-1;

  if(w>=2)co=comb(co,f(w-1,b));
  if(b>=2)co=comb(co,f(w+1,b-2));
  if(w>=1&&b>=1)co=comb(co,f(w-1,b));

  return a[w][b]=co;
}

int main(){
  int _cases; scanf("%d",&_cases);
  memset(a,-1,sizeof(a));
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);
    int w,b;scanf("%d%d",&w,&b);
    int  x=b%2;
    if(x==0)printf(" WHITE\n");
    else if(x==1)printf(" BLACK\n");
    else printf(" UNKNOWN\n");
  }
  return 0;
}
