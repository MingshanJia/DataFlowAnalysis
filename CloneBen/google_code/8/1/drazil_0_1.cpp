#include <stdio.h>

char str[310][310] ;
int n ;
int ans ;
int dir[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}} ;

bool isGood(int x, int y)
{
    for(int d=0;d<8;d++)
    {
        int dx = x+dir[d][0] ;
        int dy = y+dir[d][1] ;
        if(dx<0 || dy<0 || dx>=n || dy>=n)
            continue ;
        if(str[dx][dy]=='*')
            return false ;
    }
    return true ;
}

void go(int x, int y)
{
    str[x][y] = 'c' ;
    if(isGood(x,y))
        for(int d=0;d<8;d++)
        {
            int dx = x+dir[d][0] ;
            int dy = y+dir[d][1] ;
            if(dx<0 || dy<0 || dx>=n || dy>=n)
                continue ;
            if(str[dx][dy]=='.')
                go(dx,dy) ;
        }
}

int main(void)
{
    int T ;
    int tc ;

    scanf("%d",&T) ;

    for(tc=1;tc<=T;tc++)
    {
        scanf("%d",&n) ;

        for(int i=0;i<n;i++)
            scanf("%s", str[i]) ;

        ans = 0 ;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(str[i][j]=='.' && isGood(i,j))
                {
                    go(i,j) ;
                    ans++ ;
                }

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(str[i][j]=='.')
                    ans++ ;

        printf("Case #%d: %d\n",tc,ans) ;
    }
}
