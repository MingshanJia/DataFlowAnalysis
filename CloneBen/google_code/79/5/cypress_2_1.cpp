#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long LL;

LL a[10100000],b[10100000],tt,n,L,H;
bool pd;

bool check(LL k){
     for (int i=1;i<=n-1;i++)
         if ((a[i]%k!=0)&&(k%a[i]!=0)) return false;
     return true;
}

const double eps=1e-8;

LL gcd(LL a,LL b){    
   while (b) {
         LL c=a%b;
         a=b; b=c;
   }  
   return a;
}

void getlcm(){
     LL ans=1;
     for (int i=1;i<=n;i++) {
         LL tgcd=gcd(ans,a[i]);
         LL temp=a[i]/tgcd;
         if (double(ans)>(double(H)/double(temp)+eps)) return ;
         ans=ans*temp;
         if (ans>H) return ;
     }
     
     if (ans<L) ans=ans*((L/ans)+1);
     
     if (ans>=L&&ans<=H) {
        pd=true;
        cout<<ans<<"\n";
     }
}

void solve(){
     scanf("%d%I64d%I64d",&n,&L,&H);
     for (int i=1;i<=n;i++)
         scanf("%I64d",&a[i]);
     sort(a+1,a+n+1);
     LL maxn=a[n];
     tt=0;
     for (LL i=1;i*i<=maxn;i++) {
         if (maxn%i==0) {
            LL temp=i;
            if (temp>=L&&temp<=H) b[++tt]=temp;
            temp=maxn/i;
            if (temp>=L&&temp<=H) b[++tt]=temp;
         }
     }
     sort(b+1,b+tt+1);
     pd=false;
     for (int i=1;i<=tt;i++)
         if (check(b[i])) {
            cout<<b[i]<<"\n";
            pd=true;
            break;
         }
     if (pd==false) getlcm();
     if (pd==false) cout<<"NO\n";
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
