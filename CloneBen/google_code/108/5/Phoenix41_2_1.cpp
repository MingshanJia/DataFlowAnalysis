#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N;

void  deal()
{
  int g=N/41;
  int tmp=0;
  for(int i=0;i<15;++i) printf("I");
  printf("\n");
  for(int j=0;j<g;++j)
  {
    for(int i=0;i<15;++i)
      printf("/");
    printf("\n");
    for(int i=0;i<15;++i)
      if(tmp==1) printf("I");
      else  printf("O");
    printf("\n");
    tmp=1-tmp;
  }
  N%=41;

  if(N==0) return;
  
       if(N%3==0) printf("I");
       else  printf("/"); 

       for(int i=1;i<14;++i)
	 if(i<=N/3) printf("/");
	 else printf("I");

       if(N%3==2) printf("/");
       else printf("I");
      printf("\n"); 

 
  for(int i=0;i<15;++i)
      if(tmp==1) printf("I");
      else  printf("O");
    printf("\n");
    tmp=1-tmp;
  return;
}

int main()
{
  int  T,D;
  scanf("%d",&T);
  for(int i=1;i<=T;++i)
  {
    printf("Case #%d:\n", i);
    scanf("%d%d",&D,&N);
    deal();
  
  }
  //printf("%d\n",maxt);
  return 0;
}
