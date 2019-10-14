#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#define inf 2000000000
#define ll long long
#define Max

using namespace std;

int N,K;
vector <int> v[200];
int dp[205][205],A[205];

int f(int x,int y)
{
    if(x>y) return 0;

    int i,j,k,l,r;
    int a,b,c;

    l=y-x+1;

    if(l<3) return l;

    if(l==3)
    {
        if(A[x]+K==A[x+1] && A[x+1]+K==A[x+2]) return 0;
        return 3;
    }

    if(dp[x][y]!=-1) return dp[x][y];

    r=1+f(x+1,y);

    for(i=0;i<v[x].size();i++)
    {
        b=v[x][i];

        if(b>y) break;

        if(f(x+1,b-1)!=0) continue;

        for(j=0;j<v[b].size();j++)
        {
            c=v[b][j];

            if(c>y) break;

            if(f(b+1,c-1)!=0) continue;

            r=min(r,f(c+1,y));

        }
    }

    return dp[x][y]=r;

}


int main()
{
    int i,j,k,T,cas,ret=0;

    freopen("C-large.in","r",stdin);
    freopen("c-large-shesh.txt","w",stdout);

    scanf("%d",&T);

    for(cas=1;cas<=T;cas++)
    {
        scanf("%d %d",&N,&K);

        memset(dp,-1,sizeof(dp));

        for(i=0;i<N;i++)
        {
            v[i].clear();
            scanf("%d",&A[i]);
        }


        for(i=0;i<N;i++)
        {
            for(j=i+1;j<N;j++)
            {
                if(A[i]+K==A[j]) v[i].push_back(j);
            }
        }

        printf("Case #%d: %d\n",cas,f(0,N-1));
    }

    return 0;
}
