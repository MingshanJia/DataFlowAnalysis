#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

int par[500];

void init(){
    for(int i=0;i<500;i++)
        par[i]=i;
}

int find_par(int x){
    if(par[x]!=x)
        return par[x]=find_par(par[x]);
    return x;
}

void Union(int x,int y){
    int px=find_par(x);
    int py=find_par(y);
    if(px==py)
        return;
    par[px]=py;
}

int main()
{
    int t,m,ans=1;
    cin>>t;
    while(t--){
        cin>>m;
        string a,b;
        map<string,int> p1;
        p1.clear();
        init();
        bool l=1;
        int cnt=1;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            if(!p1[a]) p1[a]=cnt++;
            if(!p1[b]) p1[b]=cnt++;
            if(find_par(p1[a])==find_par(p1[b])||find_par(p1[a]+101)==find_par(p1[b]+101))
                l=0;
            else{
                Union(p1[a],p1[b]+101);
                Union(p1[b],p1[a]+101);
            }
        }
        //for(it=p1.begin();it!=p1.end();it++)
          //  cout<<it->first<<" "<<it->second<<endl;
        printf("Case #%d: ",ans++);
        if(l)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
