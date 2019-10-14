#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

int n,m;
char grid[55][55];
int arr[55];
bool can[300];

int main()
{
    FILE *in=fopen("house.in","r");
    freopen("house.out","w",stdout);
    int c,c2;
    int tests;
    fscanf(in,"%d",&tests);
    int testn=1;
    memset(can,0,sizeof(can));
    can['S']=1;
    can['G']=1;
    while (tests--)
    {
        printf("Case #%d: ",testn);
        testn++;
        fscanf(in,"%d%d",&m,&n);
        for (c=0;c<n;c++)
            fscanf(in,"%s",grid[c]);
        memset(arr,0,sizeof(arr));
        int ret=0;
        for (c=0;c<n;c++)
        {
            for (c2=0;c2<m;c2++)
                if (can[grid[c][c2]])arr[c2]++;
                else arr[c2]=0;
            int c3;
            int ma=0;
            for (c2=0;c2<m;c2++)
            {
                for (c3=c2;c3>=0;c3--)
                    if (arr[c3]<arr[c2])break;
                ma=c3;
                for (c3=c2;c3<m;c3++)
                    if (arr[c3]<arr[c2])break;
                ma=c3-ma-1;
                ret=max(ret,ma*arr[c2]);
            }
        }
        printf("%d\n",ret);
    }
//    system("pause");
    return 0;
}


































