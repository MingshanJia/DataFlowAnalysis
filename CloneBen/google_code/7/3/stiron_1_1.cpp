#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

int pass[5500];

int main()
{
    int N,T,casn,i,j,a,b,P;
    scanf("%d",&T);
    for(casn=0;casn<T;casn++)
    {
        memset(pass,0,sizeof(pass));
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%d %d",&a,&b);
            if(a>b)
                swap(a,b);
            for(j=a;j<=b;j++)
                pass[j]++;
        }
        printf("Case #%d:",casn+1);
        scanf("%d",&P);
        for(i=0;i<P;i++)
        {
            scanf("%d",&a);
            printf(" %d",pass[a]);
        }
        puts("");
    }
    return 0;
}
