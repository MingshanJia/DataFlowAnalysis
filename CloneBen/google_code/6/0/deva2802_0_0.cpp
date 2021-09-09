#include <bits/stdc++.h>
#define MAX 1000005
#define ll long long
#define upperlimit 1000100
#define INF 1e18
#define eps 1e-8
#define endl '\n'
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define MOD 1000000007LL
#define slld(t) scanf("%lld",&t)
#define sd(t) scanf("%d",&t)
#define pd(t) printf("%d\n",t)
#define plld(t) printf("%lld\n",t)
#define mp(a,b) make_pair(a,b)
#define FF first
#define SS second
#define pb(x) push_back(x)
#define vi vector<int>
#define vll vector<ll>
#define clr(a) memset(a,0,sizeof(a))
#define debug(a) printf("check%d\n",a)
#define csl ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
 
ll gcd(ll n1,ll n2){
    if(n2==0)
        return n1;
    if(n1%n2==0)return n2;
    return gcd(n2,n1%n2);
}
ll powmod(ll base,ll exponent)
{
    ll ans=1;
    while(exponent){
        if(exponent&1)ans=(ans*base);
        base=(base*base);
        exponent/=2LL;
    }
    return ans;
}
ll fact[MAX],ifact[MAX];
ll choose(ll n,ll r)
{
    ll ans=fact[n]*ifact[r];
    ans%=MOD;
    ans*=ifact[n-r];
    ans%=MOD;
    return ans;
}
map<string,int> m;
string s[MAX];
int main()
{
    // csl;
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n,p;
        cin>>n>>p;
        m.clear();
        ll ans=powmod(2,n);
        for(int i=0;i<p;i++)
        {
            cin>>s[i];
            m[s[i]]=1;
        }
        for(int i=0;i<p;i++)
        {
            string now="";
            bool flag=false;
            for(int j=0;j<s[i].length()-1;j++)
            {
                now+=s[i][j];
                if(m[now])
                    flag=true;
            }
            if(flag)
                continue;
            else
            {
                int l=s[i].length();
                ans-=powmod(2,n-l);
            }
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
}