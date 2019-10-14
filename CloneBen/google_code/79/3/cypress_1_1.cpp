#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const LL oo=100000000000000000ll;
const int maxn=1010000;

LL t,ans;
int n,c,l;
bool flag[maxn];
int a[maxn];

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

double jie[maxn];
int num[maxn];

bool comp(int i,int j){
     return jie[i]>jie[j];
}



void work1(){
     double now=0;
     for (int i=1;i<=n;i++) {
         num[i]=i;
         if (now>=t) jie[i]=a[i];
            else {
                 double remain=t-now;
                 if (remain>=a[i]*2) { jie[i]=0; now+=a[i]*2; }
                    else {
                         now+=remain;
                         jie[i]=(2*a[i]-remain)/2;
                         now+=(2*a[i]-remain)/2;
                    }
            }
     }
     sort(num+1,num+n+1,comp);
     for (int i=1;i<=l;i++) 
         flag[num[i]]=true;
}

void work2(){
     double now=0;
     for (int i=1;i<=n;i++) {
         num[i]=i;
         if (now>=t) jie[i]=a[i];
            else {
                 now+=a[i]*2;
            }
     }
     sort(num+1,num+n+1,comp);
     for (int i=1;i<=l;i++) 
         flag[num[i]]=true;
}

void solve(){
     scanf("%d%I64d%d%d",&l,&t,&n,&c);
     for (int i=1;i<=c;i++) {
         scanf("%d",&a[i]);
         for (int j=i;j<=n;j+=c) a[j]=a[i];
     }
     ans=oo;
     memset(flag,false,sizeof(flag));
     
     work1();
     ans=min(ans,calc());
     work2();
     ans=min(ans,calc());
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
