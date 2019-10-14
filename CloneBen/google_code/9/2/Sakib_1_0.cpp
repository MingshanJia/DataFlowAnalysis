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

double cap[500][100000],tmp,V;
int B,L,N,w[100000];

int main()
{
    int i,j,k,T,cas,ret=0;

  freopen("B-small-attempt2(1).in","r",stdin);
  //freopen("in.txt","r",stdin);
    freopen("B-SM-FN.txt","w",stdout);

    j=1;

    for(i=1;i<=401;i++)
    {
        for(;j<=(i*(i+1))/2;j++)
        {
            w[j]=i;
        }
    }

   // printf("%d\n",j);

   // for(i=1;i<=100;i++) printf("%d : %d\n",i,w[i]);

    scanf("%d",&T);

    V=250.0;

    for(cas=1;cas<=T;cas++)
    {

        cin>>B>>L>>N;

        for(i=1;i<=L;i++)
        {
            for(j=1;j<=(i*(i+1))/2;j++) cap[i][j]=0.0;
        }

        cap[1][1]=B*750.0;

        for(i=1;i<=L;i++)
        {
            for(j=1;j<=(i*(i+1))/2;j++)
            {
                if(cap[i][j]<=V) continue;

                tmp=(cap[i][j]-V)/3.0;
                cap[i][j]=V;

                cap[i+1][j]+=tmp;
                cap[i+1][j+w[j]]+=tmp;
                cap[i+1][j+w[j]+1]+=tmp;


            }
        }

        printf("Case #%d: %.8lf\n",cas,cap[L][N]);
    }

    return 0;
}
