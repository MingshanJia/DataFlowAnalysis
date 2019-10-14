/*
TASK: C-testo
LANG: C++
*/

#include<stdio.h>
#include<stdlib.h>

int a[5000000];

int main()
{
    int i,j;
    a[0] = 2; a[1] = 6;
    printf("0: 2\n1: 6\n");
    i = 2;
    while(i<5000000)
    {
        a[i] = (a[i-1]*6 - 4*a[i-2] + 40000)%1000;
        //printf("%d: %d\n",i,a[i]);
        //if(a[i]==28 && a[i-1]==6) printf("%d\n",i);
        i++;
    }
    printf("%d %d %d %d %d %d\n",a[5],a[105],a[205],a[2],a[102],a[202]);
    for(i=0;i<5000000-1;i++)
    {
        for(j=i+1;j<5000000-1;j++)
        {
            if(a[i]==a[j]&&a[i+1]==a[j+1]) {printf("%d %d\n",i,j); system("PAUSE");}
        }
    }
    system("PAUSE");
    return 0;
}
