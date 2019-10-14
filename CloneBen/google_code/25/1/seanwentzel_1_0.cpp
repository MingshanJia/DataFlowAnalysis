#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include<utility>
#include<algorithm>
#include<cassert>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<bitset>
#include<string>
#include<list>

#define f(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef  pair<int,int> pii;
typedef  pair<double, double> pdd;
typedef  pair<long long,long long> pll;
typedef  vector<int> vi;
typedef  pair<int,bool> pib;
typedef  vector<long long> vl;


ifstream fin;
ofstream fout;
int main()
{
    fin.open("B-small-attempt1.in");
    fout.open("B.out");
    int numcases;
    fin>>numcases;
    f(cas,1,numcases+1)
    {
     fout<<"Case #"<<cas<<": ";
     int n,r;
     fin>>n>>r;
     vi adjlist[n];
     int temp,t2;
     int numcomps;
     int comp[n];
     f(i,0,r)
     {
             fin>>temp>>t2;
             adjlist[temp].pb(t2);
             adjlist[t2].pb(temp);     
     }
     queue<int> bfs;
     f(i,0,n)
     {
             comp[i]=-1;
     }
     int curr=0;
     f(j,0,n)
     {
            // cerr<<j<<"\n";
             if(comp[j]==-1&&adjlist[j].size()!=0)
             {
                   bfs.push(j);
                   comp[j]=curr;
                   while(!bfs.empty())
                   {
                                      temp=bfs.front();
                                      //cerr<<"   "<<temp<<"\n";
                                      f(i,0,adjlist[temp].size())
                                      {
                                                                 if(comp[adjlist[temp][i]]==-1)
                                                                 {
                                                                                              comp[adjlist[temp][i]]=curr;
                                                                                              bfs.push(adjlist[temp][i]);
                                                                 }
                                      }
                                      bfs.pop();
                   }
                   curr++;
             }
     }
     int x=curr;
     int numodds[x];
     int totodds=0;
    // cerr<<"here";
     f(i,0,x)
     {
             numodds[i]=0;
     }
     f(i,0,n)
     {
             if(adjlist[i].size()%2==1)
             {
                                       numodds[comp[i]]++;
                                       totodds++;
             }
             //cerr<<comp[i]<<"\n";
     }
     int evencomps=0;
     int tot=0;
     f(i,0,x)
     {
             if(numodds[i]==0)
             {
                              evencomps++;
                              
             }
             
     }
   //  cerr<<totodds<<" "<<evencomps<<" "<<x<<"\n";
     if(totodds==0&&x==1)
     {
                   fout<<"0\n";
     }
     else{
     fout<<evencomps+(totodds/2)<<"\n";}
     //cin>>n;
     
        
     
     
    }
    
    fin.close();
    fout.close();
    return 0;
}
