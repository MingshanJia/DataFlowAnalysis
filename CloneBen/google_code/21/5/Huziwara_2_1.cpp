#include <cstdio>

int main()
{
  int t;
  scanf("%d",&t);
  for(int C=1;C<=t;C++){
    long long n;
    scanf("%lld",&n);
    int a=0,b=-1000;
    while(n){
      int A,B;
      if(n&1){
	A=a+1>b?a+1:b;
	B=b+2;
      }
      else{
	A=a;
	B=a+2>b+1?a+2:b+1;
      }
      a=A;
      b=B;
      n/=2;
    }
    printf("Case #%d: %d\n",C,a);
  }
  return 0;
}
