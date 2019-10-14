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

struct generator
{
    int a,b,A,B,C,M;
    vector<int> result;
    void read(){scanf("%d%d%d%d%d%d",&a,&b,&A,&B,&C,&M);}
    void gen(int nn)
    {
        result.clear();
        result.pb(a);
        result.pb(b);
        for(int i=2;i<nn;i++)
        {
            LL tmp=1ll*A*result[i-1]+1ll*B*result[i-2]+C;
            result.pb((int)(tmp%M));
        }
    }
}x,y,z;

int n,q,T;
int l[400005],r[400005],ans[100005];
pii query[100005];
int lsh[1000005],ls[1000005],lsc;
int gin[1000005],gout[1000005];

void solve()
{
    LL sum=0;
    ls[0]=0;ls[lsc+1]=0;
    int label=1,cnt=0;
    for(int i=lsc;i>=1;i--)
    {
        LL nxt=sum+1ll*(ls[i+1]-ls[i])*cnt;
        while(label<=q && query[label].fi<=nxt)
        {
            int tmp=query[label].fi-sum;
            int ret=ls[i+1]-(tmp+cnt-1)/cnt;
            ans[query[label].se]=ret;
            label++;
        }
        nxt+=gin[i];
        while(label<=q && query[label].fi<=nxt)
        {
            ans[query[label].se]=ls[i];
            label++;
        }
        cnt-=gout[i];cnt+=gin[i];
        sum=nxt;
    }
}

int main()
{
    IN;OUT;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d",&n,&q);
        x.read();y.read();z.read();
        x.gen(n);y.gen(n);z.gen(q);
        for(int i=1;i<=n;i++)
        {
            int xx=x.result[i-1],yy=y.result[i-1];
            l[i]=min(xx,yy)+1;
            r[i]=max(xx,yy)+1;
            lsh[2*i-1]=l[i];
            lsh[2*i]=r[i];
        }
        sort(lsh+1,lsh+2*n+1);ls[lsc=1]=lsh[1];for(int i=2;i<=2*n;i++)if(lsh[i]!=lsh[i-1])ls[++lsc]=lsh[i];
        for(int i=1;i<=lsc;i++){gin[i]=gout[i]=0;}
        for(int i=1;i<=n;i++){ l[i]=lower_bound(ls+1,ls+lsc+1,l[i])-ls; r[i]=lower_bound(ls+1,ls+lsc+1,r[i])-ls; gin[r[i]]++;gout[l[i]]++; }
        for(int i=1;i<=q;i++)query[i]=mp(z.result[i-1]+1,i),ans[i]=0;
        sort(query+1,query+q+1);
        solve();
        LL ret=0;
        for(int i=1;i<=q;i++)
        {
            //printf("%d %d %d\n",i,z.result[i-1]+1,ans[i]);
            ret+=1ll*i*ans[i];
        }
        prr(cas);printf("%lld\n",ret);
    }
    return 0;
}
