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

const int mod = 1000000007;

int nb(int x){return x==0?0:1+nb(x&(x-1));}
int F[20];
int c[22][22];
int d[111][11][11];
int b;
int go(int n,int per,int left){
    if(n==0) return per==0 && left==0? 1 : 0;
    if(left==0) return n==per ? 1 : 0;
    if(d[n][per][left]!=-1) return d[n][per][left];
    int val = 0;
    REP(i,1<<b)if(nb(i)==left){
        int sum = per;
        REP(j,b) if(i&(1<<j)) sum += j;
        if((sum-n)%b==0){
            REP(nl,left+1)if(left-(i&1?1:0) >= nl){
                ll temp  = go(n/b,sum/b,nl+(i&1?1:0));
                temp*=F[left];
                temp%=mod;
                temp*=c[left-(i&1?1:0)][nl];                
                temp%=mod;

                val += temp;
                val%=mod;
            }
        }
    }
    return d[n][per][left]=val;
}

ll qp(ll c,ll st){
    ll r = 1;
    while(st){
        if(st&1) r*=c,r%=mod;
        c*=c,c%=mod;
        st>>=1;
    }
    return r;
}
ll inv(int c) {return qp(c,mod-2);}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    F[0]=1;
    FOR(i,1,20) F[i]=F[i-1]*i;
    c[0][0]=1;
    FOR(i,1,20){
        c[i][0]=c[i][i]=1;
        FOR(j,1,i) c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    
    int TC;
    cin>>TC;
    REP(tc,TC){
        int n;
        cin>>n>>b;

        CL(d,-1);

        int res = 0;
        int f = 1;
        FOR(i,1,b+1){
            ll temp = go(n,0,i);
            f*=i;
            temp *= inv(f);
            temp%=mod;
            res+=temp;
            res%=mod;
        }

        printf("Case #%d: %d\n",tc+1,res);       
    }
    return 0;
}