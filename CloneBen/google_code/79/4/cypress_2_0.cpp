#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int a[101010],N,L,H;
bool pd;

bool check(int k){
     for (int i=1;i<=N;i++)
         if ((a[i]%k!=0)&&(k%a[i]!=0)) return false;
     return true;
}

void solve(){
     scanf("%d%d%d",&N,&L,&H);
     for (int i=1;i<=N;i++) 
         scanf("%d",&a[i]);
     pd=false;
     for (int i=L;i<=H;i++) {
         if (check(i)) {
            pd=true;
            printf("%d\n",i);
            break;
         }
     }
     if (!pd) printf("NO\n");
}

int main(){
    
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    
    int test;
    scanf("%d",&test);
    for (int tot=1;tot<=test;tot++) {
        printf("Case #%d: ",tot);
        solve();
    }
    
    return 0;
}
