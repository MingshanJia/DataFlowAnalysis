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
	int main()
	{

		int T;
		cin>>T;
		for(int t=1;t<=T;t++)
		{
			ll ans=0;
			int n,i,j;
			cin>>n;
			string s;
			cin>>s;
			int ar[n+1],sum[n+1];
			sum[0]=0;
			for(i=1;i<=n;++i)
			{
				ar[i]=s[i-1]-'0';
				sum[i]=sum[i-1]+ar[i];
			}

			int l=1,r=n*9,mid,pos;
			while(l<=r)
			{
				mid=(l+r)/2;
				//cout<<mid<<endl;
				for(i=1;i<=n;++i)
				{
					pos=lower_bound(sum+1,sum+n+1,sum[i-1]+mid)-sum;
					//cout<<i<<" "<<sum[i-1]<<" "<<sum[i-1]+mid<<" "<<pos-i+1<<" "<<n-pos+1<<" "<<i<<endl;
					if(pos>n)
						continue;
					if(i==1)
					{
						if(n-pos+1>=pos)
							break;
					}
					else if(pos==n)
					{
						if(n-i+1<=i)
							break;
					}
					else
					{
						if(pos-i+1<=n-pos+i)
							break;
					}
				}
				if(i==n+1)
				{
					r=mid-1;
				}
				else
				{
					ans=mid;
					l=mid+1;
				}
			}

			cout<<"Case #"<<t<<": "<<ans<<endl;
		}

		return 0;
	}
