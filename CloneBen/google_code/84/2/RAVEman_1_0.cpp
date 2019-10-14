#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

const int inf = 1011111111;
const ll INF = 1000000000000000011ll;
int d[11111];
ll l;
int n;
int a[111];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
    int TC;
    cin>>TC;
    REP(tc,TC){
        cin>>l>>n;
        REP(i,n) cin>>a[i];
        sort(a,a+n);
        REP(i,11111) d[i]=inf;
        d[0]=0;
        REP(i,n) REP(j,10000) d[j+a[i]] = min (d[j+a[i]], d[j] + 1);
        ll res = INF;
        REP(j,n) REP(i,10000) if(((l-i)%a[j])==0)
            if(d[i]!=inf)
                res = min(res, (l-i)/a[j] + d[i]);

        printf("Case #%d: ",tc+1);

        if(res==INF) puts("IMPOSSIBLE");
        else cout<<res<<endl;
       
    }
    return 0;
}