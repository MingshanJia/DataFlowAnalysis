	//For higher stack size use g++ -O2 -std=c++11 -Wall -Wl,--stack=268435456 a.cpp -o a.exe in cmd
	#include <bits/stdc++.h>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstring>
	#include <chrono>
	#include <complex>
	#define ll long long int
	#define ld long double
	#define vi vector<int>
	#define vll vector<ll>
	#define vvi vector < vi >
	#define pii pair<int,int>
	#define pll pair<long long, long long>
	#define mod 1e18
	#define inf 1000000000000000001;
	#define all(c) c.begin(),c.end()
	#define mp(x,y) make_pair(x,y)
	#define mem(a,val) memset(a,val,sizeof(a))
	#define eb emplace_back
	#define pb push_back
	#define f first
	#define s second
	
	using namespace std;


	ll power(ll a, ll b)	//a is base, b is exponent
	{
		if(b==0)
			return 1;
		if(b==1)
			return a;
		if(b%2 == 1)
			return (power(a,b-1)*a);
		ll q = power(a,b/2);
		return (q*q);
	}


	bool comp(string s,string s2)
	{
		return s.size()<s2.size();
	}


	int main()
	{

		int T;
		cin>>T;
		for(int t=1;t<=T;t++)
		{
			ll ans=0;
			int n,i,j,p;
			cin>>n>>p;
			string ar[p+1];
			for(i=1;i<=p;++i)
			{
				cin>>ar[i];
			}
			sort(ar+1,ar+p+1,comp);
			int flag[p+1];
			mem(flag,1);
			for(i=1;i<=p;++i)
			{
				for(j=i+1;j<=p;++j)
				{
					if(ar[j].substr(0,ar[i].length())==ar[i])
					{
						flag[j]=0;
					}
				}
			}
			ans=power(2,n);
			for(i=1;i<=p;++i)
			{
				if(ar[i].length()>n || flag[i]==0)
					continue;
				ans=(ans-power(2,n-ar[i].length()));
			}
			cout<<"Case #"<<t<<": "<<ans<<endl;
		}

		return 0;
	}
