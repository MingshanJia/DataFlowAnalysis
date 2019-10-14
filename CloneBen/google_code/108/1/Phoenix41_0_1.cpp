#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int S, F; 
int seat[201][201];


int deal()
{
  int i,j;
  int num = 0;
  for(i=1;i<=S;++i)
   {
     int tmp=0;
     for(j=1;j<=S;++j)
       if(seat[i][j]>0) tmp++;
     if(tmp>=num) num=tmp;
   }
  return num;
}

int main()
{
  int  T, A,B;
  scanf("%d",&T);
  for(int i=1;i<=T;++i)
  {
    printf("Case #%d: ", i);
    scanf("%d%d",&F,&S);
    for(int j=0;j<=200;++j)
      for(int  k=0;k<=200;++k)
	seat[j][k]=0;
    for(int j=0;j<F;++j)
    {
      scanf("%d%d",&A,&B);
      ++seat[A][B];
      ++seat[B][A];
    }
    
    printf("%d\n",deal());
  
  }
  //printf("%d\n",maxt);
  return 0;
}
