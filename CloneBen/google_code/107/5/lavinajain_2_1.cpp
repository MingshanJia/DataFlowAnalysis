// Lavina Jain
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MAX 1000000007
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define cases int t; cin>>t; while(t--)
ll mini(ll a,ll b) { if(a<b) return a; return b; }
ll maxi(ll a,ll b) { if(a>b) return a; return b; }
ll mod(ll a) { return a % MAX ; }
ll power(ll a,ll b) { if(b==0) return 1; else if(b%2==0) return power(a*a,b/2); else return a*power(a*a,b/2); }
ll powermod(ll a,ll b) { if(b==0) return 1; else if(b%2==0) return mod(powermod(mod(a*a),b/2)); else return mod(a)*mod(powermod(mod(a*a),b/2)); }
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

map< pair<char,char> , int> mp;
int n;

bool cycle(char A, char B, char C)
{
    if(mp.count(MP(A,B))==0 || mp.count(MP(B,C))==0 || mp.count(MP(C,A))==0)
        return false;
    if(mp[MP(A,B)]==1 && mp[MP(B,C)]==1 && mp[MP(C,A)]==1)
        return true;
    return false;
}

bool detect()
{
    for(int i=65;i<=90;i++)
    {
        for(int j=i+1;j<=90;j++)
        {
            for(int k=j+1;k<=90;k++)
            {
                if(cycle(char(i),char(j),char(k)))
                    return false;
                if(cycle(char(i),char(k),char(j)))
                    return false;
                if(cycle(char(j),char(i),char(k)))
                    return false;
                if(cycle(char(j),char(k),char(i)))
                    return false;
                if(cycle(char(k),char(j),char(i)))
                    return false;
                if(cycle(char(k),char(i),char(j)))
                    return false;
            }
        }
    }
}

bool func(string a,string b,string c)
{
    mp.clear();
    bool ans=true;
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i])
            continue;
        mp[MP(a[i],b[i])]=1;
        mp[MP(b[i],a[i])]=-1;
        break;
    }
    for(int i=0;i<n;i++)
    {
        if(b[i]==c[i])
            continue;
        if(mp.count(MP(b[i],c[i]))==0)
        {
            mp[MP(b[i],c[i])]=1;
            mp[MP(c[i],b[i])]=-1;
            break;
        }
        if(mp[MP(b[i],c[i])]==-1)
            ans=false;
        break;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==c[i])
            continue;
        if(mp.count(MP(a[i],c[i]))==0)
        {
            mp[MP(a[i],c[i])]=1;
            mp[MP(c[i],a[i])]=-1;
            break;
        }
        if(mp[MP(a[i],c[i])]==-1)
            ans=false;
        break;
    }
    ans=ans&&detect();
    return ans;
}

int main()
{
    fast_io;
    int T;
    cin>>T;
    for(int q=1;q<=T;q++)
    {
        cout<<"Case #"<<q<<": ";
        string a,b,c;
        cin>>n>>a>>b>>c;
        if(func(b,a,c)||func(c,a,b))
            cout<<"YES ";
        else
            cout<<"NO ";
        if(func(a,b,c)||func(c,b,a))
            cout<<"YES ";
        else
            cout<<"NO ";
        if(func(a,c,b)||func(b,c,a))
            cout<<"YES ";
        else
            cout<<"NO ";
        cout<<endl;
    }
    return 0;
}
