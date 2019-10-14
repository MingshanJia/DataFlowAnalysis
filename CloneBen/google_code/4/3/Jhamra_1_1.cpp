#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define piii pair<pair<int,int>,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define SIZE 10000002
#define MOD 1000000007
#define LD long double
using namespace std;

inline ll getnum()
{
    char c = getchar();
    ll num,sign=1;
    for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;
    for(num=0;c>='0'&&c<='9';)
    {
        c-='0';
        num = num*10+c;
        c=getchar();
    }
    return num*sign;
}

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int tests=getnum();

    for(int cases=1;cases<=tests;cases++)
    {
        int n=getnum(),m=getnum(),ans;

        if(n==1||m==1)
        {
            if(n==1)ans=((m/3)*2+m%3);
            else ans=((n/3)*2+n%3);
        }
        else if(n==2||m==2)
        {
            if(n==2)ans=((m/3)*2+m%3)*2;
            else ans=((n/3)*2+n%3)*2;
        }
        else
        {
            ans=0;
            for(int a=0;a<=2;a++)
            {
                int mx=0;
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if((i+j)%3!=a)mx++;
                    }
                }
                ans=max(ans,mx);
            }
        }

        printf("Case #%d: %d\n",cases,ans);
    }
}
