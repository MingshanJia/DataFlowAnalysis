#include<bits/stdc++.h>
#include <unistd.h>
using namespace std;

#define sd(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
#define sl(a) scanf("%lld",&a)
#define clr(a) memset(a,0,sizeof(a))
#define debug(a) printf("check%d\n",a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
#define N 5010

map<ll,ll> mapp;
vector<pair<ll,ll> > v;
ll prefix[N];

int main()
{
	// freopen("B1.in","r",stdin);
	// freopen("B1.out","w",stdout);
	int t;
	sd(t);
	for(int tt=1;tt<=t;tt++)
	{
		// cerr<<"test: "<<tt<<'\n';
		mapp.clear();
		v.clear();
		clr(prefix);
		int n,i,j,k;
		sd(n);
		for(i=1;i<=n;i++)
		{
			int x;
			sd(x);
			mapp[x]++;
		}
		for(auto p:mapp)
			v.PB(p);
		prefix[0]=v[0].S;
		for(i=1;i<v.size();i++)
			prefix[i]=prefix[i-1]+v[i].S;
		ll ans=0;
		for(int i=0;i<v.size();i++)
		{
			ll h=v[i].F;
			int p1=0, p2=0;
			for(j=0;j<v.size();j++)
			{
				ll h1=v[j].F;
				p1=max(p1,j+1);
				p2=max(p2,j+1);
				while(p1<v.size())
				{
					if(v[p1].F>h1)	break;
					p1++;
				}
				while(p2<v.size())
				{
					if(v[p2].F>=2*h+h1)	break;
					p2++;
				}
				ll ways=1;
				if(j==i)
				{
					ways=v[i].S*(v[i].S-1);
					ways=ways*(v[i].S-2)/6;
				}
				else
				{
					ways=v[i].S*(v[i].S-1)/2;
					ways=ways*v[j].S;
				}

				if(i<p1 || i>=p2)
					ways=ways*(prefix[p2-1]-prefix[p1-1]);
				else if(v[i].S>1)
				{
					ways/=(v[i].S*(v[i].S-1)/2);
					ways=ways*((1ll*v[i].S*(v[i].S-1)*(v[i].S-2))/6 + 1ll*(v[i].S*(v[i].S-1)/2)*(prefix[p2-1]-prefix[p1-1]-v[i].S));
				}
				ans += ways;
				// cout<<i<<' '<<j<<' '<<p1<<' '<<p2<<' '<<ways<<'\n';
			}
		}
		printf("Case #%d: %lld\n",tt,ans);
	}
}