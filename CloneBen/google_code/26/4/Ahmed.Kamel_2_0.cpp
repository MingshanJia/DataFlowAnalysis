#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<sstream>
#include<iostream>
#include<stack>
#include<list>
using namespace std;

typedef vector<vector<int> > vii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long LL;

#define sz size()
#define all(n) n.begin(),n.end()
#define clr(a,n) memset(a,n,sizeof(a))
#define pb push_back
#define fo(i,j) for(int i=0;i<j;i++)

char arr[55][55];

int main()
{
    freopen ("input.in","r",stdin);
    freopen ("CSmall.out","w",stdout);
    int i,j,k=0,l,m,T;
    
    scanf("%d",&T);
    while(T--)
    {
        int C,R,ret=0;
        k++;
        scanf("%d %d",&C,&R);
        for(i=0;i<R;i++)
        {
            scanf("%s",arr[i]);
        }
        for(i=0;i<R;i++)
        {
            for(j=i;j<R;j++)
            {
                int c=0;
                int s[55];
                memset(s,0,sizeof s);
                for(l=0;l<C;l++)
                {
                    for(m=i;m<=j;m++)
                    {
                        if(arr[m][l]=='T' || arr[m][l]=='W' || arr[m][l]=='R')s[l]=1;
                    }
                    if(!s[l])c++;
                    else
                    {
                        ret=max(ret,c*(j-i+1));
                        c=0;
                    }
                }
                ret=max(ret,c*(j-i+1));
            }
        }
        printf("Case #%d: %d\n",k,ret);
    }
}


































