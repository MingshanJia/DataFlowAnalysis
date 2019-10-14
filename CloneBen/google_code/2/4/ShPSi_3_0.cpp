#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e4+10;


int n,f[N];

int main(){
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);

    fill(f+1,f+N,N);
    for(int i=1;i<N;i++)
        for(int j=1;j*j<=i;j++) f[i]=min(f[i],f[i-j*j]+1);
    int test;
    scanf("%d",&test);
    for(int te=1;te<=test;te++){
        scanf("%d",&n);
        printf("Case #%d: %d\n",te,f[n]);
    }
}
