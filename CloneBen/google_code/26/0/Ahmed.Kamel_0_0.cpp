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

int R[1005],B[1005];

bool cmp(const int &a,const int &b)
{
    return a>b;
}

int main()
{
    freopen ("input.in","r",stdin);
    freopen ("small.out","w",stdout);
    int i,j,k,T,ret;
    
    k=0;
    scanf("%d",&T);
    while(T--)
    {
        k++;
        int N,r=0,b=0;
        ret=0;
        char c[55];
        scanf("%d",&N);
        fo(i,N)
        {
            scanf("%s",c);
            int n=strlen(c);
            if(c[n-1]=='R')
            {
                sscanf(c,"%dR",&R[r++]);
            }
            else
            {
                sscanf(c,"%dB",&B[b++]);
            }
        }
        sort(R,R+r,cmp);
        sort(B,B+b,cmp);
        for(i=0;i<min(r,b);i++)
        {
            ret+=R[i]+B[i]-2;
        }
        printf("Case #%d: %d\n",k,ret);
    }
}


































