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
	#define mod 1000000007
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
			return (power(a,b-1)*a)%mod;
		ll q = power(a,b/2);
		return (q*q)%mod;
	}

	ll fact[200001],inv[200001];

	void init()
	{
		fact[0]=1;
		inv[0]=1;
		for(int i=1;i<=200000;++i)
		{
			fact[i]=(fact[i-1]*i)%mod;
			inv[i]=power(fact[i],mod-2);
		}
	}

	ll ncr(int n,int r)
	{
		return ((fact[n]*inv[r])%mod*inv[n-r])%mod;
	}

	int main()
	{

		int T;
		init();
		cin>>T;
		for(int t=1;t<=T;t++)
		{
			ll ans=0;
			int n,m,i,j;
			cin>>n>>m;

			ans=fact[2*n];
			int flag=-1;
			//cout<<ans<<endl;
			for(i=1;i<=m;++i,flag=flag*-1)
			{
				//cout<<m<<" "<<i<<" "<<ncr(m,i)<<" "<<power(2,i)<<" "<<2*n-2*i+i<<endl;
				ans=(ans+flag*(((ncr(m,i)*power(2,i)%mod)*fact[2*n-2*i+i])%mod)+mod)%mod;
			}


			cout<<"Case #"<<t<<": "<<ans<<endl;
		}

		return 0;
	}
