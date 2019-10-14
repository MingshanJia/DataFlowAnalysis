#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

int T,N,L,H,A[105];
int main(){
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    cin>>T;
    for (int t=1;t<=T;++t) {
        cin>>N>>L>>H;
        cout<<"Case #"<<t<<": ";
        for (int i=1;i<=N;++i) scanf("%d",&A[i]);
        bool flag;
        for (int i=L;i<=H;++i) {
            flag=true;
            for (int j=1;j<=N;++j)
                if (A[j]%i!=0 && i%A[j]!=0) {flag=false;break;}
            if (flag) {cout<<i<<"\n";break;}   
        }
        if (!flag) cout<<"NO\n";
    }
    return 0;
}
