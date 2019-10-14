#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

int S;
int arr[15];

int main()
{
    FILE *in=fopen("market.in","r");
    freopen("market.out","w",stdout);
    int c,c2;
    int tests;
    fscanf(in,"%d",&tests);
    int testn=1;
    while (tests--)
    {
        printf("Case #%d: ",testn);
        testn++;
        fscanf(in,"%d",&S);
        for (c=0;c<12;c++)
            fscanf(in,"%d",&arr[c]);
        int ret=-1;
        int i1,i2;
        for (c=0;c<12;c++)
            for (c2=c+1;c2<12;c2++)
            {
                if (arr[c]>=arr[c2])continue;
                int cnt=S/arr[c];
                if (ret< cnt*(arr[c2]-arr[c]))
                {
                    ret=cnt*(arr[c2]-arr[c]);
                    i1=c;
                    i2=c2;
                }
                else if (ret == cnt*(arr[c2]-arr[c]) && arr[c]<arr[i1])
                {
                    i1=c;
                    i2=c2;
                }
            }
        if (ret<=0)printf("IMPOSSIBLE\n");
        else
            printf("%d %d %d\n",i1+1,i2+1,ret);
    }
//    system("pause");
    return 0;
}



































