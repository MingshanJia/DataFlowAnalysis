#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x << " = " << x << endl

int a[110],b[110];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,ti,k,ans;
    scanf("%d",&t);
    for(ti=1; ti<=t; ti++)
    {
        ans=0;
        scanf("%d",&k);
        for(int i=0; i<k; i++)
            scanf("%d",&a[i]);
        sort(a,a+k);
        int j;
        for(int i=j=0; i+1<k; i+=2)
            b[i]=b[i+1]=j++;
        if(k&1)
            b[k-1]=j;
        for(int i=0; i<k; i++) //dbg(a[i]);
            ans+=(a[i]-b[i])*(a[i]-b[i]);
        printf("Case #%d: %d\n",ti,ans);

    }
    return 0;
}
