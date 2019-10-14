#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PI;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%lld",&A)
#define make2(A,B) scanf("%d%d",&A,&B)
#define ALL(x) (x).begin(), (x).end()
#define db if(1)printf
template<typename C> void MA(C& a,C b){if(a<b)a=b;}
template<typename C> void MI(C& a,C b){if(a>b)a=b;}
#define MAX 1001
LL n;
LL a[MAX];
LL b[MAX];
LL il[MAX];
LL kt[MAX];
multiset<PI> s;
void test(){
  static int cas = 0;cas++;
  printf("Case #%d: ",cas);
  make(n);
  s.clear();
  LL ak = 0;
  R(i,n){
    make(a[i]);
    make(il[i]);
    kt[i] = 0;
    make(b[i]);
    a[i] = 360 - a[i];
    s.insert({a[i]*b[i],i});
    b[i] *= 360;
    ak += il[i];
  }
  LL wyn = ak;
  LL lim = ak;
  while(ak - lim < wyn){
    auto x = s.begin();
    LL nr = x->SE;
    LL gd = x->FI;
    s.erase(x);
    if(nr >= 0){
      lim --;
      ak --;
      MI(wyn,ak);
      LL speed = b[nr] + kt[nr];
      s.insert(MP(gd+speed,-speed));
      kt[nr]++;
      if(kt[nr] < il[nr])
        s.insert(MP(gd+a[nr],nr));
    }else{
      ak++;
      s.insert(MP(gd-nr,nr));
    }
  }
  printf("%lld\n",wyn);
}
main(){
  LL _;make(_);while(_--)test();
}