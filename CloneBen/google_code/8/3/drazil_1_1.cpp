#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std ;

struct tt
{
    int time ;
    int x, y ;
} ;
int n, m, q ;
int sn[110] ;
int w[110] ;
int INF = 2000000000 ;
int dis[2100000] ;
int done[2100000] ;
vector<pair<int,int> > link[2100000] ;

int main(void)
{
    int T, tc ;
    
    scanf("%d",&T) ;
    
    for(tc=1;tc<=T;tc++)
    {
        for(int i=0;i<2100000;i++)
            link[i].clear() ;
        scanf("%d",&n) ;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d", &sn[i], &w[i]) ;
            for(int j=0;j<sn[i];j++)
                link[i*2000+1000+j].push_back(make_pair(i*2000+j,w[i])) ;
            for(int j=1;j<sn[i];j++)
            {
                int val ;
                scanf("%d", &val) ;
                link[i*2000+j-1].push_back(make_pair(i*2000+j,val)) ;
                link[i*2000+j].push_back(make_pair(i*2000+j-1,val)) ;
            }
        }
        scanf("%d", &m) ;
        for(int i=0;i<m;i++)
        {
            int a1, b1, a2, b2, t ;
            scanf("%d%d%d%d%d",&a1,&b1,&a2,&b2,&t) ;
            a1-- ; b1-- ; a2-- ; b2-- ;
            link[a1*2000+1000+b1].push_back(make_pair(a2*2000+1000+b2, t)) ;
            link[a2*2000+1000+b2].push_back(make_pair(a1*2000+1000+b1, t)) ;
            link[a1*2000+b1].push_back(make_pair(a2*2000+1000+b2, t)) ;
            link[a2*2000+b2].push_back(make_pair(a1*2000+1000+b1, t)) ;
        }
        printf("Case #%d:\n",tc) ;
        scanf("%d", &q) ;
        while(q--)
        {
            for(int i=0;i<n;i++)
                for(int j=0;j<sn[i];j++)
                {
                    done[i*2000+j] = 0 ;
                    dis[i*2000+j] = INF ;
                    done[i*2000+1000+j] = 0 ;
                    dis[i*2000+1000+j] = INF ;
                }
            int a1, b1, a2, b2;
            scanf("%d%d%d%d",&a1,&b1,&a2,&b2) ;
            a1-- ; b1-- ; a2-- ; b2-- ;
            dis[a1*2000+1000+b1] = 0 ;
            int tar ;
            for(;;)
            {
                tar = -1 ;
                for(int i=0;i<n;i++)
                    for(int j=0;j<sn[i];j++)
                        for(int a=0;a<2;a++)
                        {
                            if(done[i*2000+a*1000+j]==0 && dis[i*2000+a*1000+j]<INF)
                            {
                                if(tar==-1 || dis[i*2000+a*1000+j]<dis[tar])
                                    tar = i*2000+a*1000+j ;
                            }
                        }
                if(tar==-1 || tar==a2*2000+1000+b2 || tar==a2*2000+b2)
                    break ;
                else
                {
                    done[tar] = 1 ;
                    for(int i=0;i<(int)link[tar].size();i++)
                    {
                        int nid = link[tar][i].first ;
                        dis[nid] = min(dis[nid], dis[tar]+link[tar][i].second) ;
                    }
                }
            }
            if(tar==-1)
                puts("-1") ;
            else
                printf("%d\n", dis[tar]) ;
        }
    }

    return 0 ;
}
