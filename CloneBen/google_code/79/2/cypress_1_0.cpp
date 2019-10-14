#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const LL oo=100000000000000000ll;

LL t,ans;
int n,c,l;
bool flag[1010];
int a[101000];

LL calc(){
   double ret=0;
   for (int i=1;i<=n;i++) {
       if (flag[i]==false) ret+=a[i]*2;
          else {
               if (ret>=t) ret+=a[i];
                  else {
                       double remain=t-ret;
                       if (remain>=2*a[i]) ret+=a[i]*2;
                          else {
                               ret+=remain;
                               ret+=(2*a[i]-remain)/2;
                          }
                  }
          }
   }
   return (LL)(ret+0.5);
}

void solve(){
     scanf("%d%I64d%d%d",&l,&t,&n,&c);
     for (int i=1;i<=c;i++) {
         scanf("%d",&a[i]);
         for (int j=i;j<=n;j+=c) a[j]=a[i];
     }
     ans=oo;
     memset(flag,false,sizeof(flag));
     if (l==0) ans=calc();
     if (l==1) {
        for (int i=1;i<=n;i++) {
            flag[i]=true;
            ans=min(ans,calc());
            flag[i]=false;
        }
     }
     if (l==2) {
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++) {
                flag[i]=true;
                flag[j]=true;
                ans=min(ans,calc());
                flag[i]=false;
                flag[j]=false;
            }
     }
     cout<<ans<<endl;
}

int main(){
    
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    
    int test;
    scanf("%d\n",&test);
    for (int tot=1;tot<=test;tot++) {
        printf("Case #%d: ",tot);
        solve();
    }
    
    return 0;
}
