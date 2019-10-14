#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e3+10;



int need,n,a[N];
int main(){
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int test;
    scanf("%d",&test);
    for(int te=1;te<=test;te++){
        scanf("%d%d",&need,&n);
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        printf("Case #%d: ",te);
        sort(a+1,a+n+1);

        int ans=0;
        for(int re=0;2*re<=n;re++){
            bool okay=1;
            int cur=need;
            for(int i=1;i<=re&&okay;i++){
                if (cur<=a[i]) okay=0;
                else cur+=a[n-i+1]-a[i];
            }
            if (okay){
                int hor=0;
                for(int i=re+1;i<=n-re;i++) if (cur>a[i]){
//                    cout<<re<<" "<<cur<<" "<<a[i]<<'\n';
                    hor++,cur-=a[i];
                }
                ans=max(ans,hor);
//                cout<<re<<" "<<hor<<'\n';
            }
        }
        printf("%d\n",ans);
    }
}
