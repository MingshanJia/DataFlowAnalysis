/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
  
LL a[200005];
int T,n;

int cnt[200005];

int main()
{
    IN;OUT;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        long long ans = 0,cnt0=0;
        for(int i=1;i<=n;i++)if(a[i]==0)cnt0++;else break;
        ans+=cnt0*(cnt0-1)*(cnt0-2)/6;
        ans+=cnt0*(cnt0-1)/2*(n-cnt0);
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)continue;
            for(int j=0;j<=200000;j++)cnt[j]=0;
            for(int j=i+1;j<=n;j++)cnt[a[j]]++;
            for(int j=i+1;j<=n;j++)
            {
                LL tmp=1ll*a[i]*a[j];
                if(tmp>200000)break;
                cnt[a[j]]--;
                ans+=cnt[tmp];
            }
        }
        prr(cas);printf("%lld\n",ans);
    }
    return 0;
}
