#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std ;

int dis[1100000] ;
int INF = 2000000000 ;
int pos[10] ;
set<pair<int,int> > nums ;
int req ;

void build(int n, int cnt)
{
    dis[n] = cnt ;
    if(n!=0 && n!=1)
        nums.insert(make_pair(n,cnt+1)) ;
    for(int i=0;i<10;i++)
        if(pos[i]==1)
        {
            int nn = n*10+i ;
            if(nn<=req)
                build(nn, cnt+1) ;
        }
}

int main(void)
{
    int T ;
    int tc ;
    
    scanf("%d",&T) ;
    for(tc=1;tc<=T;tc++)
    {
        for(int i=0;i<10;i++)
            scanf("%d", &pos[i]) ;
        scanf("%d", &req) ;
        
        for(int i=0;i<=req;i++)
            dis[i] = INF ;
        
        printf("Case #%d: ",tc) ;
        
        nums.clear() ;

        for(int i=1;i<10;i++)
            if(pos[i]==1)
                build(i,1) ;

        for(int i=1;i<req;i++)
        {
            if(dis[i]<INF)
            {
                for(set<pair<int,int> >::iterator it = nums.begin();it!=nums.end();++it)
                {
                    if(((long long)i)*it->first>req)
                        break ;
                    int t = i*it->first ;
                    int p = dis[i]+it->second ;
                    dis[t] = min(dis[t], p) ;
                }
            }
        }

        if(dis[req]==INF)
            printf("Impossible") ;
        else
            printf("%d",dis[req]+1) ;
        printf("\n") ;
    }

    return 0 ;
}
