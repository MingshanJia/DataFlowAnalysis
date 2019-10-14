#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

typedef long long ll;

using namespace std;

const int Mod = 1000000007;

ll A[111],X,Y,Z;
int a[555555],n,m;
int f[1111][1111];

int F(int i,int j){
    if(j>=n)return 1;
    int &res=f[i][j];
    if(res<0){
        res=F(i,j+1);
        if(a[j]>a[i])res=(res+F(j,j))%Mod;
    }
    return res;
}

int main(){
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    int tc=0,T;
    for(cin>>T;tc++<T;){
        int res=0;
        cin>>n>>m>>X>>Y>>Z;
        for(int i=0;i<m;++i)cin>>A[i];
        for(int i=0;i<n;++i){
            a[i]=A[i%m];
            A[i%m]=(X*A[i%m]+Y*(i+1))%Z;
        }
        memset(f,-1,sizeof f);
        for(int i=0;i<n;++i)res=(res+F(i,i))%Mod;
        printf("Case #%d: %d\n",tc,res);
    }
    return 0;
}
