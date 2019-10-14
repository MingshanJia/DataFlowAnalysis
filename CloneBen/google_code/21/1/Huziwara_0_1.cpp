#include <cstdio>

int main()
{
  int t;
  scanf("%d",&t);
  for(int T=1;T<=t;T++){
    long long m,w;
    int c;
    scanf("%lld%d%lld",&m,&c,&w);
    long long A[100],B[100];
    for(int i=0;i<c;i++){
      scanf("%lld%lld",A+i,B+i);
    }
    for(int i=c-1;i>=0;i--){
      if(w<=B[i]){
	w+=A[i]-1;
      }
      else if(w<=A[i]+B[i]-1){
	w-=B[i];
      }
    }
    printf("Case #%d: %lld\n",T,w);
  }
  return 0;
}
