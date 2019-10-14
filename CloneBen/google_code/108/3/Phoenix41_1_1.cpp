#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

double P[100];
double P1[100];
int N;

double deal()
{
  
  double num=1,num1=1,num2=1; 
  sort(P,P+2*N);
  for(int i=0;i<N;++i) P1[i]=(1-P[i]*P[2*N-1-i]);
   for(int i=0;i<N;++i) num2*=(1-P[i]*P[2*N-1-i]);
  sort(P1,P1+N);
  // for(int i=0;i<2*N;++i) printf("%lf\n",P[i]);
  for(int i=0;i<N;++i)
   {
     num*=P1[i];
     //  printf("%lf\n",num); 
   }
  for(int i=0;i<N;++i)
   {
     num1*=P1[N-1-i];
     //  printf("%lf\n",num); 
   }
  
  return num2;
}

int main()
{
  int  T;
  scanf("%d",&T);
  for(int i=1;i<=T;++i)
  {
    printf("Case #%d: ", i);
    scanf("%d",&N);
    for(int j=0;j<2*N;++j)    scanf("%lf",&P[j]);
    printf("%.6lf\n",deal());
  
  }
  //printf("%d\n",maxt);
  return 0;
}
