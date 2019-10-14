#include <bits/stdc++.h>
#define inf 2000000000
#define ll long long
#define Max 2005

using namespace std;

vector <int> myvec[Max],weight[Max];
int dist[Max],visited[Max],N;
priority_queue < pair<int,int> > pq;

int sn[105],w[105],cc[105][Max],id[105][Max],n,m;

void dijkstra(int s)
{
    int i,j,k,w;

    for(i=1;i<=N;i++)
    {
        dist[i]=inf;
        visited[i]=0;
    }

    while(!pq.empty()) pq.pop();

    pq.push(make_pair(0,s));
    dist[s]=0;

    while(!pq.empty())
    {
        do
        {
            //cout<<pq.size()<<endl;

            if(pq.empty())
            {
                i=-1;
                break;
            }
            i=pq.top().second;
            pq.pop();
        }while(visited[i]);

        if(i==-1) break;


       // if(pq.empty()) break;

        visited[i]=1;

       // cout<<i<<endl;

        for(j=0;j<myvec[i].size();j++)
        {
            k=myvec[i][j];
            w=weight[i][j];

            if(dist[i]+w<dist[k])
            {
                dist[k]=dist[i]+w;
                pq.push(make_pair(-1*dist[k],k));
            }
        }
    }
}

void add(int a,int b,int c)
{
   // printf("Both : %d %d : %d\n",a,b,c);
    myvec[a].push_back(b);
    weight[a].push_back(c);
    myvec[b].push_back(a);
    weight[b].push_back(c);
}

void sad(int a,int b,int c)
{
    //printf("Single : %d %d : %d\n",a,b,c);
    myvec[a].push_back(b);
    weight[a].push_back(c);
}


int main()
{
    int i,j,k,T,cas,ret=0,t;

    //freopen("in.txt","r",stdin);

    freopen("B-small-attempt1(5).in","r",stdin);
   freopen("b-small-new.txt","w",stdout);

    scanf("%d",&T);

    for(cas=1;cas<=T;cas++)
    {
        //cout<<"here"<<endl;

        scanf("%d",&n);

        for(t=i=1;i<=n;i++)
        {
            scanf("%d %d",&sn[i],&w[i]);

            for(j=1;j<sn[i];j++)
            {
                scanf("%d",&cc[i][j]);
                id[i][j]=t;
                myvec[t].clear();
                weight[t].clear();
                myvec[t+1].clear();
                weight[t+1].clear();
                t+=2;
            }

            id[i][j]=t;
            myvec[t].clear();
            weight[t].clear();
            myvec[t+1].clear();
            weight[t+1].clear();
            t+=2;
        }

        N=t-1;

        //cout<<N<<endl;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<sn[i];j++)
            {
                add(id[i][j]+1,id[i][j+1]+1,cc[i][j]);
                sad(id[i][j]+1,id[i][j+1],cc[i][j]);
                sad(id[i][j+1]+1,id[i][j],cc[i][j]);

                sad(id[i][j],id[i][j]+1,w[i]);
            }

            sad(id[i][j],id[i][j]+1,w[i]);
        }

        scanf("%d",&m);

        int x1,y1,x2,y2;

        for(int it=0;it<m;it++)
        {
            scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&k);

            add(id[x1][y1],id[x2][y2],k);
        }

        int q;

        scanf("%d",&q);

        printf("Case #%d:\n",cas);

        for(int it=0;it<q;it++)
        {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

            dijkstra(id[x1][y1]);

            k=id[x2][y2];

            if(visited[k]==0)
            {
                printf("-1\n");
                continue;
            }

            printf("%d\n",dist[k]);

        }
    }

    return 0;
}
