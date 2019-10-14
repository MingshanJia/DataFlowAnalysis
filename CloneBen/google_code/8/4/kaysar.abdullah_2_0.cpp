
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


const int N = 1000006;

int a[N],d[N];
vector<int>fact;


int f( int x )
{
    int k=0;
    while(x)
    {
        int b=x%10;
        x/=10;
        if( !a[b] )return -1;
        k++;
    }
    return k;
}

int main()
{


    freopen("cin.in","r",stdin);
    freopen("cout.txt","w",stdout);


    int i,ks,j,k,T,x,y,z,c;
    cin>>T;

//    cout<<T<<endl;

    for(  ks=1;ks<=T;ks++ )
    {
        for(i=0;i<10;i++)cin>>a[i];
        cin>>x;


        priority_queue< pii >pq;
        SET(d,-1);

        fact.clear();

        for( i=1;i*i<=x;i++ )
        {
            if( x%i==0 )
            {
                if( f(i)!=-1 )fact.pb( i );
                k=x/i;
                if(k!=i && f(k)!=-1 )fact.pb( k );
            }
        }

        int sz=fact.size();


        for( i=0;i<sz;i++ )
        {
            k=fact[i];
            d[ k ]=f( k );
            if( d[ k ]!=-1 )pq.push( mp( -d[k],k ) );
        }

        pii u,v;

        //cout<<x<<endl;

        while(!pq.empty())
        {
            u=pq.top();
            pq.pop();


           // cout<<u.second<<" "<<d[u.second]<<endl;

            if( u.second==x )break;

            y=x/u.second;

            fact.clear();
            for( i=1;i*i<=y;i++ )
            {
                if( y%i==0 )
                {
                    if( f(i)!=-1 )fact.pb( i );
                    k=y/i;
                    if(k!=i && f(k)!=-1 )fact.pb( k );
                }
            }


            int sz=fact.size();

            for( i=0;i<sz;i++ )
            {
                k=fact[i];
                c=d[u.second]+f( k )+1;
                v=mp( -c,u.second*k );

                if( d[ v.second ]==-1 || d[ v.second ]>c  )
                {
                    d[ v.second ]=c;
                    pq.push( v );
                }
            }

        }

        if(d[x]!=-1)printf("Case #%d: %d\n",ks,d[x]+1);
        else printf("Case #%d: Impossible\n",ks);


    }
    return 0;
}





















