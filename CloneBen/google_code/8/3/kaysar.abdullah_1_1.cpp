
#define ll long long
#define vi vector <int>
#define pii pair <int,int>
#define FOR(i, a, b) for (i = (a); i <= (b); i++)
#define REP(i, a) for (i = 0; i < (a); i++)
#define ALL(v) (v).begin(), (v).end()
#define SET(a, x) memset((a), (x), sizeof(a))
#define SZ(a) ((int)(a).size())
#define CL(a) ((a).clear())
#define SORT(x) sort(ALL(x))
#define mp make_pair
#define pb push_back
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define filer() freopen("in.txt","r",stdin)
#define filew() freopen("out.txt","w",stdout)

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
#include <cassert>


using namespace std;


const int N = 2003;
int n,m,q,s[N],w[N],t[N][N],ct[N][N],m1[N],s1[N],m2[N],s2[N],x_1,y_1,x_2,y_2,h[N][N],d[N][2],walk[N];

struct Node
{
    int x,y,c,t;
    Node(){}
    Node(int _x,int _y,int _c=0){x=_x,y=_y;c=_c;}
    void print(){cout<<x<<" "<<y<<" "<<d[h[x][y]]<<endl;}
};
bool operator<(Node n1,Node n2)
{
    return d[ h[n1.x][n1.y] ][n1.t]>d[ h[n2.x][n2.y] ][n2.t];
}
vector< vector<Node> >e;
void up(Node &u,Node &v,int c)
{
    return;
}

int main()
{
    freopen("bin2.in","r",stdin);
    freopen("bout2.txt","w",stdout);


    int T,ks,i,j,k,c;
    cin>>T;
    for(ks=1;ks<=T;ks++)
    {
        scanf("%d",&n);
        k=0;

        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&s[i],&w[i]);

            h[i][1]=k++;

            for(j=2;j<=s[i];j++)
            {
                scanf("%d",&t[i][j]);
                ct[i][j]=ct[i][j-1]+t[i][j];
                h[i][j]=k++;
            }
        }


        e=vector< vector<Node> >( k );

        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d%d%d",&m1[i],&s1[i],&m2[i],&s2[i],&walk[i]);
            e[ h[m1[i]][s1[i]] ].pb(  Node(m2[i],s2[i],walk[i])  );
            e[ h[m2[i]][s2[i]] ].pb(  Node(m1[i],s1[i],walk[i])  );
        }

        printf("Case #%d:\n",ks);
        scanf("%d",&q);

      //  cout<<q<<endl;while(1);

        while(q--)
        {
            scanf("%d%d%d%d",&x_1,&y_1,&x_2,&y_2);

            priority_queue< Node >pq;
            SET(d,-1);

            d[ h[x_1][y_1] ][0]=0;
            pq.push( Node(x_1,y_1,0) );

            Node u,v;

            while(!pq.empty())
            {
                u=pq.top();
                pq.pop();


              //  u.print();


                if( u.x==x_2 && u.y==y_2 )break;



                j=h[u.x][u.y];



                if(!u.t) // get into the metro
                {
                    v=u;
                    v.t=1;
                    k=h[v.x][v.y];
                    c=w[v.x];

                    if( d[k][v.t] ==-1 || d[k][v.t] > d[j][u.t] +c )
                    {
                        d[k][v.t] = d[j][u.t] +c;
                        pq.push( v );
                    }

                }


                int sz=e[ j ].size(); // use the tunnel
                for( i=0;i<sz;i++ )
                {
                    v=e[j][i];
                    v.t=0;
                    k=h[v.x][v.y];
                    c=v.c;

                    if( d[k][v.t] ==-1 || d[k][v.t] > d[j][u.t] + c )
                    {
                        d[k][v.t] = d[j][u.t] +c;
                        pq.push( v );
                    }
                }


                if(u.t) // already in the matro go to another station
                {
                    for( i=1;i<u.y;i++ ) // left
                    {
                        v=Node( u.x,i );
                        v.t=1;
                        k=h[v.x][v.y];
                        c=ct[u.x][u.y]-ct[v.x][v.y];

                        if( d[k][v.t] ==-1 || d[k][v.t] > d[j][u.t] +c )
                        {
                            d[k][v.t] = d[j][u.t] +c;
                            pq.push( v );
                        }


                    }

                    for( i=u.y+1;i<=s[u.x];i++ )
                    {
                        v=Node( u.x,i );
                        v.t=1;
                        k=h[v.x][v.y];
                        c=ct[v.x][v.y]-ct[u.x][u.y];

                        if( d[k][v.t] ==-1 || d[k][v.t] > d[j][u.t] +c )
                        {
                            d[k][v.t] = d[j][u.t] +c;
                            pq.push( v );
                        }

                    }
                }




            }

            if(u.x==x_2 && u.y==y_2)printf("%d\n",d[ h[u.x][u.y] ][u.t]);
            else printf("-1\n");

        }



    }
    return 0;
}

















