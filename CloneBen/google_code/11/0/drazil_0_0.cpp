#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std ;

int m[1100][1100] ;
int cnt[1100][1100] ;

int main(void)
{
    int T ;
    scanf("%d",&T) ;
    int t ;
    int x, y ;
    
    for(t=1;t<=T;t++)
    {
        int n, n2 ;
        
        scanf("%d",&n) ;
        n2 = n*n ;
        
        bool p = true ;

        memset(cnt,0,sizeof(cnt)) ;
        
        for(x=0;x<n2;x++)
        {
            for(y=0;y<n2;y++)
            {
                scanf("%d",&m[x][y]) ;
                if(m[x][y]<=0||m[x][y]>n2)  p = false ;
                cnt[(x/n)*n+(y/n)][m[x][y]]++ ;
                if(cnt[(x/n)*n+(y/n)][m[x][y]]>1) p = false ;
            }
        }
        
        for(x=0;x<n2;x++)
        {
            int a[1100], b[1100] ;
            memset(a,0,sizeof(a)) ;
            memset(b,0,sizeof(b)) ;
            
            for(y=0;y<n2;y++)
            {
                a[m[x][y]]++ ;
                b[m[y][x]]++ ;
                if(a[m[x][y]]>1) p = false ;
                if(b[m[y][x]]>1) p = false ;
            }
        }
        
        if(p) printf("Case #%d: Yes\n",t) ;
        else printf("Case #%d: No\n",t) ;
    }
    
    return 0 ;
}
