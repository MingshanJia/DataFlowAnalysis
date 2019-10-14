#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std ;

int n;
vector<int>ar1,ar2;

int solve()
{
    int n1=ar1.size(),n2=ar2.size();
    int ret=0;
    for (int c=0;c<min(n1,n2);c++)
        ret+=ar1[c]+ar2[c]-2;
    return ret;
}


int main()
{
    FILE *in=fopen("loop.in","r");
    freopen("loop.out","w",stdout);
    int c,c2;
    int tests;
    fscanf(in,"%d",&tests);
    int testn=1;
    while (tests--)
    {
        printf("Case #%d: ",testn);
        testn++;
        ar1.clear();
        ar2.clear();
        fscanf(in,"%d",&n);
        for (c=0;c<n;c++)
        {
            int t1;
            char ch;
            fscanf(in,"%d%c",&t1,&ch);
            if (ch=='R')ar1.push_back(t1);
            else ar2.push_back(t1);
        }
        sort(ar1.begin(),ar1.end());
        sort(ar2.begin(),ar2.end());
        reverse(ar1.begin(),ar1.end());
        reverse(ar2.begin(),ar2.end());
        int loops=2;
        int ret=0;
        ret=max(ret,solve());
        printf("%d\n",ret);
    }
//    system("pause");
    return 0;
}


































