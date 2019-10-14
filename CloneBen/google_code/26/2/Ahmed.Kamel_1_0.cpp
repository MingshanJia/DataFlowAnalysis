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

int main()
{
    freopen ("input.in","r",stdin);
    freopen ("BSmall.out","w",stdout);
    int i,j,k,T,arr[14];
    k=0;
    scanf("%d",&T);
    while(T--)
    {
        k++;
        int M,ret=0,s,e,xx=1<<30;
        scanf("%d",&M);
        
        for(i=0;i<12;i++)scanf("%d",&arr[i]);
        
        fo(i,11)
        {
            int x=(int)M/(int)arr[i];
            for(j=i+1;j<12;j++)
            {
                int p=x*arr[j];
                
                //printf("%d %d: %d\n",i+1,j+1,p-M);
                
                if(p+M%arr[i]-M>ret || (p+M%arr[i]-M==ret && arr[i]<xx))
                {
                    ret=p+M%arr[i]-M;
                    s=i+1;
                    e=j+1;
                    xx=arr[i];
                }
            }
        }
        if(ret<=0)printf("Case #%d: IMPOSSIBLE\n",k);
        else printf("Case #%d: %d %d %d\n",k,s,e,ret);
    }
}


































