#include <bits/stdc++.h>
#define inf 2000000000
#define ll long long
#define Max

using namespace std;

int n;
char g[305][305];
int visited[305][305],v[305][305];
priority_queue <pair< int , pair<int,int> > > pq;

bool valid(int x,int y)
{
    return (x>=0 && x<n && y>=0 && y<n);
}

int nbr(int x,int y)
{
    int i,j,k=0,nx,ny;

    for(i=-1;i<=1;i++)
    {
        for(j=-1;j<=1;j++)
        {
            if(i==0 && j==0) continue;

            nx=x+i;
            ny=y+j;

            if(valid(nx,ny)==0) continue;

            k+=(g[nx][ny]=='*');


        }
    }

    return k;
}

void dfs(int x,int y)
{
    visited[x][y]=1;

    if(v[x][y]!=0) return;

    int i,j,k,nx,ny;

    for(i=-1;i<=1;i++)
    {
        for(j=-1;j<=1;j++)
        {
            if(i==0 && j==0) continue;

            nx=x+i;
            ny=y+j;

            if(valid(nx,ny)==0) continue;

            if(g[nx][ny]=='*') continue;

            if(visited[nx][ny]==0) dfs(nx,ny);


        }
    }


}


int main()
{
    int i,j,k,T,cas,ret=0,x,y;

    freopen("A-large(7).in","r",stdin);
    freopen("a-Large.txt","w",stdout);

    scanf("%d",&T);

    for(cas=1;cas<=T;cas++)
    {

        while(!pq.empty()) pq.pop();

        scanf("%d",&n);

        for(i=0;i<n;i++) scanf("%s",g[i]);

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(g[i][j]=='.')
                {
                    visited[i][j]=0;
                    k=nbr(i,j);

                    v[i][j]=k;

                   // cout<<i<<" "<<j<<" "<<k<<endl;

                    pq.push(make_pair(-k,make_pair(i,j)));

                }
            }
        }

        ret=0;

        while(!pq.empty())
        {
            x=pq.top().second.first;
            y=pq.top().second.second;

            pq.pop();

           // cout<<x<<" "<<y<<endl;

            if(visited[x][y]==0)
            {
                ret++;
                dfs(x,y);
            }

        }

        printf("Case #%d: %d\n",cas,ret);
    }

    return 0;
}
